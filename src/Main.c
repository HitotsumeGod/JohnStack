#include "js.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) { 

	int *stack;
	int fif = 15;
	int sif = 16;
	if ((stack = createStack(sizeof(*stack), 50)) == NULL) {
		perror("cStack err");
		exit(EXIT_FAILURE);
	}
	if ((stack = push(stack, &fif, sizeof fif)) == NULL || (stack = push(stack, &sif, sizeof sif)) == NULL) {
		perror("push err");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 2; i++)
		printf("%d\n", pop(stack));
	free(stack);
	return 0;

}
