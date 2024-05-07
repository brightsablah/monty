#include "monty.h"

/**
 * stack_ - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void stack_(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	stack_t *prev = NULL;
    	stack_t *next = NULL;
	(void)line_number;


    if (mode == 1)  /* check mode */
    {
        /* Reverse the order of elements to switch to stack mode */
        current = *stack;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }

        *stack = prev;  /* Update the top of the stack */
    }

    mode = 0;  /* Set mode to stack */
}

/**
 * queue_ - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void queue_(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	stack_t *prev = NULL;
    	stack_t *next = NULL;
    	(void)line_number;


    if (mode == 0)  /* check mode */
    {
        /* Reverse the order of elements to switch to queue mode */
        current = *stack;

        while (current != NULL)
        {
            next = current->prev;
            current->prev = prev;
            current->next = next;
            prev = current;
            current = next;
        }

        *stack = prev;  /* Update the top of the stack */
    }

    mode = 1;  /* Set mode to queue */
}
