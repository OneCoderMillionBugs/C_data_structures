#include "list.h"

void __list_insert__(void *dptr, LinkedList *list)
{
    ListNode newNode = (ListNode)malloc(sizeof(struct list_node));
    newNode->data = dptr;
    newNode->next = NULL;

    ListNode current = list->head;
    ListNode prev = NULL;

    while (current != NULL)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        list->head = newNode;
    }
    else
    {
        prev->next = newNode;
    }
    list->size++;
}

void *__list_remove__(size_t index, LinkedList *list)
{
    ListNode current = list->head;
    ListNode prev = NULL;

    while (index--)
    {
        prev = current;
        current = current->next;
    }
    
    void *result = (current != NULL) ? current->data : NULL;

    if (prev != NULL && current != NULL) 
    {
        prev->next = current->next;
        free(current);
        list->size--;
    }
    else if (current != NULL)
    {
        list->head = list->head->next;
        free(current);
        list->size--;
    }

    return result;
}

void *__list_get__(size_t index, LinkedList *list)
{
    ListNode current = list->head;
    for (size_t i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}