#ifndef PILA_H
#define PILA_H

#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define TAM_MAX 50
#define TODO_BIEN 1
#define SIN_MEM 0
#define PILA_VACIA 0

typedef struct{
    size_t tope;
    char pila[TAM_MAX];
}t_pila;


void crearPila(t_pila*);
void eliminarPila(t_pila*);

int ponerEnPila(t_pila*, const void*, size_t); //Apilar
int sacarDePila(t_pila*, void*, size_t); //Desapilar

int verTope(const t_pila*, void*, size_t);

int pilaLlena(const t_pila*, size_t);
int pilaVacia(const t_pila*);

#endif // PILA_H
