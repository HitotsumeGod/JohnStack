#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "js.h"

jstack_t *mkjstack(size_t stack_size, JDatatype d) {

	jstack_t *js;
	
	if ((js = malloc(sizeof(jstack_t))) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	switch (d) {
	case CHAR:
		if ((js -> stack = malloc((js -> data_size = sizeof(char)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case INT:
		if ((js -> stack = malloc((js -> data_size = sizeof(int)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case FLOAT:
		if ((js -> stack = malloc((js -> data_size = sizeof(float)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case BOOLEAN:
		if ((js -> stack = malloc((js -> data_size = sizeof(bool)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case SHORT:
		if ((js -> stack = malloc((js -> data_size = sizeof(short)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case LONG:
		if ((js -> stack = malloc((js -> data_size = sizeof(long)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case DOUBLE:
		if ((js -> stack = malloc((js -> data_size = sizeof(double)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	case STRING:
		if ((js -> stack = malloc((js -> data_size = sizeof(char *)) * stack_size)) == NULL) {
			perror("malloc err");
			exit(EXIT_FAILURE);
		}
		break;
	default:
		fprintf(stderr, "%s\n", "Improper datatype submitted. Consult the JohnStack header file for documentation on the JDatatype enum.");
		exit(EXIT_FAILURE);
	}
	js -> next_free = 0;
	js -> max = stack_size;
	return js;

}

void freejstack(jstack_t *js) {

	free(js -> stack);
	free(js);

}

bool jpush(jstack_t *js, void *v) {

	if (iss_full(js))
		return false;
	if (memcpy(js -> stack + (js -> next_free)++, v, js -> data_size) == NULL) {
		perror("memcpy failure");
		exit(EXIT_FAILURE);
	}
	return true; 

}

void *jpop(jstack_t *js) {

	void *popped;

	if (iss_empty(js))
		return NULL;
	if ((popped = malloc(js -> data_size)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	if (memcpy(popped, js -> stack + (js -> next_free) - 1, js -> data_size) == NULL) {
		perror("memcpy failure");
		exit(EXIT_FAILURE);
	}
	memset(js -> stack + ((js -> next_free)--) - 1, 0, js -> data_size);
	return popped;

}

bool iss_full(jstack_t *js) {

	return js -> next_free == js -> max + 1;

}

bool iss_empty(jstack_t *js) {

	return js -> next_free == 0;

}
