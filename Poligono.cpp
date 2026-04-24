#include "Poligono.h"
#include <cmath>

Poligono::Poligono(QString nome, std::vector<Ponto> pts)
    : Objeto(nome, "poligono")
{
    pontos = pts;
}

void Poligono::desenharSegmento(QPainter &painter, Ponto a, Ponto b)
{

    float x1 = a.getX(), y1 = a.getY();
    float x2 = b.getX(), y2 = b.getY();

    float dx = x2 - x1;
    float dy = y2 - y1;

    int passos = std::max(std::abs(dx), std::abs(dy));

    if (passos == 0) {
        painter.drawPoint(round(x1), round(y1));
        return;
    }

    float x_inc = dx / passos;
    float y_inc = dy / passos;
    float x = x1, y = y1;

    for (int i = 0; i <= passos; i++) {
        painter.drawPoint(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }
}

void Poligono::desenhar(QPainter &painter)
{
    painter.setPen(QPen(this->minhaCor, this->minhaEspessura));
    int n = pontos.size();
    if (n < 2) return;

    for (int i = 0; i < n; i++) {
        desenharSegmento(painter, pontos[i], pontos[(i + 1) % n]);
    }
}
