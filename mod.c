#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_mod(stack_t **stk, unsigned int l_nmb)
{
	stack_t *current;
	int stk_lngt = 0, rslt;

	current = *stk;
	while (current)
	{
		current = current->next;
		stk_lngt++;
	}

	if (stk_lngt < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	current = *stk;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	rslt = current->next->n % current->n;
	current->next->n = rslt;
	*stk = current->next;
	free(current);
}
