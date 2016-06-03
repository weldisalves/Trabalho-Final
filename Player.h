#ifndef PLAYER_H
#define PLAYER_H
#include "Elemento.h"
#include "ReadOBJ.h"
#include "Bala.h"

class Player : public Elemento{
      public:
      	Player();
      	~Player();
            virtual void draw();
            float getHp();
            std::vector<Bala> getBalas();
            void carregaMunicao();
      private:
            float hp;
            float ataque;
            float defesa;
            std::vector<Bala> balas;
};
#endif
