#ifndef _FJ_H_
#define _FJ_H_

#include <stddef.h>

extern int *createStack(size_t size, size_t num);	//SIZE OF OBJECTS, NUMBER OF OBJECTS
extern int *push(int *stk, int *vptr, size_t ptr_size);
extern int pop(int *stk);

#endif //_FJ_H_
