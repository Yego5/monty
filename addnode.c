#include "monty.h"

/**
 * addnode - add node to the head of the stack
 * @stk: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **stk, int n)
{
	stack_t *new_node, *aux;

	aux = *stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *stk;
	new_node->prev = NULL;
	*stk = new_node;
}
