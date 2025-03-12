#include "js.h" 
#include <stdlib.h>
#include <string.h>

int *createStack(size_t obj, size_t nums) {

	int *stk;
	stk = malloc(obj * nums);
	memset(stk, 0, obj * nums);
	return stk;	

}

int *push(int *stack, int *obj, size_t obj_size) {

	int inc;
	int *substack;
	inc = 0;
	substack = stack;
	while (*(stack + inc) != 0)	//FIND NEXT AVAILABLE SPOT
		inc++;
	if (*(stack + inc + 1) != 0)	//STACK FULL; MUST ALWAYS LEAVE ONE EMPTY SPOT TO SIGNIFY END OF ALLOCATED STACK
		return NULL;
	substack += inc;
	*substack = *obj;
	return stack;	

}

int pop(int *stack) {

	int inc, result, *iptr;
	inc = 0;
	while (*(stack + inc) != 0)
		inc++;
	iptr = stack + inc - 1;
	result = *iptr;
	*iptr = 0;	//REMOVE POPPED ELEMENT
	return result;

}
