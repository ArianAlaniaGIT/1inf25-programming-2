

/* Nombre: Arian Alfonso Alania Novoa */
/* Código: 20221762 */
/* Laboratorio 3: Punteros Genéricos */

/* Programación 2 - 2025-2 */

#include "Bibliotecas/PunterosGenericos.h"

int main(int argc, char**argv) {

    void *streamers, *comentarios;

    cargastreamers(streamers);
    cargacomentarios(comentarios);
    actualizacomentarios(streamers,comentarios);
    imprimestreamers(streamers);


    return 0;
}