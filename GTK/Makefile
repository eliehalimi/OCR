## Simple SDL mini code

CC=gcc

CPPFLAGS=
CFLAGS= -Wall -Wextra -Werror -std=c99 -O0 -g
LDFLAGS= 
LDLIBS= '--libs gtk+-2.0'

OBJ= main.o

DEP= ${SRC:.o=.d}

all: main

test: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} main

-include ${DEP}

# END
