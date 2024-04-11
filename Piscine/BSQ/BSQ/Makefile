OBJS	= checkups.o find_square.o helpers.o helpers2.o main.o map.o maxima_map.o read.o read_std_input.o test.o
SOURCE	= checkups.c find_square.c helpers.c helpers2.c main.c map.c maxima_map.c read.c read_std_input.c test.c
HEADER	= headers.h
NAME	= bsq
CC	 = gcc
FLAGS	 = -Wall -Werror -Wextra -c

bsq:	$(OBJS)
	$(CC) -o bsq $(OBJS)

all: $(OBJS)
	$(CC) -o $(OBJS) -o $(NAME) $(FLAGS)

checkups.o: checkups.c
	$(CC) $(FLAGS) checkups.c 

find_square.o: find_square.c
	$(CC) $(FLAGS) find_square.c 

helpers.o: helpers.c
	$(CC) $(FLAGS) helpers.c 

helpers2.o: helpers2.c
	$(CC) $(FLAGS) helpers2.c 

main.o: main.c
	$(CC) $(FLAGS) main.c 

map.o: map.c
	$(CC) $(FLAGS) map.c 

maxima_map.o: maxima_map.c
	$(CC) $(FLAGS) maxima_map.c 

read.o: read.c
	$(CC) $(FLAGS) read.c 

read_std_input.o: read_std_input.c
	$(CC) $(FLAGS) read_std_input.c 

test.o: test.c
	$(CC) $(FLAGS) test.c 


clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

run: $(NAME)
	./$(NAME)

debug: $(NAME)
	valgrind $(NAME)
