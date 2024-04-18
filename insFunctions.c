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
/**
 * swapi - swaps the top two elemtns
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void swapi(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->prev->n;
	(*stack)->prev->n = (*stack)->n;
	(*stack)->n = n;
}
/**
 * addi - swaps the top two elemtns
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void addi(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *repmove = NULL;

	line_number = line_number;
	sum = (*stack)->prev->n + (*stack)->n;
	repmove = (*stack);
	(*stack) = (*stack)->prev;
	(*stack)->n = sum;
	free(repmove);
}
/**
 * nop - no operaion
 * @stack: container where data is stored
 * @line_number: line number inside the byte code file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	*stack = *stack;
}
