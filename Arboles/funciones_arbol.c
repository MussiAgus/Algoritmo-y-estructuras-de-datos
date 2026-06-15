#include <stdio.h>
#include <stdlib.h>

int crearArbolBinarioBusqueda(t_arbol *p){
    *p = NULL;
    return TODO_BIEN;
}

int insertarNodoArbol(t_arbol *p, void *dato, size_t tamDato, int (*cmp)(void*, void*)){
    t_nodo *nuevo;
    int res;

    if(*p){

        res=cmp(dato,(*p)->info);
        if(res>0)
            return insertarNodoArbol(&(*p)->der,dato,tamDato,cmp);

        if(res<0)
            return insertarNodoArbol(&(*p)->izq,dato,tamDato,cmp);

        // O sea, si no es menor ni mayor, son iguales. Ya existe un elemento asi.
        return CLA_DUP;
    }

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return SIN_MEM;

    nuevo->info = malloc(tamDato);
    if(!nuevo->info){
        free(nuevo);
        return SIN_MEM;
    }
    memcpy(nuevo->info, dato, tamDato);
    nuevo->der=NULL;
    nuevo->izq=NULL;
    nuevo->tamInfo=tamDato;
    *p=nuevo;
    return TODO_BIEN;
}

// t_arbol *p recibe el resultado de t_nodo **BuscarNodoDevolverDireccion entonces esa ya es la direccion del nodo a eliminar.
int eliminarNodoArbol(t_arbol *p, void *dato, size_t tamDato, int (*cmp)(void*, void*)){

    if(!*p)
        return 0;

    t_nodo **reemplazado, *eliminado;

    reemplazado = alturaArbolBin(&(*p)->izq)>alturaArbolBin(&(*p)->der)? retornarMayorNodo(&(*p)->izq):retornarMenorNodo(&(*p)->der);




}

int buscarNodoDevolverContenido(t_arbol *p, void *dato, size_t tamDato, int (*cmp)(void*,void*)){

    if(*p){
        res=cmp(dato,(*p)->info);

        if(res<0)
            return buscarNodoDevolverContenido(&(*p)->izq,dato,tamDato,cmp);

        if(res>0)
            return buscarNodoDevolverContenido(&(*p)->der,dato,tamDato,cmp);

        if(res==0){
            memcpy((*p)->info,dato,tamDato);
            return TODO_BIEN;
        }
    }
    return SIN_COINDICENCIA;
}


t_nodo **buscarNodoDevolverDireccion(t_arbol *p, void *dato, int (*cmp)(void*,void*)){

    if(*p){
        res=cmp(dato,(*p)->info);

        if(res<0)
            return buscarNodoDevolverDireccion(&(*p)->izq,dato,cmp);

        if(res>0)
            return buscarNodoDevolverDireccion(&(*p)->der,dato,cmp);

        if(res==0)
            return p;
    }
    return SIN_DIRECCION;
}
// t_arbol *p es igual a t_nodo **p
t_nodo **retornarMenorNodo(t_arbol *p){

    if(!(*p)->izq)
        return p;

    return retornarMenorNodo(&(*p)->izq);
}
t_nodo **retornarMayorNodo(t_arbol *p){

    if(!(*p)->der)
        return p;

    return retornarMayorNodo(&(*p)->der);
}

int obtenerAlturaArbol(t_arbol *p){

    if(!*p)
        return 0;

}
