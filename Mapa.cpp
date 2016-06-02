#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "Mapa.h"
#include "globals.h"

using namespace std;

Mapa::Mapa(){
  
}

Mapa::~Mapa(){

}

void Mapa::loadFile(char* filename){
  FILE* file = fopen(filename,"r");

  if(!file){
    printf("ERRO AO ABRIR AQUIVO %s\n",filename );
    exit(0);
  }

  while( 1 ){

    char lineHeader[128];
    int res = fscanf(file, "%s", lineHeader);
    if (res == EOF)
      break;

    if ( strcmp( lineHeader, "width" ) == 0 ){
      Quadrado aux;
      fscanf(file, " ='%f'\n", &aux.width);
      fscanf(file, "height ='%f'\n", &aux.height);
      fscanf(file, "x ='%f'\n", &aux.x);
      fscanf(file, "y ='%f'\n", &aux.y);
      aux.y -= 1050;
      objetos.push_back(aux);
    }
  }

  for(int i=1;i<objetos.size();i++){
    printf("%d\n",i);
    printf("Width = %f\n", objetos[i].width );
    printf("Height ='%f'\n", objetos[i].height);
    printf("X ='%f'\n", objetos[i].x);
    printf("Y ='%f'\n", objetos[i].y);

  }

  printf("FIM DO ARQUIVO!!!!\n");

  fclose(file);

}

void Mapa::draw(){

  float x,x1,y,y1;

  glPushMatrix();
    
    glColor3f(0,0,0);

    for(int i = 1;i<objetos.size();i++){

      x = objetos[i].x;
      y = objetos[i].y;
      x1 = objetos[i].width;
      y1 = objetos[i].height;

      glBegin(GL_POLYGON);
        glVertex3f(x,y,0);        
        glVertex3f(x+x1,y,0);        
        glVertex3f(x+x1,y+y1,0);        
        glVertex3f(x,y+y1,0);        
      glEnd();
    }

  glPopMatrix();

}

std::vector<Quadrado> Mapa::getObjetos(){
  return objetos;
}