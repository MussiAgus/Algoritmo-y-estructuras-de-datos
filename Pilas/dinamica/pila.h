#ifndef PILAS_H
#define PILAS_H

#define TAM 300

typedef struct sNodo{
    void *info;
    size_t tamInfo;
    struct sNodo *sig;
}t_nodo;

typedef t_nodo * t_pila;

#endif // PILAS_H
