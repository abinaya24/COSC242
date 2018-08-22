#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    int winner = 0;
    double total;
    double pretotal = 0.0;
    double a, b, c;

    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){

        total = a+b+c;
        if (total > pretotal){
            pretotal = total;
            winner = n;
        }
    }

    printf("Winner is %d", winner);

    return 1;
}

            
