#ifndef _FJ_H_
#define _FJ_H_

#include <stddef.h>

#define STACK_SYM 9

extern char *createStack(size_t size, size_t num);	//SIZE OF OBJECTS, NUMBER OF OBJECTS
extern char *push(char *stk, char *vptr, size_t ptr_size);
extern char pop(char *stk);

#endif //_FJ_H_
