#include "monty.h"

/**
 * pstr_op - Prints the string starting at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    putchar('\n');
}
