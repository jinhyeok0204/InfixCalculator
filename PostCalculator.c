#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"


// ���� ǥ��� ����ϴ� �Լ�

int EvalRPNExp(char exp[]) {
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok;

	int op1, op2;
	SInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];

		if (isdigit(tok)) {
			SPush(&stack, tok - '0'); //������ ���ڷ� ��ȯ �� ���ÿ� PUSH
		}
		else { //������ �ƴ� �����ڶ��..
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok) {
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack); //������ ��ȯ
}