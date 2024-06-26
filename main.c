#include "monty.h"

	int MODE = 0;

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

	/* skip comment lines # */
	if (line[0] == '#')
		continue;
	    
        opcode = strtok(line, " \n");
        if (opcode != NULL && *opcode != '#')
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, line_number);
            else if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
	    else if (strcmp(opcode, "pint") == 0)
                pint(&stack, line_number);	  
	    else if (strcmp(opcode, "pop") == 0)
                pop(&stack, line_number);
	    else if (strcmp(opcode, "swap") == 0)
                swap(&stack, line_number);
	else if (strcmp(opcode, "add") == 0)
                add(&stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
                nop(&stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
                sub(&stack, line_number);
	else if (strcmp(opcode, "div") == 0)
                div_(&stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
                mul_(&stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
                mod_(&stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
                pchar_(&stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
                pstr_(&stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
                rotl_(&stack, line_number);
	else if (strcmp(opcode, "rotr") == 0)
                rotr_(&stack, line_number);
	else if (strcmp(opcode, "stack") == 0)
                stack_(&stack, line_number);
	else if (strcmp(opcode, "queue") == 0)
                queue_(&stack, line_number);
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
