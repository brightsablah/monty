/* mode: 0 for stack, 1 for queue */
int mode = 0;

/**
 * stack_op - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void stack_(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    mode = 0;
}

/**
 * queue_op - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number being executed
 */
void queue_(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    mode = 1;
}
