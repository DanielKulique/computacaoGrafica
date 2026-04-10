#ifndef POLIGONO_H
#define POLIGONO_H

#include "Objeto.h"

class Poligono : public Objeto
{
public:
    Poligono(QString nome, std::vector<Ponto> pts);
    void desenhar(QPainter &painter) override;
    ~Poligono() override = default;

private:
    void desenharSegmento(QPainter &painter, Ponto a, Ponto b);
};


#endif // POLIGONO_H
