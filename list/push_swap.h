#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct List* next;
	int a;
} List;

void	last_insert(List** head, int num);
void	insert_first(List** head, int num);
void	delete_first(List** head);
void	delete_last(List** head);
void	delete_all(List** head);
void	method_node(List* head, void (*f)(List*));
void	print(List* node);
int	swap(List** head);
int	ss(List** head, List** head2);
int	pusha(List** head, List** head2);
int	pushb(List** head, List** head2);
int	rotate(List** head);
int	revrotate(List** head);

#endif