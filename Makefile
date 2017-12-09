# Makefile
 
CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -Werror -Wpedantic -W -std=c99 -O3 -g
LDFLAGS =
LDLIBS =
 
OBJ =  
DEP = ${OBJ:.o=.d}
 
all: 
 
: ${OBJ}
 
.PHONY: clean
 
clean:
	${RM} ${OBJ} ${DEP} 
 
-include ${DEP}
 
# END
