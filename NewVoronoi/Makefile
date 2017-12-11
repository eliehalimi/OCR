## Simple SDL mini code

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -Wpedantic -std=c99 -O0 -g -fsanitize=address
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image -fsanitize=address

OBJ= main.o struct.o
DEP= ${SRC:.o=.d}

all: main

main: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~ *.swp
	${RM} main

-include ${DEP}

# END
