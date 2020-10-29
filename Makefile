CC = gcc
CCFLAGS = -Wall -Werror -fsanitize=address

test: checkResults.c
	$(CC) $(CCFLAGS) -o test checkResults.c

clean:
	rm -f test
