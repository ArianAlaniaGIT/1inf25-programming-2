#include <cstring>
#include <iostream>
#include <fstream>
#include "GestorCanales.h"
#include "Comunes.h"

using namespace std;

int GestorCanales::get_cantidad_categorias() const {
    return cantidad_categorias;
}

void GestorCanales::set_cantidad_categorias(int cantidad_categorias) {
    this->cantidad_categorias = cantidad_categorias;
}

int GestorCanales::get_cantidad_etiquetas() const {
    return cantidad_etiquetas;
}

void GestorCanales::set_cantidad_etiquetas(int cantidad_etiquetas) {
    this->cantidad_etiquetas = cantidad_etiquetas;
}

int GestorCanales::get_cantidad_canales() const {
    return cantidad_canales;
}

void GestorCanales::set_cantidad_canales(int cantidad_canales) {
    this->cantidad_canales = cantidad_canales;
}

GestorCanales::GestorCanales() {
    this->cantidad_categorias = 0;
    this->cantidad_etiquetas = 0;
    this->cantidad_canales = 0;
    this->cargar_categorias();
    this->cargar_etiquetas();
    this->cargar_canales();
}

void GestorCanales::operator!() {
    for (int i = 0; i < this->cantidad_canales; i++) {
        Canal canal = this->vector_canales[i];
        char *codigo = canal.get_categoria();
        char *nombre = this->buscar_nombre_categoria(codigo);
        canal.set_categoria(nombre);
        this->vector_canales[i] = canal;
        liberar_cadena(codigo);
        liberar_cadena(nombre);
    }
}

char *GestorCanales::buscar_nombre_categoria(char *codigo) const {
    for (int i = 0; i < this->cantidad_categorias; i++) {
        char buffCod[7];
        vector_categorias[i].get_codigo(buffCod);
        if (strcmp(codigo,buffCod)==0) {
            return vector_categorias[i].get_nombre();
        }
    }
    return nullptr;
}

char *GestorCanales::buscar_nombre_etiqueta(char *codigo) const {
    for (int i = 0; i < this->cantidad_etiquetas; i++) {
        char buffCod[10]{};
        vector_etiquetas[i].get_codigo(buffCod);
        if (strcmp(codigo,buffCod)==0) {
            return vector_etiquetas[i].get_nombre();
        }
    }
    return nullptr;
}

void GestorCanales::operator*() {
    for (int i = 0; i < this->cantidad_canales; i++) {
        Canal canal = this->vector_canales[i];
        char *etiquetas = canal.get_etiquetas();
        char etiquetas_buffer[30];
        strcpy(etiquetas_buffer, etiquetas);

        char *token = strtok(etiquetas, "-");
        while (token != nullptr) {
            char *etiqueta = this->buscar_nombre_etiqueta(token);
            canal.agregar_etiqueta(etiqueta);
            token = strtok(nullptr, "-");
        }
        this->vector_canales[i] = canal;
        liberar_cadena(etiquetas);
    }
}

void GestorCanales::cargar_categorias() {
    ifstream archivo_de_categorias;
    archivo_de_categorias.open(NOMBRE_CSV_CATEGORIA, ios::in);
    if (not archivo_de_categorias.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_CATEGORIA << endl;
        exit(10);
    }

    this->cantidad_categorias = 0;
    Categoria categoria;
    while (archivo_de_categorias >> categoria) {
        this->cantidad_categorias++;
        this->vector_categorias[this->cantidad_categorias - 1] = categoria;
    }
    archivo_de_categorias.close();
}

void GestorCanales::cargar_etiquetas() {
    ifstream archivo_de_etiquetas;
    archivo_de_etiquetas.open(NOMBRE_CSV_ETIQUETA, ios::in);
    if (not archivo_de_etiquetas.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_ETIQUETA << endl;
        exit(10);
    }

    this->cantidad_etiquetas = 0;
    Etiqueta etiqueta;
    while (archivo_de_etiquetas >> etiqueta) {
        this->cantidad_etiquetas++;
        this->vector_etiquetas[this->cantidad_etiquetas - 1] = etiqueta;
    }
    archivo_de_etiquetas.close();
}

void GestorCanales::cargar_canales() {
    ifstream archivo_de_canales;
    archivo_de_canales.open(NOMBRE_CSV_CANAL, ios::in);
    if (not archivo_de_canales.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << NOMBRE_CSV_ETIQUETA << endl;
        exit(10);
    }

    this->cantidad_canales = 0;
    bool acabo_lectura = false;
    do {
        Canal canal = this->lee_canal(archivo_de_canales);
        if (canal.get_seguidores() == CANAL_NO_LEIDO)
            acabo_lectura = true;
        else {
            this->cantidad_canales++;
            this->vector_canales[this->cantidad_canales - 1] = canal;
        }
    } while (not acabo_lectura);
    archivo_de_canales.close();
}

Canal GestorCanales::lee_canal(istream &archivo_de_canales) {
    char nombre_buffer[30];
    int seguidores_buffer;
    char categoria_buffer[7];
    char etiquetas_buffer[30];

    Canal canal_local;
    archivo_de_canales.getline(nombre_buffer, 30, ',');
    if (archivo_de_canales.eof())
        return canal_local;
    archivo_de_canales >> seguidores_buffer;
    archivo_de_canales.get();;
    archivo_de_canales.getline(categoria_buffer, 7, ',');
    archivo_de_canales.getline(etiquetas_buffer, 30, '\n');

    canal_local.set_nombre(nombre_buffer);
    canal_local.set_categoria(categoria_buffer);
    canal_local.set_etiquetas(etiquetas_buffer);
    canal_local.set_seguidores(seguidores_buffer);
    return canal_local;
}

ostream &GestorCanales::lista_categorias(ostream &out) {
    out << "Lista de categorias:" << endl;
    for (int i = 0; i < this->cantidad_categorias; i++) {
        out << this->vector_categorias[i] << endl;
    }
    return out;
}

ostream &GestorCanales::lista_etiquetas(ostream &out) {
    out << "Lista de etiquetas:" << endl;
    for (int i = 0; i < this->cantidad_etiquetas; i++) {
        out << this->vector_etiquetas[i] << endl;
    }
    return out;
}

ostream &GestorCanales::lista_canales(ostream &out) {
    out << "Lista de canales:" << endl;
    for (int i = 0; i < this->cantidad_canales; i++) {
        out << this->vector_canales[i] << endl;
    }
    return out;
}

//para usar con el quicksort
int ascendente(const void *a, const void *b) {
    // Canal canalA = *(Canal *) a;
    // Canal canalB = *(Canal *) b;
    // if (canalA.get_seguidores() < canalB.get_seguidores()) return -1;
    // if (canalA.get_seguidores() > canalB.get_seguidores()) return 1;
   return 0;
}

//para usar con el quicksort
int descendente(const void *a, const void *b) {
    // Canal canalA = *(Canal *) a;
    // Canal canalB = *(Canal *) b;
    // if (canalA.get_seguidores() > canalB.get_seguidores()) return -1;
    // if (canalA.get_seguidores() < canalB.get_seguidores()) return 1;
    return 0;
}

const Canal *GestorCanales::get_vector_canales() const {
    return vector_canales;
}

ostream &operator<<(ostream &out, GestorCanales &gestor) {
    // Variable estática para alternar el orden entre llamadas (true = ascendente, false = descendente)
    static bool orden_ascendente = true;

    // 1. Crear una copia local del arreglo de canales para preservar el original
    int total = gestor.get_cantidad_canales(); // O el atributo correspondiente según tu diseño
    Canal *copia_canales = new Canal[total];
    for (int i = 0; i < total; i++) {
        copia_canales[i] = gestor.get_vector_canales()[i]; // O asignación directa si tienes acceso
    }

    // 2. Aplicar qsort usando la función de comparación respectiva
    if (orden_ascendente) {
        qsort(copia_canales, total, sizeof(Canal), ascendente);
    } else {
        qsort(copia_canales, total, sizeof(Canal), descendente);
    }

    // 3. Imprimir los diez primeros canales (o menos si hay menos de 10)
    out << endl<<"Listado de canales (" << (orden_ascendente ? "Ascendente" : "Descendente") << "):\n";
    int limite = (total < 10) ? total : 10;
    for (int i = 0; i < limite; i++) {
        out << (i + 1) << " -> " << copia_canales[i] << endl;
    }

    // 4. Alternar el indicador para la siguiente ejecución
    orden_ascendente = !orden_ascendente;

    // 5. Liberar la memoria dinámica de la copia local para evitar memory leaks
    delete[] copia_canales;

    return out;
}