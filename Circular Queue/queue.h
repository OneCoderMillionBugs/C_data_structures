#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR(msg) \
    (fprintf(stderr, msg, __FILE__, __LINE__), exit(-1))

#define QUEUE(size) \
    {0, 0, 0, size, (int *)calloc(0, sizeof(int) * size)}

struct array_queue
{
    size_t head;
    size_t tail;
    size_t size;
    const size_t N;
    int *arr;
}
typedef Queue;

int queue_insert(int n, Queue *q);  // Returns true if insertion is successful
int queue_poll(Queue *q);           // Removes and returns the first element 
int queue_peek(Queue *q);           // Just returns the first element

#endif