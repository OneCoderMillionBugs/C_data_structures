#include "queue.h"

int queue_insert(int n, Queue *q)
{
    if ((q->tail + 1) % q->N != q->head)
    {
        q->tail = q->size > 0 ? (q->tail + 1) % q->N : q->tail;
        q->arr[q->tail] = n;
        q->size++;

        return 1;
    }
    return 0;
}

int queue_poll(Queue *q)
{
    int result = queue_peek(q);

    if (q->size > 0)
    {
        q->arr[q->head] = 0;
        q->size--;
        q->head = q->size > 0 ? (q->head + 1) % q->N : q->head;
    }
    else
    {
        ERROR("%s:%d: error: Retrieving an element from an empty queue\n");
    }

    return result;
}

int queue_peek(Queue *q)
{
    if (q->size > 0)
    {
        return q->arr[q->head];
    }
    else ERROR("%s:%d: error: Retrieving an element from an empty queue\n");
}