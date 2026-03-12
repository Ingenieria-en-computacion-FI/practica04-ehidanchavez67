#include <stdio.h>
#include <stdlib.h>

int main (){
int *array, *array2;
int num,i;

printf("¿Cuantos elementos tiene el conjunto?\n");
scanf("%d", &num);
array = (int*) malloc(num*sizeof(int));

if (array!=NULL) {
    for(i=0; i < num; i++){
        printf("Ingresa[%d]\n",i);
        scanf("%d",(array + i));
    }
    printf("[ ");
    for(i = 0; i < num; i++) {
        printf("Valor insertado: %d\n", *(array + i));
    }
    printf("]\n");
}
array2 = (int*)realloc(array,num*2*sizeof(int));
 if (array2!=NULL) {
    for(i = num; i < 2*num; i++) {
        printf("Ingresa [%d]\n", i);
        scanf("%d", (array2+i));
     }
    printf("]\n");
    for(i=0; i<2*num; i++) {
        printf("%d ", *(array2+i));
    }
    printf("]\n");
 }
 free(array2);
return 0;
}
