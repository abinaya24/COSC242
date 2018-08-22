#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    /*variable declaration*/
    int i = 0;
    int f = 0;
    int g = 1;
    int temp = 0;

    /*familar for loop*/
    for (i = 0; i < 40; i++){
        printf("%d ", g);
        temp = g;
        g += f;
        f = temp;
        if (i > 1 && i%5 == 0){
            printf("\n");
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
