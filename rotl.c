#include "monty.h"

/**
 * rotl_ - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;
	(void)line_number;
	
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->next = NULL;
}
