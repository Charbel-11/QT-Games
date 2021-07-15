#include "syringe.h"

Syringe::Syringe(int _x, int _y, int _r, QObject *parent) : QObject(parent)
{
    xC = _x; yC = _y;
    rollSpeed = _r;
    this->setPixmap(QPixmap(":/images/syringe.png").scaled(60, 60));

    setTransformOriginPoint(30, 60);
    initializePos();

    shooter = new QTimer(this);
    QObject::connect(shooter, SIGNAL(timeout()), this, SLOT(move2()));

    mover = new QTimer(this);
    QObject::connect(mover, SIGNAL(timeout()), this, SLOT(move()));
    mover->start(81 - 5*rollSpeed);
}

void Syringe::initializePos(){
    setPos(95*xC, 700-80*yC);

    if (xC == 1){ this->setRotation(0); }
    if (xC == 2 || xC == 3){ this->setRotation(-45); }
    if (xC == 4){ this->setRotation(-90); }
}

void Syringe::move(){
    setPos(x(), y() + 1.5);
}

void Syringe::changeSpeed(int nSpeed){
    rollSpeed = nSpeed;
    mover->stop();
    mover->start(81 - 5*rollSpeed);
}

void Syringe::shoot(qreal o){
    this->setRotation(o + 30);
    orientation = o + 65;
    shooter->start(90 - 5*rollSpeed);
}

void Syringe::move2(){
    int dy = -12 + abs(orientation) / 9;
    int dx = orientation / 7;

    if (abs(dx-dy) <= 2){
        if (dx < 0) dx -= 2;
        else dx += 2;
        dy -= 3;
    }
    setPos(x() + 1.5*dx, y() + 1.5*dy);
}
