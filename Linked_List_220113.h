// 수정 22. 01. 13
#pragma once
#include <stdio.h>
#include <stdlib.h>

struct _NODE {
	struct _NODE* next;
	int data;
	int count;
};

int Count = 0;

void print_Node(struct _NODE* Node);
void First_index_insert_Node(struct _NODE* Node, int data);
void First_index_delete_Node(struct _NODE* Node);
void select_number_delete_node(struct _NODE* Node, int data);
