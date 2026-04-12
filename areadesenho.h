#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>
#include "DisplayFile.h"

class AreaDesenho : public QFrame {
    Q_OBJECT //Obrigatório para o MOC, habilitando sinais e slots

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    std::vector<Ponto> pontosTemporarios;
    DisplayFile displayFile;

public slots:
    void moverObjetos(float dx, float dy);

    void setModo(const QString &modo);


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString modoDesenho = "reta";
};



#endif


