/**
 * File: queue.c
 * @author: Josh King.
 */


#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "mylib.h"

/**
 * Struct: q_item
 * Purpose: Store in the information of an item in a queue.
 */
struct q_item {
    double item;
    q_item next;
};

/**
 * Struct: queuerec
 * Purpose: Store the information about a queue.
 */
struct queuerec {
    q_item first;
    q_item last;
    int length;
};

/**
 * Function: queue_new
 * Purpose: Creates a new empty queue.
 *
 * @return The queue created.
 */
queue queue_new(){

    queue result;

    result = emalloc(sizeof *result);
 
    result->length = 0;
    result->first = NULL;
    result->last = result->first;

    return result;
}

/**
 * Function: enqueue
 * Purpose: Add an item to the end of a queue.
 *
 * @param Queue to which the item will be added.
 * @param Item to be added to the queue.
 */
void enqueue(queue q, double item){

    q_item entry;

    if(q->first == NULL && q->last == NULL){
        entry = emalloc(sizeof *entry);
        entry->item = item;
        entry->next = NULL;
        q->first = entry;
        q->last = q->first;
    } else {
        entry = emalloc(sizeof *entry);
        entry->item = item;
        entry->next = NULL;
        q->last->next = entry;
        q->last = entry;
    }
    q->length++;

}

/**
 * Function: dequeue
 * Purpose: Remove and return the item at the front of a queue.
 *
 * @param The queue from which the item will be removed.
 * @return The item from the front of the queue.
 */
double dequeue(queue q){

    double item;
    q_item node;

    if (q->length > 0){
        
        item = q->first->item;
        node = q->first;
        q->first = node->next;
        q->length--;
        if (q->length == 0){
            q->last = NULL;
        }
        free(node);

        return item;
        
    } else {
        printf("Queue is empty\n");
        return 0;
    }

}

/**
 * Function: queue_print
 * Purpose: Print out the contents of a queue.
 *
 * @param The queue to be printed.
 */
void queue_print(queue q){

    q_item current = NULL;

    if (q->length > 0){
        current = q->first;
        while (current->next != NULL){
            printf("%f\n", current->item);
            current = current->next;
        }
        printf("%f\n", current->item);
    }
}

/**
 * Function: queue_size
 * Purpose: Return the size of a queue.
 *
 * @param The queue the size of which will be returned.
 * @return The size of the given queue.
 */
int queue_size(queue q){

    return q->length;
}

/**
 * Function: queue_free
 * Purpose: Delete a queue and free the memory allocated for it.
 *
 * @param The queue to be deleted.
 * @return The deleted queue object, now NULL.
 */
queue queue_free(queue q) {
    q_item current;
    q_item next;
    
    if (q->length > 0) {
        current = q->first;
        
        while (current->next != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        free(current);
    }
    free(q);
    return q;
}
