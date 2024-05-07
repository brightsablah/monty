#include "monty.h"

/**
 * rotr_ - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;
	(void)line_number;
	
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}
