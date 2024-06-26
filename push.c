#include "monty.h"

/**
 * push - Pushes an element onto the stack or queue based on the current mode
 * @stack: Pointer to the top of the stack or queue
 * @line_number: Line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    long int value;
    stack_t *new_node = NULL;
    char *endptr;

    if (arg == NULL || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = strtol(arg, &endptr, 10);
    /* Check if the entire argument is a valid integer */
    if (*endptr != '\0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (MODE == 0) /* Stack mode (LIFO) */
    {
        if (*stack != NULL)
            (*stack)->prev = new_node;
        new_node->next = *stack;
        *stack = new_node;
    }
    else if (MODE == 1) /* Queue mode (FIFO) */
    {
        stack_t *last = *stack;
        if (last != NULL)
        {
            while (last->next != NULL)
                last = last->next;
            last->next = new_node;
            new_node->prev = last;
        }
    }
}
