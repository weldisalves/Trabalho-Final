#include <iostream>
#include <math.h>
#include <vector>
#include "globals.h"
#include "Player.h"
#include "Elemento.h"
#include "Retangulo.h"

Player::Player(){
	this->x=0;
	this->y=0;
	retangulo.setX(-10);
	retangulo.setY(-10);
	retangulo.setWidth(20);
	retangulo.setHeight(20);
}

Player::~Player(){
		
}

void Player::draw(){

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
			glColor3f(0,1,1);
			glBegin(GL_POLYGON);
				for(int i=0;i<100;i++){
					glVertex3f(10*cos(2*M_PI*i/100),10*sin(2*M_PI*i/100),1);
				}
			glEnd();
		glPopMatrix();
	glPopMatrix();
}

Retangulo Player::getRetangulo(){
	return this->retangulo;
}