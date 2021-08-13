#include<stdio.h>
#include<stdlib.h>
#include"ListBaseStack.h"

void SInit(Stack* stack) {
	stack->head = NULL;
}
void SPush(Stack* stack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = stack->head;
	stack->head = newNode;
}

int isEmpty(Stack* stack) {
	if (stack->head == NULL) return TRUE;
	else return FALSE;
}

Data SPop(Stack* stack) {
	Node* rPos;
	Data rData;

	if (isEmpty(stack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rPos = stack->head;
	rData = rPos->data;
	
	stack->head = stack->head->next;
	free(rPos);
	return rData;
}
Data SPeek(Stack* stack) {

	if (isEmpty(stack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return stack->head->data;
}