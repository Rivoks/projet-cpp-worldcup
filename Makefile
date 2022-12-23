CC=g++
CCFLAGS= -Wall
EXEC=./exec

MOVE_DIR=Classes/Player/Move
PLAYER_DIR=Classes/Player

all: main.o move.o player.o
	$(CC) $(CCFLAGS) main.cc $(MOVE_DIR)/Move.cc $(PLAYER_DIR)/Player.cc $(PLAYER_DIR)/ATK/PlayerATK.cc -o $(EXEC)

player.o: $(PLAYER_DIR)/Player.o $(PLAYER_DIR)/ATK/PlayerATK.o
move.o: $(MOVE_DIR)/Move.o

run: 
	$(EXEC)

clean: 
	find . -name "*.o" -type f -delete
	rm $(EXEC)