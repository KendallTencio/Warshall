#include "hilo.h"
#include <pthread.h>

Hilo::Hilo()
{

}

void* Hilo::AlgunaFuncion(void* data) {
// Aqui realizas algún proceso,
return NULL;
}

void* Hilo::OtraFuncion(void* data) {
// Otro proceso
return NULL;
}
/*
int main(void) {
    pthread_t thread1, thread2;

// Se inician los hilos
 el primer argumento de pthread_create es un apuntador a una
variable tipo pthread_t, el segundo argumento son parametros del
hilo, como por ejemplo la prioridad, direccion de la pila, entre otros,
el tercer argumento es un apuntador a la funcion del hilo, el cuarto
es un apuntador tipo void* que seran los argumentos que le quieres
pasar a la funcion del hilo y que seran asignados al parametro data,
en este caso pasamos NULL

    pthread_create(&thread1, NULL, AlgunaFuncion, NULL);
    pthread_create(&thread2, NULL, OtraFuncion, NULL);


// Estas instrucciones son para esperar a que la ejecucion de cada hilo finalice
// sin embargo puedes destruir (si asi lo necesitas) el hilo, en este caso
// esperamos a que finalice
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
*/
