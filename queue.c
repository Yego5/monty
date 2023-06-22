#include "monty.h"

/**
 * f_queue - sets the stack mode to queue (add elements to the tail).
 * @stk: stack head
 * @l_nmb: line_number
 * Return: no return
 */
void f_queue(stack_t **stk, unsigned int l_nmb)
{
	(void)stk;
	(void)l_nmb;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail of the stack.
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
