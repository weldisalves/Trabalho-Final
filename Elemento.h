#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <GL/glut.h>

enum tipoDirecao  {NORTE, SUL, LESTE, OESTE};

class Elemento {
      protected:
        float x;
        float y;
        float z;
        float theta;
        float deslocamento; 
        float width;
        float height;
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
        float getTheta();
        float getDeslocamento();
        float getHeight();
        float getWidth();
        void setX(float);
        void setY(float);
        void setZ(float);
        void setDeslocamento(float);
        void setTheta(float);
        void setHeight(float);
        void setWidth(float);
        virtual void draw()=0;
        virtual void mover(tipoDirecao direcao, float incremento);        
        void setDirecao(tipoDirecao);
        tipoDirecao getDirecao();           
                 
};
#endif
