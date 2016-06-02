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
}

Inimigo::Inimigo(float x, float y,float deslocamento,float ataque,float hp){
	this->x=x;
	this->y=y;
	this->hp=hp;
	this->ataque=ataque;
	this->defesa = 100;
	this->deslocamento = deslocamento;
	this->theta = 0;
}

Inimigo::~Inimigo(){
	
}

void Inimigo::draw(){
	glPushMatrix();
		glTranslatef(this->x,this->y,0);
		glRotatef(this->theta,0,0,1);

		float x,x1,y,y1;

		x = quadrado.x;
      	y = quadrado.y;
      	x1 = quadrado.width;
      	y1 = quadrado.height;

	    glPushMatrix();
	    glBegin(GL_POLYGON);
	        glVertex3f(x,y,0);        
	        glVertex3f(x+x1,y,0);        
	        glVertex3f(x+x1,y+y1,0);        
	    	glVertex3f(x,y+y1,0);        
	    glEnd();
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
				glVertex3f(0,5,0);
				glVertex3f(0,-5,0);
				glVertex3f(50,-5,0);
				glVertex3f(50,5,0);
			glEnd();
		glPopMatrix();
			
		glPushMatrix();
			glColor3f(1,1,0);
			glBegin(GL_POLYGON);
				for(int i=0;i<100;i++){
					glVertex3f(30*cos(2*M_PI*i/100),30*sin(2*M_PI*i/100),1);
				}
			glEnd();
		glPopMatrix();
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