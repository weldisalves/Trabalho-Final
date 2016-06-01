#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <GL/glut.h>

enum tipoDirecao  {NORTE, SUL, LESTE, OESTE};

class Elemento {
      protected:
        float x;
        float y;
        float z;
        float largura;
        float altura;
        float theta;
        float deslocamento; 
        bool visivel;
        int linha;
        int coluna;
        tipoDirecao direcao;
      public:
        bool isVisivel();
        void setVisivel(bool);
        float getX();
        float getY();
        float getZ();
        float getAltura();
        float getLargura();
        float getTheta();
        float getDeslocamento();
        void setX(float);
        void setY(float);
        void setZ(float);
        void setDeslocamento(float);
        void setAltura(float);
        void setLargura(float);
        void setTheta(float);
        virtual void draw()=0;
        virtual void mover(tipoDirecao direcao, float incremento);
        
        void setDirecao(tipoDirecao);
        tipoDirecao getDirecao();       
                 
};
#endif
