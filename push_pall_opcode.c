#include "monty.h"

/**
 * push_func - handles push opcodes
 * @stack: head of stack data structure
 * @line_number: line number of instruction
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	bus_t *bus = &bus;
	int is_digit, str_len, big_number, push_num;

	(void)line_number;
	if (bus->arg)
	{
		str_len = strlen(bus->arg);
		is_digit = _isdigit(bus->arg);
		if (is_digit)
			push_num = atoi(bus->arg);
		big_number = push_num > (int)INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(bus->file);
			free(bus->content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		push(stack, push_num, bus->lifi);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(bus->file);
		free(bus->content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_func - handles pall opcodes
 * @stack: head of stack data structure
 * @line_number: line number of instruction
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	pall(*stack);
}

/**
 * push - performs push of values onto the stack
 * @head: head of stack data structure
 * @num: number to push to stack
 * @is_queue: switch between stack and queue modes
 */
void push(stack_t **head, int num, unsigned int is_queue)
{
	if (is_queue == 1)
		addqueue(head, num);
	else
		addnode(head, num);
}

/**
 * pall - performs pall operations
 * @head: head of stack data structure
 */
void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

