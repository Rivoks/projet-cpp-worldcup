CXX=g++
CXXFLAGS= -g -std=c++11 -Wall -pedantic
EXEC=./exec

MOVE_DIR=Classes/Move
PLAYER_DIR=Classes/Player
ACTION_DIR=Classes/Action
TEAM_DIR=Classes/Team

all: main.o team.o action.o move.o player.o
	$(CXX) $(CXXFLAGS) main.cc $(ACTION_DIR)/Action.cc $(MOVE_DIR)/Move.cc $(TEAM_DIR)/Team.cc $(PLAYER_DIR)/Player.cc $(PLAYER_DIR)/ATK/PlayerATK.cc $(PLAYER_DIR)/DEF/PlayerDEF.cc $(PLAYER_DIR)/GK/PlayerGK.cc -o $(EXEC)

team.o: $(TEAM_DIR)/Team.o
player.o: $(PLAYER_DIR)/Player.o $(PLAYER_DIR)/ATK/PlayerATK.o $(PLAYER_DIR)/DEF/PlayerDEF.o $(PLAYER_DIR)/GK/PlayerGK.o 
action.o: $(ACTION_DIR)/Action.o
move.o: $(MOVE_DIR)/Move.o

run: 
	$(EXEC)

clean: 
	find . -name "*.o" -type f -delete
	rm $(EXEC)