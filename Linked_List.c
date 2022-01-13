//First Try
#include <stdio.h>
#include <stdlib.h>

struct _NODE{
	struct _NODE* next;
	int data;
	int count;
};

void print_Node(struct _NODE *head) {
	struct _NODE* cur = head->next;

	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void insert_Node(struct _NODE* Target, int data) {
	struct _NODE* newNode = malloc(sizeof(struct _NODE));
	newNode->next = Target->next;
	newNode->data = data;

	Target->next = newNode;
}

void delete_Node(struct _NODE* Target) {
	struct _NODE* Del_Node = Target->next;
	Target->next = Del_Node->next;
	
	free(Del_Node);
}

void select_del_node(struct _NODE* Target, int data) {
	struct _NODE *cur = Target->next;
	struct _NODE *old = malloc(sizeof(struct _NODE));

	while (cur != NULL) {
		if (cur->data == data) {
			old->next = cur->next;
			free(cur);
			cur = old->next;
		}
		else {
			old = cur;
			cur = cur->next;
		}
	}	
}

int main(){
	struct _NODE* head = malloc(sizeof(struct _NODE));

	head->next = NULL;

	insert_Node(head, 2);
	insert_Node(head, 2);
	insert_Node(head, 3);
	insert_Node(head, 2);
	insert_Node(head, 100);

	print_Node(head);

	select_del_node(head, 2);

	print_Node(head);

	return 0;
}
