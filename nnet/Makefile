## Simple SDL mini code

CC=gcc

CPPFLAGS=
CFLAGS= -Wall -Wextra -Werror -std=c99 -O0 -g -fsanitize=address
LDFLAGS=
LDLIBS= -lm -fsanitize=address

OBJ= test.o nnet_init.o nnet_functions.o

DEP= ${SRC:.o=.d}

all: test

test: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} test

-include ${DEP}

# END
