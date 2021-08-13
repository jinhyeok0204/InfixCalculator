#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "infixToPostfix.h"
#include "PostCalculator.h"
#include "Calculator.h"

int EvalInfixExp(char exp[]) {
	int expLen = strlen(exp);
	char* copyExp = (char*)malloc(expLen+1);
	int result;

	strcpy_s(copyExp, expLen + 1, exp);

	ConvToRPNExp(copyExp); 
	result = EvalRPNExp(copyExp);

	free(copyExp);

	return result;
}