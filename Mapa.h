#ifndef Mapa_H
#define Mapa_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Mapa : public Elemento{
      public:
      	Mapa();
      	~Mapa();
        virtual void draw();
        void loadFile(char* filename);
        std::vector<Quadrado> getObjetos();   
      private:
      	std::vector<Quadrado> objetos;
                    
};
#endif
