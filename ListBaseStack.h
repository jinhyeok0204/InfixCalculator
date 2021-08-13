#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _liststack {
	Node* head;
}ListStack;

typedef ListStack Stack;

void SInit(Stack* stack);
void SPush(Stack* stack, Data data);

int isEmpty(Stack* stack);

Data SPop(Stack* stack);
Data SPeek(Stack* stack);

#endif // !__LIST_BASE_STACK_H__
