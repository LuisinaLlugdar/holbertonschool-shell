#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of the list.
 * @head: head of the list
 * @n: integer to be stored in the new node
 * Return: 0 on success, -1 if failed
 */
int add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (-1);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (0);
}

/**
 * delete_node - deletes node at end
 * @head: head of the list
 */
void delete_node(stack_t **head)
{
	stack_t *aux = NULL;

	aux = *head;
	if (aux->next == NULL)
	{
		*head = NULL;
		free(aux);
	}
	else
	{
		*head = aux->next;
		(*head)->prev = NULL;
		free(aux);
	}
}

/**
 * free_dlist - frees a doubly linked list
 * @head: pointer to head of list
 */
void free_dlist(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
