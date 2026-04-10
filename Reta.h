#ifndef RETA_H
#define RETA_H

#include "Objeto.h"

    class Reta : public Objeto
{
public:
    Reta(QString nome, Ponto p1, Ponto p2);

    void desenhar(QPainter &painter) override;

    ~Reta() override = default;
};

#endif
