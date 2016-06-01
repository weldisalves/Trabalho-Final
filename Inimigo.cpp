#include <iostream>
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
}

Inimigo::~Inimigo(){
	
}

void Inimigo::draw(){
	glPushMatrix();
		glTranslatef(this->x,this->y,0);
		glBegin(GL_POLYGON);
			glVertex3f(0,0,0);
			glVertex3f(50,0,0);
			glVertex3f(50,50,0);
			glVertex3f(0,50,0);
		glEnd();
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