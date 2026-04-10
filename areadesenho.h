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

    DisplayFile displayFile;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif


