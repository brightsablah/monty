#include "monty.h"

/**
 * pall - Prints all the values on the stack or queue
 * @stack: Pointer to the top of the stack or queue
 * @line_number: Line number being executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
	(void)line_number;

    if (MODE == 0) /* Stack mode (LIFO) */
    {
        current = *stack;
        while (current != NULL)
        {
            printf("%d\n", current->n);
            current = current->next;
        }
    }
    else if (MODE == 1) /* Queue mode (FIFO) */
    {
        current = *stack;
        while (current != NULL)
        {
            printf("%d\n", current->n);
            current = current->prev;
        }
    }
}
