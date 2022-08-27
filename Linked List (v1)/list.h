#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CHECK_TYPES(type_a, list) (                                             \
    strcmp(#type_a, list->type) ?                                               \
        fprintf(                                                                \
            stderr, __FILE__":%d: error: Attempting to interact data of type %s"\
            " with list of type %s\n", __LINE__, #type_a, list->type            \
        ),                                                                      \
        exit(-1)                                                                \
    : 0                                                                         \
)

#define LIST(type) {0, NULL, NULL, #type};
#define LIST_INSERT(data, list, type) \
    (CHECK_TYPES(type, list), __list_insert__(data, list))
#define LIST_GET(index, list, type) \
    (CHECK_TYPES(type, list), (type *)__list_get__(index, list))
#define LIST_REMOVE(index, list, type) \
    (CHECK_TYPES(type, list), (type *)__list_remove__(index, list))


struct list_node
{
    void *data;
    struct list_node *next;
}
typedef *ListNode;

struct linked_list
{
    size_t size;
    ListNode head;
    ListNode tail;
    const char *type;
}
typedef LinkedList;

void  __list_insert__(void *dptr, LinkedList *list);
void *__list_remove__(size_t index, LinkedList *list);
void *__list_get__(size_t index, LinkedList *list);

#endif