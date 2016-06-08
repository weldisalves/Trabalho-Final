#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "Mapa.h"
#include "globals.h"
#include "Retangulo.h"
#include "tinyxml.h"
#include "Rectangle.h"

using namespace std;

Mapa::Mapa(){
  
}

Mapa::~Mapa(){

}

void Mapa::loadFile(char* filename){

  TiXmlDocument doc;
    bool loaded = doc.LoadFile(filename);
    if (loaded)
    {
        TiXmlElement* inputFiles = doc.FirstChildElement("svg")->FirstChildElement("g");
        TiXmlElement* rect = inputFiles->FirstChildElement("rect");
        Rectangle* aux;
        while(rect!=NULL){
            
            string w = rect->Attribute("width");
            string h = rect->Attribute("height");
            string x = rect->Attribute("x");
            string y = rect->Attribute("y");
            int largura=atoi(w.c_str());
            int altura=atoi(h.c_str());
            int xlido =(int)atof(x.c_str());
            int ylido =(int)atof(y.c_str());
            
            for(int i=xlido;i<xlido+largura;i++) //criando matriz de colisões do mapa
                for(int j=ylido;j<ylido+altura;j++)
                    matrizColisao[i][j]=1;

            aux = new Rectangle(xlido, ylido, altura, largura, 0,0,0);
            retangulos.push_back(aux);
            rect = rect->NextSiblingElement("rect");
        }
      }
  
  for(float i=0;i<retangulos.size();i++){
    printf("%d\n",i);
    printf("Width = %f\n", retangulos[i]->Width);
    printf("Height ='%f'\n", retangulos[i]->Height);
    printf("X ='%f'\n", retangulos[i]->x);
    printf("Y ='%f'\n", retangulos[i]->y);

  }

  printf("FIM DO ARQUIVO!!!!\n");
}

void Mapa::draw(){

  glPushMatrix();

    for(float i = 0;i<retangulos.size();i++){
      retangulos[i]->Draw();      
    }

  glPopMatrix();

}

std::vector<Rectangle*> Mapa::getRetangulos(){
  return retangulos;
}