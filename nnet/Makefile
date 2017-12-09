## Simple SDL mini code

CC=gcc

CPPFLAGS= #`pkg-config --cflags sdl` -MMD
CFLAGS=  -Wall -Wextra -Werror -std=c99 -O0 -g
LDFLAGS=
LDLIBS= -lm #`pkg-config --libs sdl` -lSDL_image

OBJ= test.o nnet_init.o nnet_functions.o

DEP= ${SRC:.o=.d}

all: test

test: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} test

-include ${DEP}

# END
