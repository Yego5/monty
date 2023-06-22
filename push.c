#include "monty.h"

/**
 * f_push - add node to the stack
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_push(stack_t **stk, unsigned int l_nmb)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", l_nmb);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stk);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_nmb);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stk, n);
	else
		addqueue(stk, n);
}
