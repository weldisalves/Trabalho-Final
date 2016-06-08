#ifndef PLAYER_H
#define PLAYER_H
#include "Elemento.h"
#include "Retangulo.h"

class Player : public Elemento{
      public:
      	Player();
      	~Player();
        virtual void draw();        
        float getHp();
        Retangulo getRetangulo();

      private:
            float hp;
            float ataque;
            float defesa;
            Retangulo retangulo;
};
#endif
