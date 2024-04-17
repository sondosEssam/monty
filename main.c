#include "monty.h"
/**
 * main - main function for the project
 * @ac: no of arguments
 * @argv: arguments
 * Return: 0
*/

int main(int ac, char **argv)
{
	instruction_t *point = NULL;
	stack_t **stack = NULL;
	FILE *op = NULL;

	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op = fopen(argv[1], "r");
	if (op == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t *));
	*stack = NULL;
	if (stack == NULL)
		mallochandling();
	mainPart(point, stack, op);
	fclose(op);
	free_stack(stack);
	return (0);
}
