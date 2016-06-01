#include <iostream>
#include <vector>
#include <stdio.h>
#include "Elemento.h"

float Elemento::getX() {
    return this->x;   
}

float Elemento::getY() {
    return this->y;   
}

float Elemento::getZ() {
    return this->z;
}

float Elemento::getAltura() {
    return this->altura;   
}

float Elemento::getLargura() {
    return this->largura;   
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

void Elemento::setAltura(float valor) {
     this->altura = valor;     
}

void Elemento::setLargura(float valor) {
     this->largura = valor;     
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