#include "Bibliotecas/PunterosGenericos.h"

int main(int argc, char**argv) {

    void *streamers, *comentarios;

    cargastreamers(streamers);
    cargacomentarios(comentarios);
    actualizacomentarios(streamers,comentarios);
    imprimestreamers(streamers);


    return 0;
}
