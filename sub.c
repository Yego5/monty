#include "monty.h"

/**
 * f_sub - performs subtraction of the top two elements of the stack.
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_sub(stack_t **stk, unsigned int l_nmb)
{
	stack_t *aux;
	int sus, nodes;

	aux = *stk;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	aux = *stk;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stk = aux->next;
	free(aux);
}
