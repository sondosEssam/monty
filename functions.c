#include"monty.h"
int pushVal = 0;
void push (stack_t **stack, int value)
{
	if (stack == NULL)
		return;
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		mallochandling();
	new_node->n = value;
	(*stack == NULL) ? (new_node->prev = NULL) : (new_node->prev = *stack);
	new_node->next = NULL;
		(*stack) = new_node;
	return;
}
void pall (stack_t ** stack)
{
	if (*stack == NULL)
		return;
stack_t *curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
stack_t *getTail(stack_t ** stack)
{
	stack_t *curr = *stack;
	if (*stack == NULL)
		return (NULL);
	while(curr->next != NULL && curr != NULL)
		curr = curr->next;
	return (curr);
}
int countLines(FILE *file)
{
	int lineCount = 0;
	char *line = NULL;
	size_t bufferSize = 0;

	while (getline(&line, &bufferSize, file) != -1)
	{
		lineCount++;
	}
	free(line);
	return (lineCount);
}
int checkfordigits(char *word)
{
	int i = 0;

	while((word[i]) != '\0')
	{
		if(!isdigit(word[i]))
			return (-1);
		i++;
	}
	return (1);
}
