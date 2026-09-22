//
// Created by arian on 10/01/2026.
//

#include "SistemaDeGestion.h"

void SistemaDeGestion::cargarCategorias(const char* nombArch)
{
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo de categorias."<<endl;
        exit(1);
    }

    class Categoria categoria;
    while (true) {
        arch>>categoria;
        if (arch.eof())break;
        categorias.push_back(categoria);
    }
    categorias.sort();
}

void SistemaDeGestion::cargarEtiquetas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Se ha producido un inconveniente al cargar las etiquetas."<<endl;
        exit(1);
    }

    class Etiqueta etiqueta;
    while (true) {
        arch>>etiqueta;
        if (arch.eof())break;
        string cod;
        cod = etiqueta.get_codigo();
        etiquetas[cod] = etiqueta;
    }
}

void SistemaDeGestion::cargaStreamers(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Se ha producido un inconveniente al cargar los streamers."<<endl;
        exit(1);
    }
    class Streamer streamer;
    while (true) {
        arch>>streamer;
        if (arch.eof())break;

        streamers.push_back(streamer);
    }
    streamers.sort();
}

void SistemaDeGestion::cargaComentarios(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Se ha producido un inconveniente al cargar las comentarios."<<endl;
        exit(1);
    }
    class Comentario comentario;
    while (true) {
        arch>>comentario;
        if (arch.eof())break;

        comentarios.push_back(comentario);
    }
    comentarios.sort();
}

void SistemaDeGestion::completarCategoriaPorStreamer() {
    list<Streamer>::iterator it;
    for (it = streamers.begin(); it != streamers.end(); ++it) {
        string catStr = it->obtenerCategoria();
        list<Categoria>::iterator itCat;
        for (itCat = categorias.begin(); itCat != categorias.end(); ++itCat) {
            if (itCat->get_codigo() == catStr) {
                string nombre,descripcion;
                nombre = itCat->get_nombre();
                descripcion = itCat->get_descripcion();
                it->llenarDatosCategoria(nombre,descripcion);
                break;
            }
        }
    }
}

void SistemaDeGestion::completarStreamers() {
    // Completar Categorias
    completarCategoriaPorStreamer();

    // Cargar Comentarios
    completarComentariosPorStreamer();

    // Cargar Etiquetas
    completarEtiquetasPorStreamer();
}

void SistemaDeGestion::completarEtiquetasPorStreamer() {
    list <Streamer>::iterator it;
    for (it = streamers.begin(); it != streamers.end(); ++it) {
        char *cadena = new char[100]{}; int i = 0;
        string cadenaDeEtiquetas = it->get_etiquetas_str();
        for (char c : cadenaDeEtiquetas) {
            if (c == '-') {
                string cadStr = cadena;
                buscarEtiqueta(cadStr,it);
                delete []cadena;
                cadena = new char[100]{}; i=0;
            } else {
                cadena[i] = c; i++;
            }
        }
        if (cadena != nullptr){
            string cadStr = cadena;
            buscarEtiqueta(cadStr,it);
            delete []cadena;
        }
    }
}

void SistemaDeGestion::buscarEtiqueta(string cadStr,list<Streamer>::iterator &it) {
    map<string,Etiqueta>::iterator itEt;
    for (itEt = etiquetas.begin(); itEt != etiquetas.end(); itEt++) {
        if (cadStr == itEt->first){
            Etiqueta etiq = itEt->second;
            it->llenarEtiqueta(etiq);
            break;
        }
    }
}

void SistemaDeGestion::completarComentariosPorStreamer() {

    list <Streamer>::iterator it;
    for (it = streamers.begin(); it != streamers.end(); ++it) {
        list<Comentario>::iterator itCom;
        for (itCom = comentarios.begin(); itCom != comentarios.end(); ++itCom) {
            string canal = itCom->get_canal();
            if (canal == it->get_canal()) {
                string comentario = itCom->get_comentario();
                it->sumarComentario(comentario);

            }
        }
    }
}

void SistemaDeGestion::reporteDeStreamers(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo generar el reporte."<<endl;
        exit(1);
    }
    elaborarLinea(arch,120,'=');
    arch<<setw(70)<<"RELACION DE STREAMERS"<<endl;
    list<Streamer>::iterator it;
    for (it = streamers.begin(); it != streamers.end(); ++it) {
        elaborarLinea(arch,120,'-');
        arch<<*it;
    }
    elaborarLinea(arch,120,'=');
}

void SistemaDeGestion::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i ++) {
        arch<<c;
    }
    arch<<endl;
}

void SistemaDeGestion::eliminaStreamers(string idioma) {
    list<Streamer>::iterator it;
    for (it = streamers.begin(); it != streamers.end();)
    {
        string idiomaVictimizado= it->get_idioma();
        if (idioma == idiomaVictimizado) {
            it = streamers.erase(it);
        } else {
            it++;
        }
    }
}