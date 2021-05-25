/**
  * \file syringe.h
  * \brief The attacking player of the Kill Covid game
  */
#ifndef SYRINGE_H
#define SYRINGE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Syringe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Syringe(int _x, int _y, int _r, QObject *parent = nullptr);

    int xC, yC, rollSpeed;
    qreal orientation;

    QTimer *mover, *shooter;

    /**
     * @brief Sets the initial position of the syringe according to its grid coordinates
     */
    void initializePos();

    /**
     * @brief Changes the rolling speed
     * @param nSpeed The new rolling speed
     */
    void changeSpeed(int nSpeed);

    /**
     * @brief Moves the syringe according to the arrow's orientation
     * @param o The arrow's orientation
     */
    void shoot(qreal o);

public slots:
    /**
     * @brief Periodically move the player down to simulate a rolling background
     */
    void move();

    /**
     * @brief Moves the player when using the shooting ability
     */
    void move2();
};

#endif // SYRINGE_H
