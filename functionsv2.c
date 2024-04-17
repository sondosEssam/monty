#include"monty.h"
void mainPart(instruction_t * point, stack_t ** stack,FILE *op)
{
	char *word = NULL, *line = NULL;
	int lineNumber = 0 , i = 0;
	size_t read, len;

	while (read = getline(&line, &len, op) != -1)
	{
		if (strcmp(line, "\n") == 0 || strlen(line) == 1)
			continue;
	lineNumber++;
	word = strtok(line, " ");
	(word[strlen(word) - 1] == '\n') ? (word[strlen(word) - 1] = '\0') : (word[strlen(word)] = '\0');
	point = malloc(sizeof(instruction_t));
	if (point == NULL)
		mallochandling();
	point->opcode = word;
	if (strcmp(point->opcode, "push") == 0)
	{
		if (checkfordigits(word = strtok(NULL, " ")) != -1 || strcmp(word, "\n") != 0)
		{
			pushVal = atoi(word);
			point->f = &pushi;
		}
		else
		{
			printf("L<%d>: usage: push integer\n", lineNumber);
			free(point);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else if (strncmp(point->opcode, "pall", 4) == 0)
		point->f = &palli;
	else
	{
		printf("L<%d>: unknown instruction <%s>\n", lineNumber, point->opcode);
		free(point);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (point->f != NULL)
		point->f(stack, lineNumber);
	free(point);
	}
free(line);
}
void free_stack(stack_t ** stack)
{
	if (*stack == NULL)
		return;
	stack_t *curr = *stack;
	stack_t *prev = NULL;

	if (curr->prev == NULL)
	{
		free(curr);
		*stack = NULL;
		return;
	}
	while(curr != NULL)
	{
		prev = curr->prev;
		free(curr);
		curr = prev;
	}
	free(stack);
	stack = NULL;
}

void mallochandling()
{
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
