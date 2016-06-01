#include <iostream>
#include <math.h>
#include "globals.h"
#include "Poder.h"
#include "Elemento.h"
#include "ReadOBJ.h"

Poder::Poder(){
	this->x=0;
	this->y=0;
}
Poder::Poder(float x, float y){
	this->x=x;
	this->y=y;
}

Poder::~Poder(){
		
}

void Poder::draw(){

glPushMatrix();
	glColor3f(1,1,0);
	glTranslatef(this->x,this->y,0);
			
	glPushMatrix();
        glColor3f(0,1,1);
        glBegin(GL_POLYGON);
            for(int i=0;i<10;i++){
                glVertex3f(10*cos(2*M_PI*i/10),10*sin(2*M_PI*i/10),1);
            }
        glEnd();
    glPopMatrix();

glPopMatrix();
}