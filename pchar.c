#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_pchar(stack_t **stk, unsigned int l_nmb)
{
	stack_t *current;

	current = *stk;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}

