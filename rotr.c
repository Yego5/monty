#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @stk: stack head
 * @ctr: line_number (unused)
 * Return: no return
 */
void f_rotr(stack_t **stk, __attribute__((unused)) unsigned int ctr)
{
	stack_t *copy;

	copy = *stk;
	if (*stk == NULL || (*stk)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stk;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stk)->prev = copy;
	(*stk) = copy;
}
