#include "Reta.h"
#include <cmath>

Reta::Reta(QString nome, Ponto p1, Ponto p2)
    : Objeto(nome, "reta")
{
    pontos.push_back(p1);
    pontos.push_back(p2);
}

void Reta::desenhar(QPainter &painter)
{
    painter.setPen(QPen(this->minhaCor, this->minhaEspessura));
    float x1 = pontos[0].getX();
    float y1 = pontos[0].getY();

    float x2 = pontos[1].getX();
    float y2 = pontos[1].getY();

    float dx = x2 - x1;
    float dy = y2 - y1;

    int passos = std::max(std::abs(dx), std::abs(dy));

    if (passos == 0) {
        painter.drawPoint(round(x1), round(y1));
        return;
    }

    float x_inc = dx / passos;
    float y_inc = dy / passos;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= passos; i++) {
        painter.drawPoint(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }
}
