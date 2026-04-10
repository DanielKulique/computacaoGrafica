#ifndef PONTO_H
#define PONTO_H


class Ponto
{
private:
    float x, y;


public:
    Ponto(float x = 0, float y = 0);

    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);

};

#endif // PONTO_H
