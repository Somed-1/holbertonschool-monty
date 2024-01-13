#include "monty.h"

/**
 * is_number - custom atoi
 * @str: string
 * Return: int from str
 */
int is_number(char *str)
{
	char *s = str;

	if (!s || *s == '\0')
	{
		return (0);
	}
	if (*s == '-' || *s == '+')
		s++;

	while (*s != '\0')
	{
		if (!isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
