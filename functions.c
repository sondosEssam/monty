#include"monty.h"
int pushVal = 0;
void push (stack_t **stack, int value)
{
	stack_t *new_node = NULL;
	if (stack == NULL)
		return;
	new_node = malloc(sizeof(stack_t));
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
	stack_t *curr = *stack;
	if (*stack == NULL)
		return;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
int _isspace(char *line)
{
	int i = 0;

	while(line[i] != '\0')
	{
		if(line[i] != ' ')
			return (0);
		i++;
		if(line[i] == '\n')
			break;
	}
	return (1);
}
int checkfordigits(char *word)
{
	int i = 0;

	while((word[i]) != '\0')
	{
		if((word[i] < 48 || word[i] > 57) && word[i] != '-')
		{
			return (-1);
		}
		i++;
		if(word[i] == '\n')
			break;
	}
	return (1);
}
