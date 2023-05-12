#include "monty.h"

/**
 * pall - print all nodes in dlinkedlist
 * @head: head of list
 * @line_counter: number of line
 */
void pall(stack_t **head, unsigned int line_counter)
{
	stack_t *aux = NULL;

	if (!head || !*head)
		return;

	(void) line_counter;
	aux = *head;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pint - print first node in dlinkedlist
 * @head: head of list
 * @line_counter: number of line
 */
void pint(stack_t **head, unsigned int line_counter)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _add - adds the lasts two ints in dlinkedlist
 * @head: head of list
 * @line_counter: number of line
 */
void _add(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * nop - do nothing
 * @head: head of list
 * @line_counter: number of line
 */
void nop(stack_t **head, unsigned int line_counter)
{
	(void) head;
	(void) line_counter;
}

