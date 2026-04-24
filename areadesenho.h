#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>
#include "DisplayFile.h"
#include <QColor>

class AreaDesenho : public QFrame {
    Q_OBJECT //Obrigatório para o MOC, habilitando sinais e slots

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    std::vector<Ponto> pontosTemporarios;
    DisplayFile displayFile;

    QColor corAtual = Qt::red;
    int espessuraAtual = 2;

    int contadorPonto = 1;
    int contadorReta = 1;
    int contadorPoligono = 1;

public slots:
    void moverObjetos(float dx, float dy);

    void setModo(const QString &modo);


signals:
    void novoObjetoCriado(QString nome);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString modoDesenho = "reta";
};



#endif


