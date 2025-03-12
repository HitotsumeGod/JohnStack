#include "js.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) { 

	int i, permi;
	char *stack, *ap;
	size_t ssize;
	i = 0;
	ap = "Hello Kaylee!";
	ssize = 50;
	if ((stack = createStack(sizeof(*stack), ssize)) == NULL) {
		perror("cStack err");
		exit(EXIT_FAILURE);
	}
	while (*(ap + i) != '\0')
		i++;
	permi = i - 1;
	while (i >= 0) {
		if (*(ap + i) != '\0') 
			push(stack, ap + i, sizeof(char));
		i--;
	}
	while (i < permi) {
		printf("%c\n", pop(stack));
		i++;
	}
	free(stack);
	return 0;

}
