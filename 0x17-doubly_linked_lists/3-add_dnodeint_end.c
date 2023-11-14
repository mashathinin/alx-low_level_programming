#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of linked list
 * @head: a pointer to the linked list
 * @n: the new data for new node
 *
 * Return: (Success) a pointer to the newly added node
 * ------- (Fail) return NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *cursor;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->n = n;
		*head = new_node;
		return (new_node);
	}
	cursor = *head;
	while (cursor->next)
	{
		cursor = cursor->next;
	}
	new_node->prev = cursor;
	new_node->next = NULL;
	new_node->n = n;
	cursor->next = new_node;
	return (new_node);
}
