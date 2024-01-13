#include "monty.h"

/**
 * execute - execute instructions
 * @stack: stack
 * @line: line of file
 */
void execute(stack_t **stack, int line)
{
	int i = 0;
	instruction_t instrs[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"add", add}, {"nop", nop},
		{"swap", swap}, {NULL, NULL}
	};

	while (instrs[i].opcode)
	{
		if (strcmp(instrs[i].opcode, token) == 0)
		{
			instrs[i].f(stack, line);
			break;
		}
		i++;
	}
	if (instrs[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, token);
		exit(EXIT_FAILURE);
	}
}
