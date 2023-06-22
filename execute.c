#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stk: head linked list - stack
 * @l_nmb: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
int execute(char *content, stack_t **stk, unsigned int l_nmb, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opcode)
	{
		if (strcmp(opcode, opst[i].opcode) == 0)
		{
			opst[i].f(stk, l_nmb);
			return (0);
		}
		i++;
	}
	if (opcode && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_nmb, opcode);
		fclose(file);
		free(content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	return (1);
}
