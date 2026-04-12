#ifndef OBJETO_H
#define OBJETO_H

#include <QPainter>
#include <QString>
#include <vector>
#include "Ponto.h"

class Objeto
{
public:
    QString nome;
    QString tipo;

    std::vector<Ponto> pontos;

    Objeto(QString nome, QString tipo);

    virtual void desenhar(QPainter &painter) = 0;
    virtual ~Objeto();

    void mover(float dx, float dy);

};

#endif // OBJETO_H
