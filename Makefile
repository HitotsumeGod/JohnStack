CC=gcc
AR=ar
SRC=src/main
DEPS=src/headers
LIBS=libs
OBJ=jstack.o
WERRS=-Wall -Werror -Wextra

$(LIBS): $(OBJ)
	mkdir $@
	$(AR) rcs $@/libjstack.a $^
	rm -rf *.o
$(OBJ): $(SRC)/jstack.c
	$(CC) -c $(WERRS) -o $@ $^ -I $(DEPS)
clean:
	rm -rf pilot
	rm -rf libs
