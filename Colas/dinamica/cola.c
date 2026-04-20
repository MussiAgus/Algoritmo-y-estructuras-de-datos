#include <stdlib.h>
#include <string.h>
#include "cola.h"

void crearCola(t_cola *cola){
    cola->primero = cola->ultimo = NULL;
}

void vaciarCola(t_cola *cola){
    while(cola->primero){
        t_nodo *eliminar = cola->primero;
        cola->primero = eliminar->sig;
        free(eliminar->info);
        free(eliminar);
    }
    cola->ultimo = NULL;
}

int ponerEnCola(t_cola *cola, const void *dato, size_t tamDato){
    t_nodo *nuevo = (t_nodo*) malloc(sizeof(t_nodo));

    if(!nuevo)
        return SIN_MEMORIA;

    nuevo->info = malloc(tamDato);
    if(!nuevo->info){
        free(nuevo);
        return SIN_MEMORIA;
    }

    nuevo->tamInfo = tamDato;
    memcpy(nuevo->info,dato,tamDato);
    nuevo->sig=NULL;

    if(!cola->ultimo){
        cola->primero = nuevo;
    }else{
        cola->ultimo->sig = nuevo;
    }
    cola->ultimo = nuevo;
    return TODO_BIEN;
}

int sacarDeCola(t_cola *cola, void *dato, size_t tamDato){

    t_nodo *eliminar = cola->primero;
    if(!eliminar) // ! cola->primero
        return COLA_VACIA;

    memcpy( dato, eliminar->info, MIN(eliminar->tamInfo, tamDato));
    cola->primero = eliminar->sig;

    if(!cola->primero)
        cola->ultimo = NULL;

    free(eliminar->info);
    free(eliminar);
    return TODO_BIEN;
}

int verPrimeroCola(const t_cola *cola, void *dato, size_t tamDato){
    if(!cola->primero)
        return COLA_VACIA;

    memcpy(dato, cola->primero->info, MIN(cola->primero->tamInfo, tamDato));
    return TODO_BIEN;
}

int colaLlena(t_cola *cola, size_t tamDato){
    void *nodo = malloc (sizeof(t_nodo));
    void *informacion = malloc(tamDato);

    free(nodo);
    free(informacion);

    return !nodo || !informacion;
}

int colaVacia(const t_cola *cola){
    return !cola->primero;
}












