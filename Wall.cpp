#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "globals.h"
#include "Elemento.h"
#include "Wall.h"

Wall::Wall(){
	
}
Wall::Wall(float x, float y, float z){
	this->x=x;
	this->y=y;
  this->z=z;
}

Wall::~Wall(){
		
}

void Wall::draw(){
  glPushMatrix();
    glTranslatef(this->x,this->y,this->z);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        glVertex3f(100,100,0);
        glVertex3f(0,100,0);
    glEnd();
  glPopMatrix();
}