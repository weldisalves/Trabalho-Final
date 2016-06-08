#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "globals.h"
#include "Elemento.h"
#include "Arma.h"

Arma::Arma(){
  this->x = 2000;
  this->x = 2000;
	
}
Arma::Arma(float x, float y, float z){
	this->x=x;
	this->y=y;
  this->z=z;
}

Arma::~Arma(){
		
}

void Arma::draw(){
  glPushMatrix();
    glTranslatef(this->x,this->y,this->z);
    glRotatef(this->theta,0,0,1);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
      for(int i=0;i<100;i++){
        glVertex3f(10*cos(2*M_PI*i/100),10*sin(2*M_PI*i/100),1);
      }
    glEnd();
  glPopMatrix();
}

void Arma::atirar(float theta, float time){
  setX(cos(getTheta()*M_PI/180 )*time);
  setY(sin(getTheta()*M_PI/180 )*time);
}