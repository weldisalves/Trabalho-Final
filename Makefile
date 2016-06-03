CC=g++
OPT=-lGL -lGLU -lglut -lm
COMPILE=$(OPT) -cpp
LINK=$(OPT) -o
APP=main

SRC=main.cpp Inimigo.cpp Elemento.cpp Player.cpp ReadOBJ.cpp Arena.cpp Wall.cpp Poder.cpp Mapa.cpp Bala.cpp

all: run
	
run: $(APP)
	./$(APP)

$(APP) : 
	$(CC) $(SRC) $(LINK) $(APP)

rebuild: clean all

clean:
	rm -rf *.o