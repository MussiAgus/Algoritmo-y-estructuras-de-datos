#include <stdlib.h>
#include <string.h>
#include "pila.h"

void crearPila(t_pila* pila){
    pila->tope=TAM_MAX;
}

void eliminarPila(t_pila* pila){
    pila->tope=TAM_MAX;
}

int ponerEnPila(t_pila *pila, const void *dato, size_t tamDato){
    if(pila->tope < (tamDato + sizeof(size_t) ) )
        return SIN_MEM;

    pila->tope -=tamDato;
    memcpy(pila->pila+pila->tope, dato, tamDato);
    pila->tope-= sizeof(size_t);
    memcpy(pila->pila+pila->tope, &tamDato, sizeof(size_t));
}
