#include "arrow.h"

#include <iostream>

Arrow::Arrow(int _x, int _y, int _r, QObject *parent) : QObject(parent)
{
    xC = _x; yC = _y;
    dir = 1;
    rollSpeed = _r;

    this->setPixmap(QPixmap(":/images/Arrow.png").scaled(65, 50));

    rotationTimer = new QTimer(this);
    mover = new QTimer(this);

    setTransformOriginPoint(0, 50);
    initializePos();

    QObject::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(rotate()));
    QObject::connect(mover, SIGNAL(timeout()), this, SLOT(move()));

    rotationTimer->start(150 - 5*rollSpeed);
    mover->start(81 - 5*rollSpeed);
}

void Arrow::initializePos(){
    setPos(95*xC, 700-80*yC);
    setRotation(0);

    if (xC == 1){ setPos(x() + 60, y() - 30); }
    else if (xC == 2 || xC == 3){ setPos(x() + 30, y() - 10); }
}

void Arrow::rotate(){
    this->setRotation(this->rotation() + dir*15);

    if(this->rotation() >= 20 || this->rotation() <= -180)
        dir *= -1;
}

void Arrow::move(){
    setPos(x(), y() + 1.5);
}

void Arrow::changeSpeed(int nSpeed){
    rollSpeed = nSpeed;
    mover->stop();
    mover->start(81 - 5*rollSpeed);
    rotationTimer->stop();
    rotationTimer->start(130 - 5*rollSpeed);
}
