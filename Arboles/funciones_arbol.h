#ifndef ARBOL_H
#include <stdlib.h>

#define SIN_MEM 0
#define CLA_DUP 0 //CLAVE DUPLICADA
#define TODO_BIEN 1
#define SIN_COINDICENCIA 0
#define SIN_DIRECCION NULL



typedef struct snode{
    void *info;
    size_t tamInfo;
    snode *izq, *der;
}t_nodo;

typedef t_nodo *t_arbol;

int crearArbolBinarioBusqueda(t_arbol*);

int insertarNodoArbol(t_arbol*, void*, size_t, int(*cmp)(void*,void*));

int buscarNodoDevolverContenido(t_arbol*, void*, size_t, int(*cmp)(void*,void*));

#endif // ARBOL_H


