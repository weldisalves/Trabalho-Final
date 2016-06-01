#ifndef AWALL_H
#define WALL_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Wall : public Elemento{
      public:
      	Wall();
      	Wall(float x, float y,float z);
      	~Wall();
        virtual void draw();   
      private:
      	float x,y,z;
                    
};
#endif
