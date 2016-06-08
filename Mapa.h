#ifndef Mapa_H
#define Mapa_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Elemento.h"
#include "Retangulo.h"

class Mapa : public Elemento{
      public:
      	Mapa();
      	~Mapa();
        virtual void draw();
        void loadFile(char* filename);
        std::vector<Retangulo*> getRetangulos();   
      private:
      	std::vector<Retangulo*> retangulos;
                    
};
#endif
