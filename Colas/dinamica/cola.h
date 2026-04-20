#ifndef COLA_H
#define COLA_H

#define SIN_MEMORIA 0
#define COLA_VACIA 0
#define TODO_BIEN 1
#define MIN(a,b) ( (a)>(b)? (a) : (b) )

typedef struct sNodo{
    void *info;
    size_t tamInfo;
    struct sNodo sig;
}t_nodo;

typedef struct{
    t_nodo *primero;
    t_nodo *ultimo;
}t_cola;

void crearCola(t_cola*);
void vaciarCola(t_cola*);

int ponerEnCola(t_cola*,void*,size_t);
int sacarDeCola(t_cola*,void*,size_t);
int verPrimeroCola(t_cola*,void*,size_t);

int colaLlena(t_cola*,size_t);
int colaVacia(t_cola*);


#endif // COLA_H
