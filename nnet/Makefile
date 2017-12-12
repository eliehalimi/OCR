## Makefile for nnet_training

CC=gcc

CPPFLAGS=
CFLAGS=-fsanitize=address -Wall -Wextra -Werror -std=c99 -O0 -g3
LDFLAGS= 
LDLIBS= -fsanitize=address -lm 

OBJ= nnet_training.o nnet_work.o nnet_init.o nnet_functions.o ../save/save_file.o

DEP= ${SRC:.o=.d}

all: nnet_training

nnet_training: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} *~
	${RM} nnet_training

-include ${DEP}

# END
