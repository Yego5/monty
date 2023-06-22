#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_pstr(stack_t **stk, unsigned int l_nmb)
{
	stack_t *current;
	(void)l_nmb;

	current = *stk;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
