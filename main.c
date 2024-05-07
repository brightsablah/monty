#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
 /* char *line = NULL, *opcode = NULL;
    size_t len = 0;
    ssize_t read; */
	char line[1024];
	char *opcode = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

 
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \n");
        if (opcode != NULL && *opcode != '#')
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, line_number);
            else if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
	    else if (strcmp(opcode, "pint") == 0)
                pint(&stack, line_number);
            /* more opcodes go here */
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
              /*  free(line); */
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
	/*	free(line); 
		line = NULL; */
    }

    /* Free memory allocated for the stack */
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    fclose(file);
    return (EXIT_SUCCESS);
}
