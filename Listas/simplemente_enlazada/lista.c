#include "lista.h"

void crearLista(t_lista *lista){
    *lista = NULL;
}
void vaciarLista(t_lista *lista){
    while(*lista){
        t_nodo *aux = *lista;
        *lista = aux->siguiente;
        free(aux->info);
        free(aux);
    }
}

int listaVacia(const t_lista *lista){
    return *lista==NULL;
}
int listaLlena(const t_lista *lista, size_t tamDato){

    t_nodo *aux = (t_nodo*)malloc(sizeof(t_nodo));
    void *info = malloc(tamDato);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int insertarElementoComienzo(t_lista *lista, const void *dato, size_t tamDato){

    t_nodo *nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return SIN_MEM;

    nuevo->info = malloc(tamDato);
    if(nuevo->info == NULL){
        free(nuevo);
        return SIN_MEM;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->siguiente = *lista;
    *lista = nuevo;
    return TODO_BIEN;
}
int insertarElementoFinal(t_lista *lista, const void *dato, size_t tamDato){

    t_nodo *nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return SIN_MEM;

    nuevo->info = malloc(tamDato);
    if(nuevo->info == NULL){
        free(nuevo);
        return SIN_MEM;
    }

    while(*lista){
        lista = &(*lista)->siguiente;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->siguiente = NULL;
    *lista = nuevo;
    return TODO_BIEN;
}

int sacarPrimerElemento(t_lista *lista, void *dato, size_t tamDato){
    t_nodo *aux = *lista;

    if(aux==NULL)
        return 0;

    *lista = aux->siguiente;
    memcpy(dato, aux->info, MIN(tamDato, aux->tamInfo));
    free(aux->info);
    free(aux);
    return TODO_BIEN;
}
int sacarUltimoElemento(t_lista *lista, void *dato, size_t tamDato){

    if(*lista==NULL)
        return 0;

    while(*lista){
        lista = &(*lista)->siguiente;
    }
    memcpy(dato, (*lista)->info, MIN(tamDato,(*lista)->tamInfo));
    free( (*lista)->info );
    free(*lista);
    return TODO_BIEN;
}

int verPrimerElemento(const t_lista *lista, void *dato, size_t tamDato){
    if(*lista==NULL)
        return 0;

    memcpy(dato, (*lista)->info, MIN(tamDato, (*lista)->tamInfo));
    return TODO_BIEN;
}
int verUltimoElemento(const t_lista *lista, void *dato, size_t tamDato){
    if(*lista == NULL)
        return 0;

    while((*lista)->siguiente){
        lista = &(*lista)->siguiente;
    }
    memcpy(dato, (*lista)->info, MIN(tamDato, (*lista)->tamInfo));
    return TODO_BIEN;
}
