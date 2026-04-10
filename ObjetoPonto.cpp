#include "ObjetoPonto.h"
#include <cmath>

ObjetoPonto::ObjetoPonto(QString nome, Ponto p)
    : Objeto(nome, "ponto")
{
    pontos.push_back(p);
}

void ObjetoPonto::desenhar(QPainter &painter)
{
    painter.drawPoint(round(pontos[0].getX()), round(pontos[0].getY()));
}
