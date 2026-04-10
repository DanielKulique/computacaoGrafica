#include "Ponto.h"

Ponto::Ponto(float x, float y)
    : x(x), y(y){}

float Ponto::getX() const{
    return x;
}

float Ponto::getY() const {
    return y;
}

void Ponto::setX(float x){
    this->x = x;
}


void Ponto::setY(float y){
    this->y = y;
}

