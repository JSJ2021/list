#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct List *next;
	int a;
} List;

List *NewNode(List * head)
{
	List* p = (List *)malloc(sizeof(List));
	p->next = head;
	head = p;
	return (head);
}

List* LastInsert(List* head, int num)
{
	List* p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = NULL;
	List* cur = head;
	
	if(cur)
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
	return (head);
}

List* Insert_first(List* head, int num)
{
	List* p = (List*)malloc(sizeof(List));
	p->a = num;
	p->next = head;
	head = p;
	return (head);
}

List* Delete_first(List* head)
{
	List* node;
	node = head->next;
	free(head);
	return (node);
}

List* Delete_last(List* head)
{
	List* node;
	node = head;
	while (node->next != NULL)
	{
		node = node->next;
	}
	free(node);
	return (head);
}

void printNode(List* head)
{
	List *node = head;
	while (node->next != NULL)
	{
		printf("%d\n", node->a);
		node = node->next;
	}
}

int main(void)
{
	List *head =NULL;
	//head = NewNode(head);
	for (int i = 10; i >= 0; i--)
	{
		head = Insert_first(head, i);
	}

	printNode(head);
	//head = Delete_first(head);
	//printNode(head);
	return (0);
}