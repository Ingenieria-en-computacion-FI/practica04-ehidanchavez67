#include <stdio.h>
#include <stdlib.h>

int main (){
int *array;
int num,i;

printf("¿Cuantos elementos tiene el conjunto?\n");
scanf("%d", &num);
array = (int *)calloc(num, sizeof(int));

if (array!=NULL) {
for(i=0; i < num; i++){
        printf("Elemento[%d]:\n", i);
        scanf("%d", (array+i));
}
    
printf("[ ");
for(i=0; i < num; i++) {
printf("%d", *(array+i));
}
printf("]\n");
free(array);
}
return 0;
}
