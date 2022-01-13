// 수정 22. 01. 13 

#include "Main.h"

int main(){
	struct _NODE* head = malloc(sizeof(struct _NODE));

	head->next = NULL;

	First_index_insert_Node(head, 2);
	First_index_insert_Node(head, 2);
	First_index_insert_Node(head, 3);
	First_index_insert_Node(head, 2);
	First_index_insert_Node(head, 100);

	print_Node(head);

	First_index_delete_Node(head);

	print_Node(head);

	select_number_delete_node(head, 2);

	print_Node(head);

	return 0;
}

void print_Node(struct _NODE* Node) {
	struct _NODE* cur = Node->next;

	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void First_index_insert_Node(struct _NODE* Node, int data) {
	struct _NODE* newNode = malloc(sizeof(struct _NODE));

	newNode->next = Node->next;
	newNode->data = data;
	newNode->count = ++Count;

	Node->next = newNode;
}

void First_index_delete_Node(struct _NODE* Node) {
	struct _NODE* Del_Node = Node->next;
	Node->next = Del_Node->next;

	free(Del_Node);
}

void select_number_delete_node(struct _NODE* Node, int data) {
	struct _NODE* cur = Node->next;
	struct _NODE* temp = malloc(sizeof(struct _NODE));

	while (cur != NULL) {
		if (cur->data == data) {
			if (Node->next->count == cur->count)
			{
				temp = cur->next;
				free(cur);
				cur = Node->next = temp;
			}
			else {
				temp->next = cur->next;
				free(cur);
				cur = temp->next;
			}
		}
		else {
			temp = cur;
			cur = cur->next;
		}
	}
}
