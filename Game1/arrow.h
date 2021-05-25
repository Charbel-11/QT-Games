/**
  * \file arrow.h
  * \brief Rotating arrow that orients the attack of the player
  */
#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Initializes the arrow on the correct place in the grid
     * @param _x The x coordinate on the grid
     * @param _y The y coordinate on the grid
     * @param _r The current rolling speed
     */
    explicit Arrow(int _x, int _y, int _r, QObject *parent = nullptr);

    int xC, yC, dir, rollSpeed;

    QTimer *rotationTimer, *mover;

    /**
     * @brief Changes the rolling speed
     * @param nSpeed The new rolling speed
     */
    void changeSpeed(int nSpeed);

    /**
     * @brief Initializes the position of the arrow on the grid according to its coordinates
     */
    void initializePos();

public slots:
    /**
     * @brief Rotates the arrow periodically
     */
    void rotate();
    /**
     * @brief Moves the arrow down to simulate the rolling background
     */
    void move();
};

#endif // ARROW_H
