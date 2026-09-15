//
// Created by alulab14 on 19/09/2025.
//

#include "PunterosGenericos.h"

#define INCREMENTO 5


void cargastreamers(void *&str) {
    ifstream arch("Archivos/streamers.csv",ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al intentar abrir el archivo de streamers."<<endl;
        exit(1);
    }
    void **streamers = nullptr, *reg;
    str = nullptr;
    int mind = 0, cap = 0; // Se usa Incrementos de 5
    while (true) {
        reg= darConLosStreamers(arch);
        if (arch.eof() or reg == nullptr) break;
        if (mind == cap) incrementarEspacios(streamers,mind,cap);
        streamers[mind-1] = reg;
        mind++;
    }
    str = streamers;
    pruebaStreamers(str);
}

void pruebaStreamers(void *str) {
    ofstream arch("Reportes/StreamersPrueba.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un percance al generar el reporte de streamers"<<endl;
        exit(1);
    }
    void **streamers = (void**)str;
    for (int i = 0; streamers[i];i++) {
        void **dato = (void**)streamers[i];
        arch<<left<<setw(20)<<(char*)dato[0]<<right<<setw(10)<<*(int*)dato[1]<<setw(7)<<" "<<(char*)dato[2]<<endl;
    }
}

void incrementarEspacios(void**&streamers, int &mind, int &cap) {
    cap += INCREMENTO;
    void **aux;
    if (streamers == nullptr) {
        streamers = new void*[cap]{};
        mind = 1;
    } else {
        aux = new void*[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = streamers[i];
        }
        delete streamers;
        streamers = aux;
    }
}


void *darConLosStreamers(ifstream &arch) {
    char *cuenta, *categoria, c;
    long long*tiempoTotal = new long long, *seguidores = new long long;
    int *promedio = new int;

    //xQcOW,6196161750,27716,3246298,QA1080
    cuenta = leerCadenaExacta(arch,100,',');
    if (arch.eof() or cuenta == nullptr) return nullptr;
    arch>>*tiempoTotal>>c>>*promedio>>c>>*seguidores;
    arch.get();
    categoria = leerCadenaExacta(arch,100,'\n');

    void **reg = new void*[4]{};
    reg[0] = cuenta;
    reg[1] = seguidores;
    reg[2] = categoria;
    reg[3] = nullptr;
    return reg;
}

char *leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof())return nullptr;
    ptCadena = new char[strlen(cadena)+1];
    strcpy(ptCadena,cadena);
    return ptCadena;

}

void cargacomentarios(void *&comen) {
    ifstream arch("Archivos/comentarios.csv",ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al intentar abrir el archivo de comentarios."<<endl;
        exit(1);
    }
    void **comentarios = nullptr, *reg;
    comen = nullptr;
    int mind = 0, cap = 0; // Se usa Incrementos
    while (true) {
        reg = darConLosComentarios(arch);
        if (arch.eof() or reg == nullptr) break;
        if (mind == cap) incrementarEspacios(comentarios,mind,cap);
        comentarios[mind-1] = reg;
        mind++;
    }
    comen = comentarios;
    pruebaComentarios(comen);
}

void pruebaComentarios(void *comen) {
    ofstream arch("Reportes/ComentariosPrueba.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un percance al generar el reporte de Comentarios."<<endl;
        exit(1);
    }
    void **comentarios =(void**)comen;

    for (int i = 0; comentarios[i];i++) {
        void **dato = (void**)comentarios[i];
        arch<<left<<setw(15)<<(char*)dato[0]<<setw(20)<<(char*)dato[1]<<setw(20)<<(char*)dato[2]<<
            setw(100)<<(char*)dato[3]<<endl;
    }
}

void *darConLosComentarios(ifstream &arch) {
    char *codigo, *emisor, *receptor, *texto;

    // Can someone please help me understand [Castro_1021 loltyler1]
    codigo = leerCadenaExacta(arch,200,',');
    if (arch.eof() or codigo == nullptr) return nullptr;
    texto = leerCadenaExacta(arch,300,'[');
    emisor = leerCadenaExacta(arch,300,' ');
    receptor = leerCadenaExacta(arch,300,']');
    arch.get();

    void **reg = new void*[4]{};
    reg[0] = codigo;
    reg[1] = emisor;
    reg[2] = receptor;
    reg[3] = texto;
    return reg;
}

void actualizacomentarios(void *&str,void *&comen) {
    void **streamers = (void**)str, **comentarios = (void**)comen;
    int numStreamers = 0;
    while (streamers[numStreamers])numStreamers++;
    int nd[numStreamers+1], cap[numStreamers+1];
    for (int i = 0; i < numStreamers;i++) {
        nd[i] = 0; cap[i] = 0;
    }
    llenarLosRestantes(comentarios, streamers,nd,cap);
    str = streamers;
    comen = comentarios;
}

void llenarLosRestantes(void **&comentarios, void **&streamers,int *nd,int *cap) {
    for (int i = 0; comentarios[i];i++) {
        void **dato = (void**)comentarios[i];
        int posStreamer = buscarStreamer(streamers, (char*)dato[1]);
        if (posStreamer != -1) {
            void **datoStr = (void**)streamers[posStreamer];
            void **arreglo = (void**)datoStr[3];

            void **dupla = new void*[2]{};
            dupla[0] = dato[2];
            dupla[1] = dato[3];

            if (nd[posStreamer] == cap[posStreamer]) incrementarEspacios(arreglo,nd[posStreamer], cap[posStreamer]);
            arreglo[nd[posStreamer]-1]= dupla;
            nd[posStreamer] += 1;
            datoStr[3] = arreglo;
            streamers[posStreamer] = datoStr;
        }
    }
}

int buscarStreamer(void **streamers, char *emisor) {
    for (int i = 0; streamers[i];i++) {
        void**dato = (void**)streamers[i];
        if (strcmp((char*)dato[0],emisor)==0) return i;
    }
    return -1;
}

void imprimestreamers(const void*str) {
    ofstream arch("Reportes/Reporte.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al generar el reporte final."<<endl;
        exit(1);
    }
    void **streamers = (void**)str;
    for (int i = 0; streamers[i];i++) {
        elaborarLinea(arch,120,'=');
        void **dato = (void**)streamers[i];
        arch<<left<<setw(20)<<"Cuenta"<<"Seguidores"<<endl;
        arch<<left<<setw(20)<<(char*)dato[0]<<right<<*(long long*)dato[1]<<endl;
        elaborarLinea(arch,120,'-');
        arch<<"Comentarios emitidos: "<<endl;
        elaborarLinea(arch,120,'-');
        arch<<left<<setw(20)<<"Receptor"<<"Texto"<<endl;
        elaborarLinea(arch,120,'-');
        imprimirComentariosStr(arch,dato[3]);
    }
    elaborarLinea(arch,115,'=');
}

void imprimirComentariosStr(ofstream &arch, void *dato) {
    void **lista = (void**)dato;

    if (lista != nullptr) {
        for (int j = 0; lista[j];j++) {
            void **dato3 = (void**)lista[j];
            arch<<setw(20)<<(char*)dato3[0]<<(char*)dato3[1]<<endl;
        }
    } else {
        arch<<"SIN COMENTARIOS"<<endl;
    }
}

void elaborarLinea(ofstream &arch,int max,char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}
