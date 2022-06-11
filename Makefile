INSTALL ?= install
PREFIX ?= /usr/local
LIBDIR = $(PREFIX)/lib
INCLUDEDIR = $(PREFIX)/include
CFLAGS = -Wall -pedantic -Werror -Wextra

libstring_functions.so: libstring_functions.o
	gcc -shared -o libstring_functions.so *.o

libstring_functions.o:
	gcc $(CFLAGS) -fPIC -c *.c

install:
	sudo $(INSTALL) -D libstring_functions.h $(INCLUDEDIR)/libstring_functions.h
	sudo $(INSTALL) -D libstring_functions.so $(LIBDIR)/libstring_functions.so

uninstall:
	rm $(INCLUDEDIR)/libstring_functions.h
	rm $(LIBDIR)/libstring_functions.so

clean:
	rm *.o
