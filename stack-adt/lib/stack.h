/**
 * @author: Rezvee Rahman
 * @date: 09/30/2024
 * 
 * @details: Implementing the stack data type
 *
 * Credits to: Kyle Luodon's Mastering Algorithm's with C... book
 */

#include <stdlib.h>

#include 

typedef struct Stack;

/***********************************************************************
*                       -- Initialization --                           *
***********************************************************************/

void stack_init(Stack *stack, void (*destroy)(void *data));

/***********************************************************************
*                       -- Functions --                                *
***********************************************************************/

void stack_destroy(Stack *stack);

void stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack);

/***********************************************************************
*                       -- MACROS --                                   *
***********************************************************************/

#define stack_size list_size