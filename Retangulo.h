#ifndef Retangulo_h
#define Retangulo_h
#include <GL/glut.h>
#include <string>
#include "Elemento.h"

class Retangulo : public Elemento{
      public:
       
        float R,G,B;
        //std::string style;
        Retangulo();
        Retangulo(float x, float y, float height, float width,float R,float G,float B);
        void set(float x, float y, float height, float width,float R,float G,float B);
        ~Retangulo();
        void draw();                 
};
#endif
