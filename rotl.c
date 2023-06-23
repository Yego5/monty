#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tm = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	aux = (*head)->next;
	aux->prev = NULL;

	while (tm->next != NULL)
	{
		tm = tm->next;
	}

	tm->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tm;
	(*head) = aux;
}
