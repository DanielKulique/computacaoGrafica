#include "areadesenho.h"
#include "ObjetoPonto.h"
#include "Reta.h"
#include <QPainter>
#include <cmath>
#include <QDebug>



AreaDesenho::AreaDesenho(QWidget *parent) : QFrame(parent)
{
    setStyleSheet("background-color: white;");
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(corAtual, espessuraAtual));

    // desenha os objetos
    for (Objeto* obj : displayFile.objetos) {
        obj->desenhar(painter);
    }

    // demonstracao do polígono em construção
    if (modoDesenho == "poligono" && pontosTemporarios.size() > 0) {
        painter.setPen(QPen(Qt::gray, 1, Qt::DashLine));
        for (size_t i = 1; i < pontosTemporarios.size(); i++) {
            painter.drawLine(
                round(pontosTemporarios[i-1].getX()),
                round(pontosTemporarios[i-1].getY()),
                round(pontosTemporarios[i].getX()),
                round(pontosTemporarios[i].getY())
                );
        }

        // marca cada vértice clicado
        painter.setPen(QPen(Qt::blue, 4));
        for (auto &p : pontosTemporarios) {
            painter.drawPoint(round(p.getX()), round(p.getY()));
        }
    }
}

void AreaDesenho::moverObjetos(float dx, float dy) {
    for (Objeto* obj : displayFile.objetos) {
        obj->mover(dx, dy);
    }
    update();
}

void AreaDesenho::setModo(const QString &modo) {
    modoDesenho = modo;
    pontosTemporarios.clear();
    qDebug() << "modo atual:" << modoDesenho;
}

void AreaDesenho::mousePressEvent(QMouseEvent *event) {
    float x = event->pos().x();
    float y = event->pos().y();

    if (modoDesenho == "ponto") {
        QString nome = QString("Ponto %1").arg(contadorPonto++);

        ObjetoPonto* novoPonto = new ObjetoPonto(nome, Ponto(x, y));

        novoPonto->minhaCor = this->corAtual;
        novoPonto->minhaEspessura = this->espessuraAtual;

        displayFile.adicionar(novoPonto);

        emit novoObjetoCriado(nome);
        update();
    }
    else if (modoDesenho == "reta") {
        pontosTemporarios.push_back(Ponto(x, y));
        if (pontosTemporarios.size() == 2) {
            QString nome = QString("Reta %1").arg(contadorReta++);

            Reta* novaReta = new Reta(nome, pontosTemporarios[0], pontosTemporarios[1]);

            novaReta->minhaCor = this->corAtual;
            novaReta->minhaEspessura = this->espessuraAtual;

            displayFile.adicionar(novaReta);

            emit novoObjetoCriado(nome);
            pontosTemporarios.clear();
            update();
        }
    }


    else if (modoDesenho == "poligono") {
        pontosTemporarios.push_back(Ponto(x, y));
        update();
    }
}
