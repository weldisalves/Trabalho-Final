#ifndef PLAYER_H
#define PLAYER_H
#include "Elemento.h"
#include "ReadOBJ.h"

class Player : public Elemento{
      public:
      	Player();
      	~Player();
            virtual void draw();
            float getHp();
      private:
            float hp;
            float ataque;
            float defesa;
};
#endif
