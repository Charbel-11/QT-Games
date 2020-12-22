/**
  * \file virus.h
  * \brief Stores the information of all registered users
  */
#ifndef VIRUS_H
#define VIRUS_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Virus(int _t, int _x, int _y, int _r, QObject *parent = nullptr);

    int xC, yC, type, rollSpeed;
    bool dead;

    QTimer* mover;

    /**
     * @brief Changes the rolling speed
     * @param nSpeed The new rolling speed
     */
    void changeSpeed(int nSpeed);

    /**
     * @brief Changes the virus pixmap to make him look smashed
     */
    void smashed();

public slots:
    /**
     * @brief Periodically move the virus down to simulate a rolling background
     */
    void move();
};

#endif // VIRUS_H
