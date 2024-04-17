#include "monty.h"
int main(int ac, char **argv)
{
	instruction_t *point = NULL;
	stack_t **stack = NULL;
	FILE *op = fopen(argv[1], "r");

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (op == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		fclose(op);
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
