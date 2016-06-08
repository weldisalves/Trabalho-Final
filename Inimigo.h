#ifndef INIMIGO_H
#define INIMIGO_H
#include "Elemento.h"
#include "Player.h"
class Inimigo : public Elemento{
      public:
      	Inimigo();
      	Inimigo(float,float,float,float,float);
      	~Inimigo();
            virtual void draw();
            void idle(float,float,float);
            void setHp(float);
            void setDefesa(float);
            void setTheta(float);
            Retangulo getRetangulo();
            
      private:
             float hp;
             float ataque;
             float defesa;
             Retangulo retangulo;
                   
};
#endif
