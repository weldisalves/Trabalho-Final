#include "Rectangle.h" 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Construtor
Rectangle::Rectangle()
{
}

// Criar um retangulo dado x, y, height e width
Rectangle::Rectangle(int x, int y, int pHeight, int pWidth,int R,int G,int B)
{
	
	this->x = x;
	this->y = y;
	this->Height = pHeight;
	this->Width = pWidth;
	this->R = R;
	this->G = G;
	this->B = B;
}
void Rectangle::Set(int x, int y, int pHeight, int pWidth,int R,int G,int B)
{
	this->x = x;
	this->y = y;
	this->Height = pHeight;
	this->Width = pWidth;
	this->R = R;
	this->G = G;
	this->B = B;
}

// Destrutor
Rectangle::~Rectangle()
{
}

// Desenhar um retangulo - a ser implementado
void Rectangle::Draw()
{
	glColor3ub(R,G,B);
	glBegin(GL_POLYGON);
    glBegin(GL_LINE_STRIP);
	glVertex3f(x,y, 0);
	glVertex3f(x,y+(Height), 0);
	glVertex3f(x+(Width),y+(Height), 0);
	glVertex3f(x+(Width),y, 0);
	glEnd();
}
