#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @stk: head of the stack
 */
void free_stack(stack_t *stk)
{
	stack_t *aux;

	aux = stk;
	while (stk)
	{
		aux = stk->next;
		free(stk);
		stk = aux;
	}
}
