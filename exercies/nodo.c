#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

Nodo* crearNodo(int valor) {
    Nodo* newNodo=(Nodo*)malloc(sizeof(Nodo));
    if(newNodo!=NULL) {
        newNodo->dato=valor;
        newNodo->siguiente=NULL;
    }
    return newNodo;
}

Nodo* crearArregloNodos(int n) {
    Nodo* arreglo = (Nodo*)calloc(n, sizeof(Nodo));
    return arreglo;
}

Nodo* agregarNodo(Nodo* arreglo, int* n, int valor) {
    Nodo* newArreglo = (Nodo*)realloc(arreglo, (*n+1)*sizeof(Nodo));
     if (newArreglo != NULL) {
        arreglo = newArreglo;
        arreglo[*n].dato = valor;
        arreglo[*n].siguiente = NULL;
        (*n)++; 
    }
    return arreglo;
}

void liberarNodos(Nodo* arreglo, int n){
    if (arreglo != NULL) {
        free(arreglo);
    }
}

Nodo* construirTresNodos() {
    Nodo* primerNodo = (Nodo*)malloc(sizeof(Nodo));
    Nodo* segundoNodo = (Nodo*)malloc(sizeof(Nodo));
    Nodo* tercerNodo = (Nodo*)malloc(sizeof(Nodo));
    
    
    if (primerNodo == NULL || segundoNodo == NULL || tercerNodo == NULL) {
        
        if (primerNodo) free(primerNodo);
        if (segundoNodo) free(segundoNodo);
        if (tercerNodo) free(tercerNodo);
        return NULL;
    }
    
  
    primerNodo->dato = 8;
    segundoNodo->dato = 6;
    tercerNodo->dato = 6;
    
   
    primerNodo->siguiente = segundoNodo;
    segundoNodo->siguiente = tercerNodo;
    tercerNodo->siguiente = NULL; 
    
    return primerNodo;  
}

int contarNodos(Nodo* inicio) {

    int contador = 0;
    Nodo* actual = inicio;

    while(actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

Nodo* creaNodosPorEntrada() {
    int cantidad, i, valor;
    Nodo* lista = NULL;
    Nodo* ultimo = NULL;
    Nodo* nuevo;

    printf("Cuantos nodos quieres crear? ");
    scanf("%d", &cantidad);

    for(i = 0; i < cantidad; i++) {
        printf("Valor para nodo %d: ", i+1);
        scanf("%d", &valor);

        nuevo = crearNodo(valor); 
        if (nuevo == NULL) {
            printf("Error: no se pudo crear el nodo\n");
            Nodo* temp;
            while (lista != NULL) {
                temp = lista;
                lista = lista->siguiente;
                free(temp);
            }
            return NULL;
        }

        if (lista == NULL) {
            lista = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
    
    return lista;  
}
