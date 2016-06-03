#ifndef Bala_H
#define Bala_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Bala : public Elemento{
      public:
      	Bala();
      	Bala(float,float,float);
      	~Bala();
        virtual void draw();
        void atirar(float,float);   
      private:
      	float x,y,z;
                    
};
#endif
