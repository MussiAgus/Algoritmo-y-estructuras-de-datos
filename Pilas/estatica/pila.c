#include <stdlib.h>
#include <string.h>
#include "pila.h"

void crearPila(t_pila* pila){
    pila->tope=TAM_MAX;
}

void eliminarPila(t_pila* pila){
    pila->tope=TAM_MAX;
}

int pilaLlena(const t_pila *pila, size_t tamDato){
    return pila->tope < (tamDato+sizeof(size_t));
}

int pilaVacia(t_pila *pila){
    return pila->tope == TAM_MAX;
}

int ponerEnPila(t_pila *pila, const void *dato, size_t tamDato){
    if(pila->tope < (tamDato + sizeof(size_t) ) )
        return SIN_MEM;

    pila->tope -=tamDato;
    memcpy(pila->pila+pila->tope, dato, tamDato);
    pila->tope-= sizeof(size_t);
    memcpy(pila->pila+pila->tope, &tamDato, sizeof(size_t));
    return TODO_BIEN;
}

int sacarDePila(t_pila *pila, void *dato, size_t tamDato){

    size_t tamDatoPila;

    if(pila->tope == TAM_MAX)
        return PILA_VACIA;

    memcpy(&tamDatoPila, pila->pila+pila->tope,sizeof(size_t));
    pila->tope+=sizeof(size_t);

    memcpy(dato, pila->pila+pila->tope, MIN(tamDato,tamDatoPila));
    pila->tope+=tamDatoPila;

    return TODO_BIEN;
}

int verTopeDePila(const t_Pila *pila, void *d, size_t tamDato)
{
    size_t tamDatoPila;
    if(p->tope == TAM)
        return PILA_VACIA;

    memcpy(&tamDatoPila, p->pila + p->tope, sizeof(size_t));
    memcpy(d, p->pila + p->tope + sizeof(size_t), MIN(tamDato,tamDatoPila));

    return TODO_BIEN;
}


