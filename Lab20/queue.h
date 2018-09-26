/**
 * File: queue.h
 * @author Josh King.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queuerec *queue;

typedef struct q_item *q_item;

/**
 * Prototypes
 * Purpose: specifies functions to be implemented in the queue.c file, based on
 * their signatures.
 */
extern queue queue_new();
extern void enqueue(queue q, double item);
extern double dequeue(queue q);
extern void queue_print(queue q);
extern int queue_size(queue q);
extern queue queue_free(queue q);

#endif
