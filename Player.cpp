#include <iostream>
#include <math.h>
#include "globals.h"
#include "Player.h"
#include "Elemento.h"
#include "ReadOBJ.h"
#include "Poder.h"

Player::Player(){
	this->x=0;
	this->y=0;
}
Player::Player(float x, float y){
	this->x=x;
	this->y=y;

}

Player::~Player(){
		
}

void Player::draw(){

	glPushMatrix();
		glTranslatef(this->x,this->y,0);
		glRotatef(this->theta,0,0,1);

		glPushMatrix();
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
