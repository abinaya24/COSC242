#include <stdio.h>
#include <stdlib.h>

int main(void){

    double s1,s2,s3;

    printf("Enter first score:\n");
    scanf("%lg", &s1);
    printf("Enter second score:\n");
    scanf("%lg", &s2);
    printf("Enter third score:\n");
    scanf("%lg", &s3);

    if(s1 < s2 && s1 < s3){
        printf("%g\n", (s2+s3)/2);
    }
    else if (s2 < s1 && s2 < s3){
        printf("%g\n", (s1+s3)/2);
    }
    else if (s3 < s1 && s3 < s2){
        printf("%g\n", (s1+s2)/2);
    }

    return 1;
}
