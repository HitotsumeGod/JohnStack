CC=gcc
AR=ar
SRC=src/main
DEPS=src/headers
LIBS=libs
SRS=$(SRC)/jstack.c
INSTPATH=/usr/local/lib

static: $(SRS) $(LIBS)
	$(CC) -c -Wall -Werror -Wextra -o $(LIBS)/jstack.o $< -I $(DEPS)
	$(AR) -rcs $(LIBS)/libjstack.a $(LIBS)/jstack.o
	rm -rf $(LIBS)/*.o
shared: $(SRS) $(LIBS)
	$(CC) -c -Wall -Werror -Wextra -fpic -o $(LIBS)/jstack.o $< -I $(DEPS)
	$(CC) -shared -o $(LIBS)/libjstack.so $(LIBS)/jstack.o 
	rm -rf $(LIBS)/*.o
install:
	if [ -f $(LIBS)/libjstack.a ]; then 		\
		cp $(LIBS)/libjstack.a $(INSTPATH);	\
	fi
	if [ -f $(LIBS)/libjstack.so ]; then		\
		cp $(LIBS)/libjstack.so $(INSTPATH); 	\
	fi
uninstall:
	if [ -f $(INSTPATH)/libjstack.a ]; then 	\
		rm $(INSTPATH)/libjstack.a;		\
	fi
	if [ -f $(INSTPATH)/libjstack.so ]; then	\
		rm $(INSTPATH)/libjstack.so;		\
	fi
$(LIBS):
	if ! [ -d $@ ]; then				\
		mkdir $@; 				\
	fi
clean:
	rm -rf libs
