#ifndef ARENA_H
#define ARENA_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

typedef struct {
      float x,y;
}Coordenada;

class Arena : public Elemento{
      public:
      	Arena();
      	Arena(float x, float y,float z);
      	~Arena();
            virtual void draw();   
            void load(char* filename);
      private:

            std::vector<Coordenada> walls;
                    
};
#endif
