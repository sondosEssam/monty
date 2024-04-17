#include"monty.h"
void pushi(stack_t **stack, unsigned int line_number)
{
	if (isdigit(pushVal))
		push(stack, pushVal);
	else
	{
		printf("L<%d>: usage: push integer\n", line_number);
	}
}
void palli(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	pall(stack);
}
