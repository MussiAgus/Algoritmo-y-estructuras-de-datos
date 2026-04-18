#include <stdlib.h>
#include <string.h>
#include "pila.h"


void crearPila(t_pila *pila){
    *pila =NULL;
}

void eliminarPila(t_pila *pila){
    while(*pila){
        t_nodo *aux = *pila;
        *pila = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int ponerEnPila(t_pila *pila, const void *dato, size_t tamDato){
    t_nodo *nuevo;

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return SIN_MEM;

    nuevo->info = malloc(tamDato);
    if(!nuevo->info){
        free(nuevo);
        return SIN_MEM;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = *pila;
    *pila = nuevo;
    return TODO_BIEN;
}

int sacarDePila(t_pila *pila, void *dato, size_t tamDato){
    t_nodo *aux = *pila;

    if(aux==NULL){
        //Quiere decir que ya no hay ningun elemento para sacar.
        return 0;
    }

    *pila = aux->sig;
    memcpy(dato, aux->info, MIN(tamDato, aux->tamInfo));
    free(aux->info);
    free(aux);
    return TODO_BIEN;
}

int verTopeDePila(const t_pila *pila, void *dato, size_t tamDato){
    if(*pila == NULL){
        return PILA_VACIA;
    }

    memcpy(dato, (*pila)->info, MIN(tamDato, (*pila)->tamInfo));
    return TODO_BIEN;
}

//Esto de aca, se puede porque free solo libera la memoria, pero no anula el puntero que estabamos usando.
//Por lo tanto, si malloc funciono bien al principio, el puntero sera != NULL.
int pilaLlena(const t_pila *pila, size_t tamDato){
    t_nodo *aux = (t_nodo*)malloc(sizeof(t_nodo));
    void *info = malloc(tamDato);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int pilaVacia(const t_pila *pila){
    return *pila == NULL;
}




