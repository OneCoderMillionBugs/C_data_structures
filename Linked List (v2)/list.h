#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void *LinkedList;

#define DEFINE_LIST(type)               \
    struct type##_list_node             \
    {                                   \
        type data;                      \
        struct type##_list_node *next;  \
    }                                   \
    typedef *type##_ListNode;           \
    \
    struct type##_linked_list           \
    {                                   \
        size_t size;                    \
        type##_ListNode head;           \
        type##_ListNode tail;           \
        const char *T;                  \
    }                                   \
    typedef type##_LinkedList;          \
    \
    type##_LinkedList *type##__list_construct__()               \
    {                                                           \
        type##_LinkedList *list = (type##_LinkedList *)malloc(  \
            sizeof(type##_LinkedList)                           \
        );                                                      \
        list->T = #type;                                        \
        return list;                                            \
    }                                                           \
    \
    void type##__list_insert__(type data, type##_LinkedList *list)  \
    {                                                               \
        type##_ListNode newNode = (type##_ListNode)malloc(          \
            sizeof(struct type##_list_node)                         \
        );                                                          \
        newNode->data = data;                                       \
        newNode->next = NULL;                                       \
        type##_ListNode current = list->head;                       \
        type##_ListNode prev = NULL;                                \
        while (current != NULL)                                     \
        {                                                           \
            prev = current;                                         \
            current = current->next;                                \
        }                                                           \
        if (prev == NULL)                                           \
        {                                                           \
            list->head = newNode;                                   \
        }                                                           \
        else                                                        \
        {                                                           \
            prev->next = newNode;                                   \
        }                                                           \
        list->size++;                                               \
    }                                                               \
    \
    type type##__list_remove__(size_t index, type##_LinkedList *list)   \
    {                                                                   \
        type##_ListNode current = list->head;                           \
        type##_ListNode prev = NULL;                                    \
        while (index--)                                                 \
        {                                                               \
            prev = current;                                             \
            current = current->next;                                    \
        }                                                               \
        type result = (current != NULL) ? current->data : (type)0;      \
        if (prev != NULL && current != NULL)                            \
        {                                                               \
            prev->next = current->next;                                 \
            free(current);                                              \
            list->size--;                                               \
        }                                                               \
        else if (current != NULL)                                       \
        {                                                               \
            list->head = list->head->next;                              \
            free(current);                                              \
            list->size--;                                               \
        }                                                               \
        return result;                                                  \
    }                                                                   \
    \
    type type##__list_get__(size_t index, type##_LinkedList *list)  \
    {                                                               \
        type##_ListNode current = list->head;                       \
        for (size_t i = 0; i < index; i++)                          \
        {                                                           \
            current = current->next;                                \
        }                                                           \
        return current->data;                                       \
    }

#define NEW_LIST(type) type##__list_construct__()

#define TYPECHECK(type, list) (                                             \
    strcmp(#type, list->T) ?                                                \
    fprintf(                                                                \
        stderr, __FILE__":%d: error: Attempting to interact data of type %s"\
        " with list of type %s\n", __LINE__, #type, list->T                 \
    ), exit(-1) : 0                                                         \
)

#define LIST_INSERT(data, list, type) (                     \
    TYPECHECK(type, ((type##_LinkedList *)list)),           \
    type##__list_insert__(data, (type##_LinkedList *)list)  \
)

#define LIST_GET(index, list, type) (                       \
    TYPECHECK(type, ((type##_LinkedList *)list)),           \
    type##__list_get__(index, (type##_LinkedList *)list)    \
)

#define LIST_REMOVE(index, list, type) (                    \
    TYPECHECK(type, ((type##_LinkedList *)list)),           \
    type##__list_remove__(index, (type##_LinkedList *)list) \
)

#define LIST_SIZE(list, type) (((type##_LinkedList *)list)->size)

#endif
