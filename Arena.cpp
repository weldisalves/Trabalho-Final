#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "globals.h"
#include "Elemento.h"
#include "Arena.h"
#include "Wall.h"

Wall *auxWall = NULL;

Arena::Arena(){
	
}
Arena::Arena(float x, float y, float z){
	this->x=x;
	this->y=y;
  this->z=z;
}

Arena::~Arena(){
		
}

void Arena::load(char* filename){
  int i=0;
  float x=0,y=0;
  FILE* file = fopen(filename,"r");

  if(!file){
    printf("ERRO AO ABRIR AQUIVO %s\n",filename );
    exit(0);
  }

  while( 1 ){

    char ch = fgetc(file);
    if (ch == EOF)break;

    Coordenada aux;

    switch(ch){
      case 'W':
        aux.x=x;
        aux.y=y;
        walls.push_back(aux);
        break;
      case '\n':
        x++;
        y=0;
      default: break;
    }
    y++;
  }
 

  fclose(file);
}


void Arena::draw(){
  
  for(int i=0;i<walls.size();i++){
  auxWall = new Wall();  
  //   auxWall->setX(100*walls[i].x/100*2*WINDOW_WIDTH);
  //   auxWall->setY(100*walls[i].y/100*2*WINDOW_HEIGHT);
  //   auxWall->setZ(0);
  //   auxWall->draw();
  // }
  glPushMatrix();
      glTranslatef(100*walls[i].x/100*2*WINDOW_WIDTH,100*walls[i].y/100*2*WINDOW_HEIGHT,this->z);
      glColor3f(0,0,0);
      glBegin(GL_POLYGON);
          glVertex3f(0,0,0);
          glVertex3f(100,0,0);
          glVertex3f(100,100,0);
          glVertex3f(0,100,0);
      glEnd();
    glPopMatrix();
  }
  
}