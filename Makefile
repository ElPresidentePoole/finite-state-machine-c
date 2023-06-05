HEADERS = fsm_state.h
CC = gcc

default: main

fsm_state.o: fsm_state.c $(HEADERS)
	$(CC) -c fsm_state.c -o fsm_state.o -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror -Wpedantic

main.o: fsm_state.o main.c $(HEADERS)
	$(CC) -c main.c -o main.o -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror -Wpedantic

main: main.o 
	$(CC) main.o fsm_state.o -o main -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror -Wpedantic

clean:
	-rm -f main.o
	-rm -f main
