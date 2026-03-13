#include <stdio.h>
#include <stdlib.h>  
#include "nodo.h"

int main() {
    printf("===== Almacen de los ejercicios de nodos ====\n");

    // Ejercicio 1
    printf("\n Ejercicio 1:\n");
    Nodo* n1 = crearNodo(10);
    if (n1) printf("Nodo creado con dato: %d\n", n1->dato);

    // Ejercicio 2
    printf("\n Ejercicio 2: \n");
    Nodo* arreglo = crearArregloNodos(5);
    // TODO(1): imprimir arreglo
    printf("Arreglo de 5 nodos creado (inicializados a 0/NULL):\n");
    for(int i = 0; i < 5; i++) {
        printf("  arreglo[%d]: dato=%d, siguiente=%p\n", 
               i, arreglo[i].dato, arreglo[i].siguiente);
    }

    // Ejercicio 3
    printf("\n--- Ejercicio 3: agregarNodo ---\n");
    int tam = 5;
    printf("Agregando nodo con valor 99...\n");
    arreglo = agregarNodo(arreglo, &tam, 99);
    // TODO(2): imprimir arreglo actualizado
    printf("Arreglo actualizado (%d nodos):\n", tam);
    for(int i = 0; i < tam; i++) {
        printf("  arreglo[%d]: dato=%d, siguiente=%p\n", 
               i, arreglo[i].dato, arreglo[i].siguiente);
    }

    // Ejercicio 4
    printf("\n--- Ejercicio 4: liberarNodos ---\n");
    printf("Liberando arreglo de %d nodos...\n", tam);
    liberarNodos(arreglo, tam);
    printf("Arreglo liberado.\n");
    printf("Liberando nodo individual n1...\n");
    liberarNodos(n1, 1);
    printf("Nodo liberado.\n");

    // Ejercicio 5
    printf("\n--- Ejercicio 5: construirTresNodos ---\n");
    Nodo* inicio = construirTresNodos();
    // TODO(3): imprimir nodos
    if (inicio != NULL) {
        printf("Lista de 3 nodos enlazados:\n");
        Nodo* actual = inicio;
        int pos = 1;
        while(actual != NULL) {
            printf("  Nodo %d: dato=%d", pos, actual->dato);
            if (actual->siguiente != NULL)
                printf(" -> siguiente apunta a nodo %d\n", pos+1);
            else
                printf(" -> siguiente = NULL\n");
            actual = actual->siguiente;
            pos++;
        }
    } else {
        printf("Error al crear la lista de nodos\n");
    }

    // Ejercicio 6
    printf("\n--- Ejercicio 6: contarNodos ---\n");
    int total = contarNodos(inicio);
    printf("Total de nodos: %d\n", total);

    // Ejercicio 7
    printf("\n--- Ejercicio 7: creaNodosPorEntrada ---\n");
    Nodo* desdeEntrada = creaNodosPorEntrada();
    // TODO(4): imprimir nodos
    if (desdeEntrada != NULL) {
        int total2 = contarNodos(desdeEntrada);
        printf("Lista creada por usuario (%d nodos):\n", total2);
        Nodo* actual = desdeEntrada;
        int pos = 1;
        while(actual != NULL) {
            printf("  Nodo %d: dato=%d\n", pos, actual->dato);
            actual = actual->siguiente;
            pos++;
        }
        
        // Liberar memoria de la lista creada por usuario
        printf("Liberando lista creada por usuario...\n");
        actual = desdeEntrada;
        while(actual != NULL) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
        printf("Lista liberada.\n");
    } else {
        printf("No se creó la lista o está vacía.\n");
    }
    
    // Liberar memoria de la lista de 3 nodos
    if (inicio != NULL) {
        printf("\nLiberando lista de 3 nodos...\n");
        Nodo* actual = inicio;
        while(actual != NULL) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
        printf("Lista liberada.\n");
    }

    printf("\n===== Fin del programa =====\n");
    return 0;
}
