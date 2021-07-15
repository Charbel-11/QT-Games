/**
  * \file instructionswidget.h
  * \brief Shows the instructions of a game
  */
#ifndef INSTRUCTIONSWIDGET_H
#define INSTRUCTIONSWIDGET_H

#include "gameinfowidget.h"

class InstructionsWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The widget is initialized with the gameID so we know which description to use.
     */
    explicit InstructionsWidget(user *_player, int _gameID, QWidget *parent = nullptr);

    user *player;
    int gameID;
    QLabel *instructions, *title;
    QPushButton *backButton;

public slots:
    /**
     * @brief Gets us back to the game info screen of the corresponding game.
     */
    void goBack();
};

#endif // INSTRUCTIONSWIDGET_H
