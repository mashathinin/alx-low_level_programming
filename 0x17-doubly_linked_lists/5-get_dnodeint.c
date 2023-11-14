#include "lists.h"

/**
 * get_dnodeint_at_index - return the nth node of linked list
 * @head: a pointer to the linked list
 * @index: the given index
 *
 * Return: (Success) a pointer to the nth node
 * ------- (Fail) return NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cursor;
	unsigned int count = 0;

	cursor = head;
	while (cursor)
	{
		if (count == index)
			return (cursor);
		count++;
		cursor = cursor->next;
	}
	return (NULL);
}
