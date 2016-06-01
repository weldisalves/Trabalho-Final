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
      Objeto aux;
      fscanf(file, " ='%f'\n", &aux.width);
      fscanf(file, "height ='%f'\n", &aux.height);
      fscanf(file, "x ='%f'\n", &aux.x);
      fscanf(file, "y ='%f'\n", &aux.y);
      objetos.push_back(aux);

      // printf("Width = %f\n", aux.width );
      // printf("Height ='%f'\n", aux.height);
      // printf("X ='%f'\n", aux.x);
      // printf("Y ='%f'\n", aux.y);
    }
  }

  printf("FIM DO ARQUIVO!!!!\n");

  fclose(file);

  for(int i=0;i<objetos.size();i++){
    printf("test\n");
    printf("Width = %f\n", objetos[i].width );
    printf("Height ='%f'\n", objetos[i].height);
    printf("X ='%f'\n", objetos[i].x);
    printf("Y ='%f'\n", objetos[i].y);

  }

}

void Mapa::draw(){
  glPushMatrix();
    glColor3f(0,0,0);

    // glBegin(GL_POLYGON);
    //   glVertex3f(objetos[0].x -WINDOW_WIDTH ,objetos[0].y,0);        
    //   glVertex3f(objetos[0].x+objetos[0].width -WINDOW_WIDTH,objetos[0].y,0);
    //   glVertex3f(objetos[0].x+objetos[0].width -WINDOW_WIDTH,objetos[0].y+objetos[0].height,0);
    //   glVertex3f(objetos[0].x -WINDOW_WIDTH,objetos[0].y+objetos[0].height,0);
    // glEnd();

    for(int i = 0;i<objetos.size();i++){
      glBegin(GL_POLYGON);
      for(int j=i+0;j<i+4;j++){
        glVertex3f(objetos[j].x,objetos[j].y,0);        
        glVertex3f(objetos[j].x+objetos[i].width,objetos[j].y,0);
        glVertex3f(objetos[j].x+objetos[i].width,objetos[j].y-objetos[j].height,0);
        glVertex3f(objetos[j].x,objetos[j].y-objetos[j].height,0);
      }
      glEnd();
    }

  glPopMatrix();

  
}

std::vector<Objeto> Mapa::getObjetos(){
  return objetos;
}