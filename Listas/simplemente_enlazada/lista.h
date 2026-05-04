#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <string.h>

#define SIN_MEM 1
#define CLA_DUP 2
#define TODO_BIEN 3

#define MIN(a,b) ( (a)<=(b)? (a): (b))

typedef struct sNode{
    void *info;
    size_t tamInfo;
    struct sNode *siguiente;
} t_nodo;

typedef t_nodo *t_lista;

void crearLista(t_lista*);
void vaciarLista(t_lista*);

int listaVacia(const t_lista*);
int listaLlena(const t_lista*, size_t);

int insertarElementoComienzo(t_lista*, const void*, size_t);
int insertarElementoFinal(t_lista*, const void*, size_t);

int sacarPrimerElemento(t_lista*, void*, size_t);
int sacarUltimoElemento(t_lista*, void*, size_t);

int verPrimerElemento(const t_lista*, void*, size_t);
int verUltimoElemento(const t_lista*, void*, size_t);



#endif // LISTA_H
