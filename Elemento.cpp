#include <iostream>
#include <vector>
#include <stdio.h>
#include "Elemento.h"
#include "Retangulo.h"

float Elemento::getX() {
    return this->x;   
}

float Elemento::getY() {
    return this->y;   
}

float Elemento::getZ() {
    return this->z;
}

float Elemento::getHeight() {
    return this->height;   
}

float Elemento::getWidth() {
    return this->width;   
}

float Elemento::getDeslocamento(){
    return this->deslocamento;
}

float Elemento::getTheta(){
    return this->theta;
}

void Elemento::setX(float valor) {
     this->x += valor;     
}

void Elemento::setY(float valor) {
     this->y += valor;     
}

void Elemento::setZ(float valor) {
    this->z += valor;
}

void Elemento::setTheta(float valor){
    this->theta += valor;
}

void Elemento::setDeslocamento(float valor){
    this->deslocamento=valor;
}

void Elemento::setHeight(float valor) {
     this->height = valor;     
}

void Elemento::setWidth(float valor) {
     this->width = valor;     
}

void Elemento::setVisivel(bool valor) {
     this->visivel = valor;     
}

bool Elemento::isVisivel() {
     return this->visivel;     
}

void Elemento::mover(tipoDirecao direcao, float incremento) {
     
     switch (direcao) {
        case LESTE:
             setX(getX() + incremento);
             break;
        case OESTE:
             setX(getX() - incremento);
             break;
        case NORTE:
             setY(getY() + incremento);
             break;
        case SUL:
             setY(getY() - incremento);
             break;       
     }   
     setDirecao(direcao);  
}

tipoDirecao Elemento::getDirecao() {
     return this->direcao;            
}

void Elemento::setDirecao(tipoDirecao tipo) {
    this->direcao = tipo;     
}
