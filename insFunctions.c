#include"monty.h"
/**
 * pushi - final version of push
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void pushi(stack_t **stack, unsigned int line_number)
{
		push(stack, pushVal);
	line_number = line_number;
}
/**
 * palli - final version of push
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void palli(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	pall(stack);
}
/**
 * pinti - prints the top
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void pinti(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * popi - prints the top
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void popi(stack_t **stack, unsigned int line_number)
{
	stack_t *rempved = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	rempved = *stack;
	(*stack) = (*stack)->prev;
	free(rempved);
}
