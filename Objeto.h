#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <vector>
#include <QColor>
#include "Ponto.h"
#include <QPainter>

class Objeto {
public:
    QString nome;
    QString tipo;
    std::vector<Ponto> pontos;

    QColor minhaCor;
    int minhaEspessura;

    Objeto(QString nome, QString tipo);
    virtual void desenhar(QPainter &painter) = 0;
    void mover(float dx, float dy);
    virtual ~Objeto();
};

#endif
