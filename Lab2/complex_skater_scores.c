#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 10

double calculate_mean(int n, double judge[]){

    double total = 0.0, mean;
    int i;
    
    for(i=0; i < n; i++){
        total += judge[i];
    }
    mean = total/n;

    return mean;
}

double calculate_deviation(double judge[], double mean, int n){

    double variance = 0.0, deviation = 0.0, sum = 0.0;
    int i;

    for(i=0; i<n; i++){
        sum += (judge[i]-mean)*(judge[i]-mean);
    }
    variance = sum/(n-1);

    deviation = sqrt(variance);

    return deviation;
}



int main(void){

    int n, count = 0;
    double a, b, c;
    double judge1[ARRAY_SIZE],judge2[ARRAY_SIZE],judge3[ARRAY_SIZE];
    double judge1_mean, judge2_mean, judge3_mean;
    double judge1_deviation, judge2_deviation, judge3_deviation;

    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){

        judge1[count] = a;
        judge2[count] = b;
        judge3[count] = c;
        
        count++;
    }

    judge1_mean = calculate_mean(count, judge1);
    judge2_mean = calculate_mean(count, judge2);
    judge3_mean = calculate_mean(count, judge3);

    judge1_deviation = calculate_deviation(judge1, judge1_mean, count);
    judge2_deviation = calculate_deviation(judge2, judge2_mean, count);
    judge3_deviation = calculate_deviation(judge3, judge3_mean, count);

    printf("\t  Average\tSD\n");
    printf("Judge 1: %8.3f %8.3f\n", judge1_mean, judge1_deviation);
    printf("Judge 2: %8.3f %8.3f\n", judge2_mean, judge2_deviation);
    printf("Judge 3: %8.3f %8.3f\n", judge3_mean, judge3_deviation);

    return EXIT_SUCCESS;
}
           
        
