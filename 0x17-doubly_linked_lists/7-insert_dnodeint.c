#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node in a given index
 * @head: a pointer to linked list
 * @index: the given position
 * @n: the integer data
 *
 * Return: (Success) a pointer to the newly added node
 * ------- (Fail) return NULL
 */
dlistint_t
*insert_dnodeint_at_index(dlistint_t **head, unsigned int index, int n)
{
	dlistint_t *cursor;
	dlistint_t *new_node;
	unsigned int count = 1;

	if (index == 0)
	{
		new_node = add_dnodeint(head, n);
		return (new_node);
	}
	cursor = (*head)->next;
	while (cursor)
	{
		if (index == count)
		{
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
			{
				return (NULL);
			}
			new_node->n = n;
			new_node->prev = cursor->prev;
			new_node->next = cursor;
			cursor->prev->next = new_node;
			cursor->prev = new_node;
			return (new_node);
		}
		count++;
		cursor = cursor->next;
	}
	if (count == index)
	{
		new_node = add_dnodeint_end(head, n);
		return (new_node);
	}
	return (NULL);
}
