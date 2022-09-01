# C data structures
Various data structures implemented in C language for learning purposes 
and possibly further personal use.

## Table of contents
* [General info](#general-information)
* [Linked List v1](#linked-list-v1)
* [Linked List v2](#linked-list-v2)

## General information
This repository is a collection of various data structures written in the C language. 
Efficiency was not always the author's priority, some structures were created solely 
for experimental purposes, and may have several implementations, of varying degrees of bugginess. 
Use at your own risk.

<details>
<summary>

## Linked List v1
</summary>

### About
The first version of the linked list structure is created with a void pointer 
in the list node, which can contain the address of an instance of any data type. \
It uses macros as an interface to call all internal functions. 
This is done to avoid errors related to differences in the type of data supplied 
to the input and those already in the list.

### Functionality
List of functions and their complexity:
- Inserting one element at the end of the list. *O(n)*
- Getting an element at some index. *O(n)*
- Removing an element at some index. *O(n)*

### Usage
This structure has four macros for performing manipulations:
```
// Initializes the list
LIST(type of data that will be stored in a list)

// Inserts an element
LIST_INSERT(
    pointer to data, 
    list address, 
    type of input data
)

// Returns an element of the expected type
LIST_GET(
    index, 
    list address, 
    type of expected data
)

// Same as get function, except it also removes the element from the list
LIST_REMOVE(
    index,
    list address,
    type of expected data
)
```
###### Important! Do not ever input literals into LIST_INSERT
Example with strings:

```c
#include "list.h"

int main(void)
{
    // Initializing the list, and setting its type to char*
    LinkedList list = LIST(char *);

    char s1[] = "First";
    char s2[] = "Second";

    // In order to avoid memory problems,
    // we have to pack all data into pointers, and 
    // then pass the address of that newly created pointers to the insert function
    char **sptr1 = (char **)s1;
    char **sptr2 = (char **)s2;

    // Inserting elements
    // At this stage, if the types of input data and 
    // list data are mismatched, the program terminates
    LIST_INSERT(&sptr1, &list, char *);
    LIST_INSERT(&sptr2, &list, char *);

    // Removing an element
    char *s3 = LIST_REMOVE(0, &list, char *);

    return 0;
}
```

Example with int:

```c
#include "list.h"

int main() {
    // Initializing the list, and setting its type to int
    LinkedList list = LIST(int);

    int n1 = 1;
    int n2 = 2;

    // In case of non-pointer types we don't
    // need to create an extra layer of pointers
    LIST_INSERT(&n1, &list, int);
    LIST_INSERT(&n2, &list, int);

    // Removing an element
    int n3 = LIST_REMOVE(0, &list, int);
    printf("%d\n", n3);

    return 0;
}
```
</details>


<details> 
<summary>

## Linked List v2
</summary>



</details>