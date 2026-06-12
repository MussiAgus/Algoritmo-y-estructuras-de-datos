#ifndef ARBOL_H
#include <stdlib.h>

typedef struct snode{

    void *info;
    size_t tamInfo;
    snode *izq, *der;

}t_nodoArbol;

typedef t_nodoArbol *t_arbol;




#endif // ARBOL_H


