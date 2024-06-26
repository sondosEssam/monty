#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int pushVal;
void pushi(stack_t **stack, unsigned int line_number);
void palli(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int value);
void pall(stack_t **stack);
stack_t *getTail(stack_t **stack);
int checkfordigits(char *word);
void mainPart(instruction_t *point, stack_t **stack, FILE *op);
void free_inst(instruction_t **point);
void free_stack(stack_t **stack);
void mallochandling();
int _isspace(char *line);
void handleWrongPush(instruction_t *p, stack_t **s, int N, int c, FILE *o);
void pinti(stack_t **stack, unsigned int line_number);
void popi(stack_t **stack, unsigned int line_number);
void swapi(stack_t **stack, unsigned int line_number);
void addi(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
