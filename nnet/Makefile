## Simple SDL mini code

CC=gcc

CPPFLAGS=
CFLAGS= -fsanitize=address -Wall -Wextra -Werror -std=c99 -O0 -g
LDFLAGS=
LDLIBS= -lm -lasan 

OBJ= test.o nnet_init.o nnet_functions.o

DEP= ${SRC:.o=.d}

all: test

test: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} test

-include ${DEP}

# END
