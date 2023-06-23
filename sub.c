#include "monty.h"
/**
  * f_sub - subtraction
  * @head: stack head
  * @counter: line_number
  * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *ux;
	int sus, nodes;

	ux = *head;
	for (nodes = 0; ux != NULL; nodes++)
		ux = ux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ux = *head;
	sus = ux->next->n - ux->n;
	ux->next->n = sus;
	*head = ux->next;
	free(ux);
}
