/**
  * \file reversiScene.h
  * \brief Main scene of the Reversi Game
  */
#ifndef REVERSISCENE_H
#define REVERSISCENE_H

#include "../UI/helper.h"
#include "../UI/gamechoicewidget.h"
#include <fstream>
#include <QTimer>
#include "../Users/usersdata.h"
#include <QCloseEvent>

class ReversiScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ReversiScene(user* _player, bool continueFlag);
    user* player;

    QLabel *p1Label, *p2Label, *p1Color, *p2Color;
    QLabel *p1ScoreLabel, *p2ScoreLabel, *p1TimeLabel, *p2TimeLabel;
    QLabel *winner, *winInfo;

    QPushButton *passBut, *saveExitBut, *exitBut, *playAgainBut;

    QVector<QLabel*> gridNums, gridLetters;
    QVector<QVector<QPushButton*>> grid;
    QVector<QVector<int>> gridState;

    bool isP1Turn;
    int discsW, discsB;
    int timeLeftP1, timeLeftP2;
    int passCount;

    QTimer* clock;

    /**
     * @brief Sets the labels for the game
     */
    void setGameLayout();

    /**
     * @brief Initializes the game grid for a new game
     */
    void setInitialGameState();

    /**
     * @brief Reads from the file information to continue a previous game, initializing the game grid accordingly
     */
    void setPreviousGameState();

    /**
     * @brief Sets the buttons for the game
     */
    void setGameButtons();

    /**
     * @brief Switches turns between player 1 and 2
     */
    void switchTurn();

    /**
     * @brief Highlights all valid moves on the grid
     */
    void HighlightPossibleMoves();

    /**
     * @brief Flips the discs according to the choice of the player
     * @param i The ith coordinate of the chosen cell
     * @param j The jth coordinate of the chosen cell
     */
    void flipDiscs(int i, int j);

    /**
     * @brief Ends the game, showing the winner
     */
    void endGame();

public slots:
    /**
     * @brief Passes the turn to the other player
     */
    void passTurn();

    /**
     * @brief Go back to the game choice screen
     */
    void goBack();

    /**
     * @brief Starts a new game again
     */
    void playAgain();

    /**
     * @brief Saves the game state into a file and exists the game
     */
    void saveAndExit();

    /**
     * @brief Updates the time counter for the current player
     */
    void changeTime();

    /**
     * @brief Checks whether the cell choosed is valid, and behave accordingly
     */
    void handleChoice();
};

#endif // REVERSISCENE_H
