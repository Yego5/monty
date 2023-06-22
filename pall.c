#include "monty.h"

/**
 * f_pall - prints the stack
 * @stk: stack head
 * @ctr: not used
 * Return: no return
 */
void f_pall(stack_t **stk, unsigned int ctr)
{
	stack_t *current;
	(void)ctr;

	current = *stk;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
