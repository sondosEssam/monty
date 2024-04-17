#include"monty.h"
/**
 * mainPart - basiclly the main fubciton
 * @point: instructions pointer
 * @stack: container where data is stored
 * @op: bytecode file
 * Return: void
*/
void mainPart(instruction_t *point, stack_t **stack, FILE *op)
{
	char *word = NULL, line[1024];
	int lineNumber = 0, casse = 0, meh = 0;

	while (fgets(line, sizeof(line), op) != NULL)
	{
		lineNumber++;
		if (_isspace(line) == 1 || strlen(line) == 1)
			continue;
	word = strtok(line, " ");
	meh = strlen(word) - 1;
	(word[meh] == '\n') ? (word[meh] = '\0') : (word[meh] = word[meh]);
	point = malloc(sizeof(instruction_t));
	if (point == NULL)
		mallochandling();
	point->opcode = word;
	if (strcmp(point->opcode, "push") == 0)
	{
		word = strtok(NULL, " ");
		if (checkfordigits(word) != -1 && strcmp(word, "\n") != 0)
		{
			pushVal = atoi(word);
			point->f = &pushi;
		}
		else
			handleWrongPush(point, stack, lineNumber, casse = 1, op);
	}
	else if (strncmp(point->opcode, "pall", 4) == 0)
		point->f = &palli;
	else if (strcmp(point->opcode, "pint") == 0)
		point->f = &pinti;
	else if (strcmp(point->opcode, "pop") == 0)
		point->f = &popi;
		else handleWrongPush(point, stack, lineNumber, casse = 2, op);
	if (point->f != NULL)
		point->f(stack, lineNumber);
	free(point);
	}
}
/**
 * free_stack - free stack elemnts
 * @stack: container where data is stored
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *prev = NULL;

	if (*stack == NULL)
		return;
	if (curr->prev == NULL)
	{
		free(curr);
		*stack = NULL;
		free(stack);
		return;
	}
	while (curr != NULL)
	{
		prev = curr->prev;
		free(curr);
		curr = prev;
	}
	free(stack);
	stack = NULL;
}
/**
 * mallochandling - handle malloc return
 * Return: void
 */
void mallochandling(void)
{
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * handleWrongPush - basiclly the main fubciton
 * @p: instructions pointer
 * @s: container where data is stored
 * @N: bytecode file
 * @c: case of the handleing
 * @o: file to open
 * Return: void
 */
void handleWrongPush(instruction_t *p, stack_t **s, int N, int c, FILE *o)
{
	if (c == 1)
		fprintf(stderr, "L%d: usage: push integer\n", N);
	else if (c == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", N, p->opcode);
	free(p);
	free_stack(s);
	fclose(o);
	exit(EXIT_FAILURE);
}
