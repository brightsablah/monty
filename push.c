#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int value;
    stack_t *new_node = NULL;

    if (arg == NULL || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    new_node->next = *stack;
    *stack = new_node;
}
