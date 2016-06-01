#ifndef PODER_H
#define PODER_H
#include "Elemento.h"
#include "ReadOBJ.h"
class Poder : public Elemento{
      public:
      	Poder();
      	Poder(float x, float y);
      	~Poder();
            virtual void draw();
            float getHp();   
      private:
            float ataque;
            float deslocamento;
            ReadOBJ* obj=NULL;        
};
#endif
