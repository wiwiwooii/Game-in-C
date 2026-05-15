SOURCES = attack.c bitboards.c board.c data.c evaluate.c hashkey.c init.c io.c makemove.c misc.c movegen.c perft.c polybook.c polykeys.c pvtable.c
OBJECTS = $(SOURCES:.c=.obj)

all:
	gcc $(SRCS) -o $(NAME) -pthread -O2 -Wall -Wextra