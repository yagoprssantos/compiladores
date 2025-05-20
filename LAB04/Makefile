CC = gcc
CFLAGS = -Wall -Wextra -g -I./src

SRC_FILES = \
    src/compiler.c \
    src/lexer.c \
    src/parser.c \
    src/node.c \
    src/cprocess.c \
    src/lex_process.c \
    src/token.c \
    expressionable.c \
    src/helpers/vector.c \
    src/helpers/buffer.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test_precedence: test_precedence.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o test_precedence test_precedence.c $(OBJ_FILES)
	./test_precedence

clean:
	rm -f $(OBJ_FILES) test_precedence 