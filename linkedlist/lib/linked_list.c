/**
 * @author: Rezvee Rahman
 * @date: 09/28/2024
 *
 * @details: Linked list implementation.
 */

#include <stdlib.h>
#include <string.h>

#include "./linked_list.h"

/**
 * Initialize linked list. When we initialize
 * 
 * @see linked_list.h list_init
 */
void list_init(l_list *list, void (*destroy)(void *data)) 
{
        list -> size = 0;
        list -> destroy =  destroy;

        list -> head = NULL;
        list -> tail = NULL;

        /* This return statement is kinda unecessary :^/ */
        return;
}

/**
 * Destroy the linked list. This function calls a user defined function
 * to destroy the list.
 */
void list_destroy(l_list *list)
{
        void    *data;

        while(list_size(list) > 0) {
                /*
                 * Remove each element. Check if the element is removed
                 * properly and the destroy functin is not NULL. If it
                 * isn't then destroy.
                 */
                if ((list_rem_next(list, NULL, (void **) data) == 0) &&
                (list -> destroy != NULL)) {
                        list->destroy(data);
                }
        }

        /* Clear out any data of the list */
        memset(list, 0, sizeof(int));
}

int list_ins_next(l_list *list, node *elem, const void *data)
{
        node    *new_elem;

        /* Allocate storage for the new node element. If null return (-1) */
        if ((new_elem = (node*)malloc(sizeof(node))) == NULL) {
                return (-1);
        }

        /* Generic pointer initialized for the new element */
        new_elem -> item = (void *)data;

        /*
         * handle the insertion of the elment.
         * If the element is NULL then add it to the tail or the head.
         * If not then add the element to the tail if the linked list
         * already has a head.
         */
        if (elem == NULL) {
                if (list_size(list) == 0) {
                        list->tail = new_elem;
                }

                new_elem -> next = list->head;
                list -> head = new_elem;
        } else {
                if (elem -> next) {
                        list -> tail = new_elem;
                }

                new_elem -> next = elem -> next;
                elem -> next = new_elem;
        }

        /* Increment list size */
        list -> size++;

        /* Return 0 for success */
        return (0);
}

int list_rem_next(l_list *list, node *elem, void **data) {
        node    *old_elem;

        /* Check if there is any element to remove from the list */
        if (list_size(list) == 0) {
                return (-1);
        }

        /*
         * 
         */
        if (elem == NULL) {
                *data = list -> head -> item;
                old_elem = list -> head;
                list -> head = list ->head -> next;

                /* Remove the tail */
                if (list_size(list) == 1) {
                        list -> tail = NULL;
                }
        } else {
                if (elem -> next == NULL) {
                        return (-1);
                }

                *data = elem -> next -> item;
                old_elem = elem -> next;
                elem -> next = elem -> next -> next;

                if (elem -> next == NULL) {
                        list -> tail = elem;
                }
        }

        free(old_elem);

        list -> size--;

        return (0);

}
