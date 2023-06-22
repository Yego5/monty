#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_mul(stack_t **stk, unsigned int l_nmb)
{
	stack_t *h;
	int stk_lngt = 0, rslt;

	h = *stk;
	while (h)
	{
		h = h->next;
		stk_lngt++;
	}
	if (stk_lngt < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	h = *stk;
	rslt = h->next->n * h->n;
	h->next->n = rslt;
	*stk = h->next;
	free(h);
}
