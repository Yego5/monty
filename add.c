#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_add(stack_t **stk, unsigned int l_nmb)
{
	stack_t *current;
	int stk_length = 0, result;

	current = *stk;

	while (current)
	{
		current = current->next;
		stk_length++;
	}

	if (stk_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	current = *stk;

	result = current->n + current->next->n;
	current->next->n = result;
	*stk = current->next;
	free(current);
}
