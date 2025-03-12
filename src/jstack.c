#include "js.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *createStack(size_t obj, size_t nums) {

	char *stk;
	if ((stk = malloc(obj * nums)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	memset(stk, STACK_SYM, obj * nums);
	if (*stk != STACK_SYM) {
		perror("memset err");
		exit(EXIT_FAILURE);
	}
	return stk;	

}

char *push(char *stack, char *obj, size_t obj_size) {

	int inc;
	char *substack;
	inc = 0;
	substack = stack;
	while (*(stack + inc) != STACK_SYM)	//FIND NEXT AVAILABLE SPOT
		inc++;
	if (*(stack + inc + 1) != STACK_SYM)	//STACK FULL; MUST ALWAYS LEAVE ONE EMPTY SPOT TO SIGNIFY END OF ALLOCATED STACK
		return NULL;
	substack += inc;
	*substack = *obj;
	return stack;	

}

char pop(char* stack) {

	int inc; 
	char result, *iptr;
	inc = 0;
	while (*(stack + inc) != STACK_SYM)
		inc++;
	iptr = stack + inc - 1;
	result = *iptr;
	*iptr = STACK_SYM;	//REMOVE POPPED ELEMENT
	return result;

}
