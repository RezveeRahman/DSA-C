/**
 * @author: Rezvee Rahman
 * @date: 09/28/2024
 * 
 * @details: Creating a node structure for the linked list data
 * structure. The node consists of the following fields
 *
 * 1. void pointer item (basically generic pointer)
 * 2. node pointer
 */

typedef struct linked_list_node
{
        void *item;
        struct node* next;
} node;