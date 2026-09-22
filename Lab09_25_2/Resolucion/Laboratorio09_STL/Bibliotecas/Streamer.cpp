//
// Created by arian on 10/01/2026.
//

#include "Streamer.h"

Streamer::Streamer()
{
    canal = "";
    fecha = 0;
    etiquetasStr = "";
    idioma = "";
}

string Streamer::get_canal() const
{
    return canal;
}

void Streamer::set_canal(const string& canal)
{
    this->canal = canal;
}

int Streamer::get_fecha() const
{
    return fecha;
}

void Streamer::set_fecha(int fecha)
{
    this->fecha = fecha;
}

string Streamer::get_etiquetas_str() const
{
    return etiquetasStr;
}

void Streamer::set_etiquetas_str(const string& etiquetas_str)
{
    etiquetasStr = etiquetas_str;
}

string Streamer::get_idioma() const
{
    return idioma;
}

void Streamer::set_idioma(const string& idioma)
{
    this->idioma = idioma;
}

Streamer::~Streamer() {
    // String gesta su propia memoria, por lo tanto, no hace falta hacer delete
}

void Streamer::guardarCategoria(string &cat) {
    categoria.set_codigo(cat);
}

string Streamer::obtenerCategoria() const {
    string cat = categoria.get_codigo();
    return cat;
}

void operator>>(ifstream &arch, Streamer &streamer) {
    int dia, mes, anho, fecha;
    char cadena[200], c;
    arch.getline(cadena,200,',');
    if (arch.eof())return;
    string guardado;
    guardado = cadena;
    streamer.set_canal(guardado);
    arch>>dia>>c>>mes>>c>>anho;
    arch.get();
    streamer.set_fecha(anho*10000 + mes*100 + dia);
    arch.getline(cadena,200,','); // codigo
    guardado = cadena;
    streamer.guardarCategoria(guardado);
    arch.getline(cadena,200,',');
    guardado = cadena;
    streamer.set_etiquetas_str(guardado);
    arch.getline(cadena,200,'\n');
    guardado = cadena;
    streamer.set_idioma(guardado);
}


bool Streamer::operator<(const Streamer &str2) {
    int fecha1 = get_fecha();
    int fecha2 = str2.get_fecha();
    string cat1 = obtenerCategoria();
    string cat2 = str2.obtenerCategoria();

    bool comparador1 = cat1 < cat2;
    bool comparador2 = cat1 == cat2 and fecha1 < fecha2;
    return comparador1 || comparador2;
}

void Streamer::llenarDatosCategoria(string nomb, string desc)
{
    categoria.set_nombre(nomb);
    categoria.set_descripcion(desc);
}

void Streamer::sumarComentario(string comen) {
    comentarios.push_back(comen);
}

void Streamer::llenarEtiqueta(Etiqueta etiq) {
    etiquetasVector.push_back(etiq);
}

void Streamer::imprimirCategoria(ofstream &arch) {
    arch<<categoria;
}

void Streamer::imprimirEtiquetas(ofstream &arch) {
    vector<Etiqueta>::iterator it; int i = 1;
    for (it = etiquetasVector.begin(); it != etiquetasVector.end(); it++) {
        arch<<setw(4)<<i<<") ";
        arch<<*it;
        i++;
    }
}


void Streamer::imprimirComentarios(ofstream &arch) {
    vector<string>::iterator it; int i = 1;
    for (it = comentarios.begin(); it != comentarios.end(); it++){
        arch<<setw(4)<<i<<") ";
        arch<<*it<<endl;
        i++;
    }
}
void operator<<(ofstream &arch, Streamer &streamer) {
    arch<<"CANAL:    "<<streamer.get_canal()<<endl;
    int dia,mes,anho;
    anho = streamer.get_fecha()/10000;
    mes = (streamer.get_fecha()%10000)/100;
    dia = (streamer.get_fecha()%10000)%100;
    arch<<"FECHA:    "<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes
    <<'/'<<setw(4)<<anho<<setfill(' ')<<endl;
    arch<<"LENGUAJE: "<<streamer.get_idioma()<<endl;
    streamer.imprimirCategoria(arch);
    arch<<"ETIQUETAS STR: "<<streamer.get_etiquetas_str()<<endl;
    arch<<"ETIQUETAS: "<<endl;
    streamer.imprimirEtiquetas(arch);
    arch<<"COMENTARIOS: "<<endl;
    streamer.imprimirComentarios(arch);
}