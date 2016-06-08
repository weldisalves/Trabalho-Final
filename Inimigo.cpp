#include <iostream>
#include <math.h>
#include "Inimigo.h"
#include "Elemento.h"
#include "Player.h"
Inimigo::Inimigo(){
	this->x=0;
	this->y=0;
	this->hp=0;
	this->ataque=0;
	this->defesa =0;
	this->deslocamento =0.1;
	// retangulo.setX(-30 + getX());
	// retangulo.setY(-30 + getY());
	// retangulo.setWidth(60);
	// retangulo.setHeight(60);
}

Inimigo::Inimigo(float x, float y,float deslocamento,float ataque,float hp){
	this->x=x;
	this->y=y;
	this->hp=hp;
	this->ataque=ataque;
	this->defesa = 100;
	this->deslocamento = deslocamento;
	this->theta = 0;
	// retangulo.setX(-30);
	// retangulo.setY(-30);
	// retangulo.setWidth(60);
	// retangulo.setHeight(60);
}

Inimigo::~Inimigo(){
	
}

void Inimigo::draw(){
	glPushMatrix();
		glTranslatef(this->x,this->y,0);
		glRotatef(this->theta,0,0,1);

		float x,w,y,h;

		x = retangulo.getX();
      	y = retangulo.getY();
      	w = retangulo.getWidth();
      	h = retangulo.getHeight();

	    glPushMatrix();
	    glBegin(GL_POLYGON);
	        glVertex3f(x,y,0);        
	        glVertex3f(x+w,y,0);        
	        glVertex3f(x+w,y+h,0);        
	    	glVertex3f(x,y+h,0);        
	    glEnd();
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
				glVertex3f(0,2,0);
				glVertex3f(0,-2,0);
				glVertex3f(20,-2,0);
				glVertex3f(20,2,0);
			glEnd();
		glPopMatrix();
			
		glPushMatrix();
			glColor3f(0,1,0);
			glBegin(GL_POLYGON);
				for(int i=0;i<100;i++){
					glVertex3f(10*cos(2*M_PI*i/100),10*sin(2*M_PI*i/100),1);
				}
			glEnd();
		glPopMatrix();
	glPopMatrix();
}
 
void Inimigo::idle(float x, float y, float time){
	if(getX() > x){
        setX(-getDeslocamento()*time);
    }else if(getX() < x){
        setX(getDeslocamento()*time);
    }

    if(getY() > y){
        setY(-getDeslocamento()*time);
    }else if(getY()< y){
        setY(getDeslocamento()*time);
    }
}

void Inimigo::setHp(float valor){
	this->hp += valor;
}

void Inimigo::setDefesa(float valor){
	this->defesa += valor;
}

void Inimigo::setTheta(float valor){
	this->theta = valor;
}