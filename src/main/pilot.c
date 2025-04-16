#include <stdio.h>
#include <stdlib.h>
#include "js.h"

int main(void) {

	float *f, fe = 10.2, foo = 1.2, five = 6.55;
	void *v;
	
	jstack_t *mystack = mkjstack(10, FLOAT);
	if (!jpush(mystack, &fe) || !jpush(mystack, &foo) || !jpush(mystack, &five)) {
		perror("stack push err");
		return 1;
	}
	if ((v = jpop(mystack)) == NULL) {
		fprintf(stderr, "%s\n", "Stack is empty.");
		return 1;
	}
	f = (float *) v;
	printf("f = %.2f\n", *f);
	free(v);
	freejstack(mystack);
	return 0;

}
