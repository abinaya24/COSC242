#include <stdio.h>
#include <stdlib.h>

/* Breaks if value higher than 12 */
int factorial(int num){

    int result;

    if (num > 0){
        result = num * factorial(num-1);
        return result;
    } else{
        return 1;
    }
   
}

int main(void){

    int num;

    while(1== scanf("%d", &num)){
        printf("%d\n", factorial(num));
    }

    return EXIT_SUCCESS;
}
