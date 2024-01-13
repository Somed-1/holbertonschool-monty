#include "monty.h"

/**
 * push - push to stack
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(NULL, DELIMS);
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (is_number(opcode) && opcode != NULL)
	{
		new->n = atoi(opcode);
		new->prev = NULL;
		new->next = *stack;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints stack
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints elements of stack (top)
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pop - remove elemet form stack
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *right = *stack;

	if (stack && *stack)
	{
		*stack = (*stack)->next;
		free(right);
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * add - adds 2 elems of stack
 * @stack: stack
 * @line_number: line of file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *right;

	if (stack && *stack && (*stack)->next)
	{
		right = (*stack)->next;
		right->n += (*stack)->n;
		pop(stack, line_number);
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
