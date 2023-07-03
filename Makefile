CC = gcc
CCFLAGS = -Wall -Werror -lm -g
OUTPUT = skillmaster
SRCDIR =

all: skillmaster


skillmaster: ${SRCDIR}main.c ${SRCDIR}skillmaster.h
	${CC} ${SRCDIR}main.c -o ${OUTPUT} ${CCFLAGS}

clean:
	rm skillmaster *.o
