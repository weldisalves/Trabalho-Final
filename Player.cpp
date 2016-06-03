#include <iostream>
#include <math.h>
#include <vector>
#include "globals.h"
#include "Player.h"
#include "Elemento.h"
#include "ReadOBJ.h"
#include "Poder.h"
#include "Bala.h"

Player::Player(){
	this->x=0;
	this->y=0;
	quadrado.x=-30;
	quadrado.y=-30;
	quadrado.width = 60;
	quadrado.height = 60;
}

Player::~Player(){
		
}

void Player::draw(){

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
			glColor3f(0,1,1);
			glBegin(GL_POLYGON);
				for(int i=0;i<100;i++){
					glVertex3f(30*cos(2*M_PI*i/100),30*sin(2*M_PI*i/100),1);
				}
			glEnd();
		glPopMatrix();
	glPopMatrix();
}

std::vector<Bala> Player::getBalas(){
	return balas;
}

void Player::carregaMunicao(){
	
	for(int i = 0;i< 10000 ;i++){
		Bala aux;
		balas.push_back(aux);
	}
}