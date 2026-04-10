#include "areadesenho.h"
#include "ObjetoPonto.h"
#include "Reta.h"
#include "Poligono.h"
#include <QPainter>

AreaDesenho::AreaDesenho(QWidget *parent) : QFrame(parent)
{
    setStyleSheet("background-color: white;");

    // Populando o DisplayFile com exemplos
    displayFile.adicionar(new ObjetoPonto("p1", Ponto(50, 50)));

    displayFile.adicionar(new Reta("r1", Ponto(10, 10), Ponto(200, 150)));

    displayFile.adicionar(new Poligono("tri1", {
                                                   Ponto(300, 50),
                                                   Ponto(400, 200),
                                                   Ponto(200, 200)
                                               }));
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

    for (Objeto* obj : displayFile.objetos) {
        obj->desenhar(painter);
    }
}
