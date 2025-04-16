#ifndef __JS_H__
#define __JS_H__

#include <stddef.h>
#include <stdbool.h>

typedef enum JDatatype {
	CHAR,
	INT,
	FLOAT,
	BOOLEAN,
	SHORT,
	LONG,
	DOUBLE,
	STRING
} JDatatype;

typedef struct jstack_t {
	void *stack;
	size_t data_size;
	int next_free;
	int max;
} jstack_t;

extern jstack_t *mkjstack(size_t stack_size, JDatatype d);
extern void freejstack(jstack_t *stack);
extern bool jpush(jstack_t *stack, void *object);

/*
JSTACK POP FUNCTION. RETURNS THE TOP OF THE PASSED JSTACK IN ACCORDANCE WITH LIFO. IT IS THE RESPONSIBILITY OF THE IMPLEMENTER TO CAST THE RETURNED OBJECT TO WHATEVER TYPE THEY DESIRE BEFORE DEREFERENCING.
*/
extern void *jpop(jstack_t *jstack);
extern bool iss_full(jstack_t *stack);	
extern bool iss_empty(jstack_t *stack);	

#endif //__JS_H__
