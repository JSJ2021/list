#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct List *next;
	int a;
} List;

void LastInsert(List** head, int num)
{
	List* p;

	p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = 0;
	if (*head == 0 || !p) {
		*head = p;
		return;
	}
	List* cur = *head;
	while (cur->next != 0)
	{
		cur = cur->next;
	}
	cur->next = p;
}

void Insert_first(List** head, int num)
{
	List*	p;

	p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = *head;
	*head = p;
}

void Delete_first(List** head)
{
	List*	node;

	node = (*head)->next;
	free(*head);
	*head = node;
}

void Delete_last(List** head)
{
	List*	node;
	List*	pre;

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

void methodNode(List* head, void (*f)(List *))
{
	List*	node;
	
	node = head;
	while (node != 0)
	{
		f(node);
		node = node->next;
	}
}

void print(List *node)
{
	printf("%d\n", node->a);
}

int main(void)
{
	List*	head;

	head = 0;
	for (int i = 10; i >= 0; i--)
	{
		LastInsert(&head, i);
	}
	methodNode(head, print);
	Delete_first(&head);
	Delete_first(&head);
	Delete_first(&head);
	Delete_last(&head);
	Delete_last(&head);

	methodNode(head, print);
	return (0);
}