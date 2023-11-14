#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes node at a given index
 * @head: a pointer to the linked list
 * @index: the given index
 *
 * Return: (Success) return 1
 * ------- (Fail) return -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cursor;
	unsigned int count = 1;

	if (!head)
	{
		return (-1);
	}
	cursor = *head;
	if (index == 0)
	{
		if (!cursor)
		{
			return (-1);
		}
		*head = cursor->next;
		if (*head)
		{
			(*head)->prev = NULL;
		}
		free(cursor);
		return (1);
	}
	while (cursor)
	{
		if ((count - 1) == index)
		{
			if (cursor->next)
			{
				cursor->prev->next = cursor->next;
				cursor->next->prev = cursor->prev;
			}
			else
				cursor->prev->next = NULL;
			free(cursor);
			return (1);
		}
		count++;
		cursor = cursor->next;
	}
	return (-1);
}
