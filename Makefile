CC=g++
CCFLAGS= -Wall
EXEC=./exec

MOVE_DIR=Classes/Move
PLAYER_DIR=Classes/Player

all: main.o move.o player.o
	$(CC) $(CCFLAGS) main.cc $(MOVE_DIR)/Move.cc $(PLAYER_DIR)/Player.cc $(PLAYER_DIR)/ATK/PlayerATK.cc $(PLAYER_DIR)/DEF/PlayerDEF.cc $(PLAYER_DIR)/GK/PlayerGK.cc -o $(EXEC)

player.o: $(PLAYER_DIR)/Player.o $(PLAYER_DIR)/ATK/PlayerATK.o $(PLAYER_DIR)/DEF/PlayerDEF.o $(PLAYER_DIR)/GK/PlayerGK.o 
move.o: $(MOVE_DIR)/Move.o

run: 
	$(EXEC)

clean: 
	find . -name "*.o" -type f -delete
	rm $(EXEC)