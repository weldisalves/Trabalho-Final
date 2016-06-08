#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "Mapa.h"
#include "globals.h"
#include "Retangulo.h"
#include "tiny/tinystr.h"
#include "tiny/tinyxml.h"

using namespace std;

Mapa::Mapa(){
  
}

Mapa::~Mapa(){

}

void Mapa::loadFile(char* filename){
  TiXmlDocument doc;
    bool loaded = doc.LoadFile(filename);
    if (loaded){
        TiXmlElement* inputFiles = doc.FirstChildElement("svg")->FirstChildElement("g");
        TiXmlElement* rect = inputFiles->FirstChildElement("rect");
        Retangulo* aux;
        while(rect!=NULL){
            
            string w = rect->Attribute("width");
            string h = rect->Attribute("height");
            string x = rect->Attribute("x");
            string y = rect->Attribute("y");
            float width=atoi(w.c_str());
            float height=atoi(h.c_str());
            float x =(float)atof(x.c_str());
            float y =(float)atof(y.c_str());
            
            for(int i=x;i<x+largura;i++) //criando matriz de colisões do mapa
                for(int j=y;j<y+altura;j++)
                    matrizColisao[i][j]=1;

            aux = new Retangulo(x, y, height, width, 0.0,0.0,0.0);
            retangulos.push_back(aux);
            rect = rect->NextSiblingElement("rect");
        }
      }else{
        printf("ERRO AO ABRIR AQUIVO %s\n",filename );
      }

  for(int i=0;i<retangulos.size();i++){
    printf("%d\n",i);
    printf("Width = %f\n", retangulos[i]->getWidth() );
    printf("Height ='%f'\n", retangulos[i]->getHeight());
    printf("X ='%f'\n", retangulos[i]->getX());
    printf("Y ='%f'\n", retangulos[i]->getY());

  }

  printf("FIM DO ARQUIVO!!!!\n");
}

void Mapa::draw(){

  glPushMatrix();

    for(int i = 0;i<retangulos.size();i++){
      retangulos[i]->draw();      
    }

  glPopMatrix();

}

std::vector<Retangulo*> Mapa::getRetangulos(){
  return retangulos;
}