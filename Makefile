.PHONY: all
all: test

test:
	$(CC) test.c argparser.c

lib:
	$(CC) -shared -undefined dynamic_lookup -o argparser.so argparser.c
