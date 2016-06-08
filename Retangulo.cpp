#include "Retangulo.h"
#include "Elemento.h" 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>

Retangulo::Retangulo(){
}

Retangulo::Retangulo(float x, float y, float height, float width,float R,float G,float B){
	
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->R = R;
	this->G = G;
	this->B = B;
}

void Retangulo::set(float x, float y, float height, float width,float R,float G,float B){
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->R = R;
	this->G = G;
	this->B = B;
}

Retangulo::~Retangulo(){
}


void Retangulo::draw(){
	glColor3ub(R,G,B);
	glBegin(GL_POLYGON);
    glBegin(GL_LINE_STRIP);
	glVertex3f(x,y, 0);
	glVertex3f(x,y+(height), 0);
	glVertex3f(x+(width),y+(height), 0);
	glVertex3f(x+(width),y, 0);
	glEnd();
}
