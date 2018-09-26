#include <stdlib.h>
#include <stdio.h>
#include "queue2.h"

int main(void){

    queue q = queue_new();
    int i;

    for (i = 1; i < 6; i++){
        enqueue(q, (double) i);
    }

    printf("Queue contents:\n");
    queue_print(q);

    printf("Queue size: %d\n", queue_size(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Queue contents:\n");
    queue_print(q);

    printf("Queue size: %d\n", queue_size(q));

    for (i = 1; i < 4; i++){
        enqueue(q, (double) i);
    }

    printf("Queue contents:\n");
    queue_print(q);

    printf("Queue size: %d\n", queue_size(q));


    queue_free(q);

    return EXIT_SUCCESS;
}
