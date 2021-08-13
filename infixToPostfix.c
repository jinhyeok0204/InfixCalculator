#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"ListBaseStack.h"
#include"infixToPostfix.h"


// 중위 표기법 -> 후위 표기법	


int GetOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) return 1;
	else if (op1Prec == op2Prec) return 0;
	else return -1;
}

void ConvToRPNExp(char exp[]) {
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen+1);
	int i, idx=0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * (expLen + 1)); //할당된 배열은 0으로 초기화
	SInit(&stack);
	
	for (i = 0; i < expLen; i++) {
		tok = exp[i];

		if (isdigit(tok)) {
			convExp[idx++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(') break;
					convExp[idx++] = popOp;
				}
				break;

			case '*': case '-':
			case '+': case '/':
				while (!isEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;
			}
		}
	}
	while (!isEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp,expLen+1 , convExp);
	free(convExp);
}