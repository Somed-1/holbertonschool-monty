#include "monty.h"


/**
 * main - main function of program
 * @ac: argument count
 * @av: array of arguments
 * Return: always 0 on success
 */
int main(int ac, char **av)
{
	FILE *script_file;
	char *opcode;
	size_t size = 0;
	stack_t *stack = NULL; /* first elem */
	int line = 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script_file = fopen(av[1], "r");
	if (script_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&opcode, &size, script_file) != -1)
	{
		line++;
		token = strtok(opcode, DELIMS);
		if (token == NULL || *token == '#')
			continue;
		execute(&stack, line);
	}
	free(opcode);
	fclose(script_file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
