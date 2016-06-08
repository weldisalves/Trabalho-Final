#ifndef Arma_H
#define Arma_H
#include "Elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Arma : public Elemento{
      public:
      	Arma();
      	Arma(float,float,float);
      	~Arma();
        virtual void draw();
        void atirar(float,float);   
      private:
      	float x,y,z;
                    
};
#endif
