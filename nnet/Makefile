## Simple SDL mini code

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS=  -std=c99		#-Wall -Wextra -Werror -Wpedantic -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image

OBJ= test_function.o nnet_functions.o nnet_prototype.o
DEP= ${SRC:.o=.d}

all: test_function

test_function: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} test_function

-include ${DEP}

# END
