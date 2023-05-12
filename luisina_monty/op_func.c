#include "monty.h"

/**
 * is_digit - iterates to check of isdigit
 * @n: integer
 * Return: 0 if is num, -1 if not
 */
int is_digit(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * push - adds node to the start of stack
 * @head: head of linked list
 * @line_counter: numebr of line
 * @n: integer
 */
void push(stack_t **head, unsigned int line_counter, const char *n)
{
	if (!head)
		return;
	if (is_digit(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_counter);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_dnodeint(head, atoi(n)) == -1)
		{
			free_dlist(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pop - removes node of stack
 * @head: head of dlinkedlist
 * @line_counter: number of line
 */
void pop(stack_t **head, unsigned int line_counter)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_counter);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
		delete_node(head);
}

/**
 * swap - swap locations of two lasts nodes of stack
 * @head: node to be swapped
 * @line_counter: number of line
 */
void swap(stack_t **head, unsigned int line_counter)
{
	stack_t *aux = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_counter);
		exit(EXIT_FAILURE);
	}
	aux = (*head)->next;
	if (aux->next != NULL)
	{
		(*head)->next = aux->next;
		(*head)->next->prev = *head;
	}
	else
	{
		aux->prev->prev = aux;
		aux->prev->next = NULL;
	}
	aux->prev = NULL;
	aux->next = *head;
	(*head) = aux;
}

