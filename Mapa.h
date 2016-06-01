#ifndef Mapa_H
#define Mapa_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

typedef struct{
	float x,y;
	float height,width;
	
}Objeto;

class Mapa : public Elemento{
      public:
      	Mapa();
      	~Mapa();
        virtual void draw();
        void loadFile(char* filename);
        std::vector<Objeto> getObjetos();   
      private:
      	std::vector<Objeto> objetos;
                    
};
#endif
