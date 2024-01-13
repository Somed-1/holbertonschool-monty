#include "monty.h"

/**
 * swap - swaps two elems values
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *right;
	int num;

	if (stack && *stack && (*stack)->next)
	{
		right = (*stack)->next;
		num = (*stack)->n;
		(*stack)->n = right->n;
		right->n = num;
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * nop - probably what Abil does
 * @stack: stack
 * @line_number: life of file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
