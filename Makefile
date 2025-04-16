CC=gcc
AR=ar
SRC=src/main
DEPS=src/headers
LIBS=libs
SRS=$(SRC)/pilot.c
OBJ=jstack.o

pilot: $(SRS) $(LIBS)
	$(CC) -o $@ $< -I $(DEPS) -L $(LIBS) -ljstack
$(OBJ): $(SRC)/jstack.c
	$(CC) -c -o $@ $^ -I $(DEPS)
$(LIBS): $(OBJ)
	mkdir $@
	$(AR) rcs $@/libjstack.a $^
	rm -rf *.o
clean:
	rm -rf jstack
	rm -rf libs
