/**
 * @author: Rezvee Rahman
 * @date: 09/28/2024
 * 
 * @details: This will use the 
 */

#include "node.c"

#include <stdlib.h>

/***********************************************************************
 *
 * The linked list
 *
 ***********************************************************************/

/**
 * The linked list structure should have the following.
 * 1. The size of the linked list
 * 2. A function to match 
 * 2. A Destroy function to de-structure and free the linked list memory
 * 4. Head of the linked list
 * 5. The tail of the linked list
 */
typedef struct linked_list {
        int size;

        int (*match)(const void *k1, const void *k2);
        void (*destroy)(void *data);

        node *head; 
        node *tail; 
} l_list;


/***********************************************************************
 *
 * Header file
 *
 ***********************************************************************/

void list_init(l_list *list, void (*destroy)(void *data));

void list_destroy(l_list *list);

int list_ins_next(l_list *list, node *elem, const void *data);

int list_rem_next(l_list *list, node *elem, void **data);

/**
 * MACROS for the linked list
 */
#define list_size(list) ((list) -> size)

#define list_head(list) ((list) -> head)

#define list_tail(list) ((list) -> tail)

#define list_is_head(list, elem) ((elem) == (list) -> head ? 1 : 0)

#define list_is_tail(elem) ((elem) -> next == NULL ? 1 : 0)

#define list_next(elem) ((elem) -> next)

#define list_data(elem) ((elem) -> data)
