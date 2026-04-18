#ifndef PILAS_H
#define PILAS_H

#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define TAM_MAX 50
#define TODO_BIEN 1
#define SIN_MEM 0
#define PILA_VACIA 0

typedef struct sNodo{
    void *info;
    size_t tamInfo;
    struct sNodo *sig;
}t_nodo;

typedef t_nodo * t_pila;

void crearPila(t_pila*);
void eliminarPila(t_pila*);

int ponerEnPila(t_pila*, const void*, size_t); //Apilar
int sacarDePila(t_pila*, void*, size_t); //Desapilar

int verTopeDePila(const t_pila*, void*, size_t);

int pilaLlena(const t_pila*, size_t);
int pilaVacia(const t_pila*);

#endif // PILAS_H
