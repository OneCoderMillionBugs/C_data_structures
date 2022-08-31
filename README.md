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

    // Returns an element
    // If more precisely: expected type pointer
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

This structure is best suited for pointer types. \
So all you have to do in this case is:

```c
    #include "list.h"

    int main() {
        // Initializing the list, and setting its type to char*
        LinkedList list = LIST(char *);

        char s1[] = "First";
        char s2[] = "Second";

        // Inserting elements
        // At this stage, if the types of input data and list data are mismatched, the program terminates
        LIST_INSERT(s1, (&list), char *);
        LIST_INSERT(s2, (&list), char *);

        // Removing an element
        char *s3 = LIST_REMOVE(1, (&list), char *)

        return 0;
    }
```
</details>
