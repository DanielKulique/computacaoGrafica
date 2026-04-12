#include "Objeto.h"

Objeto::Objeto(QString nome, QString tipo) : nome(nome), tipo(tipo) {

}

void Objeto::mover(float dx, float dy){
    for(auto &p : pontos){
        p.setX(p.getX() + dx);
        p.setY(p.getY() + dy);
    }
};

Objeto::~Objeto(){

}
