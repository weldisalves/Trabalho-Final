CC=g++
OPT=-lGL -lGLU -lglut -lm
COMPILE=$(OPT) -cpp
LINK=$(OPT) -o
APP=main
TINY=tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp

SRC=main.cpp Inimigo.cpp Elemento.cpp Player.cpp ReadOBJ.cpp Mapa.cpp Retangulo.cpp Rectangle.cpp $(TINY)

all: run
	
run: $(APP)
	./$(APP)

$(APP) : 
	$(CC) $(SRC) $(LINK) $(APP)

rebuild: clean all

clean:
	rm -rf *.o