#ifndef OBJETOPONTO_H
#define OBJETOPONTO_H

#include "Objeto.h"

class ObjetoPonto : public Objeto {
public:
    ObjetoPonto(QString nome, Ponto p);
    void desenhar(QPainter &painter) override;
    ~ObjetoPonto() override = default;
};

#endif
