#include "monty.h"

/**
 * f_pint - prints the top element of the stack.
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_pint(stack_t **stk, unsigned int l_nmb)
{
	if (*stk == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stk)->n);
}
