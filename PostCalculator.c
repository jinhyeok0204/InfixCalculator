#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"


// 후위 표기법 계산하는 함수

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
			SPush(&stack, tok - '0'); //정수면 숫자로 변환 후 스택에 PUSH
		}
		else { //정수가 아닌 연산자라면..
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
	return SPop(&stack); //연산결과 반환
}