#include "push_swap.h"

void	last_insert(List** head, int num)
{
	List* p;

	p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = 0;
	if (*head == 0 || !p)
	{
		*head = p;
		return;
	}
	List* cur = *head;
	while (cur->next != 0)
		cur = cur->next;
	cur->next = p;
}

void	insert_first(List** head, int num)
{
	List* p;

	p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = *head;
	*head = p;
}

void	delete_first(List** head)
{
	List* node;

	node = (*head)->next;
	free(*head);
	*head = node;
}

void	delete_last(List** head)
{
	List* node;
	List* pre;

	pre = 0;
	node = *head;
	while (node->next != 0)
	{
		pre = node;
		node = node->next;
	}
	if (pre == 0)
	{
		free(node);
		node = 0;
	}
	else
	{
		free(node);
		pre->next = 0;
	}
}

void	delete_all(List** head)
{
	while (*head != 0)
		delete_first(head);
}

void	method_node(List* head, void (*f)(List*))
{
	List* node;

	node = head;
	while (node != 0)
	{
		f(node);
		node = node->next;
	}
}

void	print(List* node)
{
	printf("%d\n", node->a);
}

int	swap(List** head)
{
	int	i1;
	int	i2;

	if ((*head) == 0 || (*head)->next == 0)
		return (0);
	i1 = (*head)->a;
	delete_first(head);
	i2 = (*head)->a;
	delete_first(head);
	insert_first(head, i1);
	insert_first(head, i2);
	return (1);
}

int	ss(List** head, List** head2)
{
	if (((*head) == 0 || (*head)->next == 0) || ((*head) == 0 || (*head)->next == 0))
		return (0);
	return (swap(head) && swap(head2));
}

int	pusha(List** head, List** head2)
{
	int	i;

	if ((*head2) == 0 || (*head2)->next == 0)
		return (0);
	i = (*head2)->a;
	delete_first(head2);
	insert_first(head, i);
	return (1);
}

int	pushb(List** head, List** head2)
{
	int	i;

	if ((*head) == 0 || (*head)->next == 0)
		return (0);
	i = (*head)->a;
	delete_first(head);
	insert_first(head2, i);
	return (1);
}

int	rotate(List** head)
{
	int	i;

	if (*head == 0 || (*head)->next == 0)
	{
		return (0);
	}
	i = (*head)->a;
	delete_first(head);
	last_insert(head, i);
	return (1);
}

int	revrotate(List** head)
{
	int	i;

	if (*head == 0 || (*head)->next == 0)
	{
		return (0);
	}
	i = (*head)->a;
	delete_last(head);
	insert_first(head, i);
	return (1);
}