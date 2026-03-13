#ifndef NODO_H
#define NODO_H

#include <stdbool.h>
struct nodo{
    int dato;
    struct nodo* siguiente;
};
typedef struct nodo Nodo;

Nodo* crearNodo(int valor);
Nodo* crearArregloNodos(int n);
Nodo* agregarNodo(Nodo* arreglo, int* n, int valor);
void liberarNodos(Nodo* arreglo, int n);
Nodo* construirTresNodos();
int contarNodos(Nodo* inicio);
Nodo* crearNodosPorEntrada();

#endif





