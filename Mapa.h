#ifndef Mapa_H
#define Mapa_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Elemento.h"
#include "Retangulo.h"
#include "Rectangle.h"

class Mapa : public Elemento{
      public:
      	Mapa();
      	~Mapa();
        virtual void draw();
        void loadFile(char* filename);
        std::vector<Rectangle*> getRetangulos();
        int matrizColisao [3000][3000];   
      private:
      	std::vector<Rectangle*> retangulos;      	
                    
};
#endif
