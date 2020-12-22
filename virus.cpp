#include "virus.h"

#include <iostream>

Virus::Virus(int _t, int _x, int _y, int _r, QObject *parent) : QObject(parent)
{
    dead = false;
    rollSpeed = _r;
    xC = _x; yC = _y; type = _t;

    if (type == 0){ this->setPixmap(QPixmap(":/images/SmallVirus.png").scaled(80, 80));}
    else if (type == 1){ this->setPixmap(QPixmap(":/images/MediumVirus.png").scaled(80, 80)); }
    else { this->setPixmap(QPixmap(":/images/LargeVirus.png").scaled(80, 80)); }

    setTransformOriginPoint(40, 80);
    setPos(85*xC, 700-65*yC);

    mover = new QTimer();
    QObject::connect(mover, SIGNAL(timeout()), this, SLOT(move()));
    mover->start(130 - 8*rollSpeed);
}

void Virus::move(){
    setPos(x(), y() + 3);
}

void Virus::changeSpeed(int nSpeed){
    rollSpeed = nSpeed;
    mover->stop();
    mover->start(130 - 8*rollSpeed);
}

void Virus::smashed(){
    dead = true;

    if (type == 0){ this->setPixmap(QPixmap(":/images/SmallVirusSmashed.png").scaled(80, 80));}
    else if (type == 1){ this->setPixmap(QPixmap(":/images/MediumVirusSmashed.png").scaled(80, 80)); }
    else { this->setPixmap(QPixmap(":/images/LargeVirusSmashed.png").scaled(80, 80)); }
}
