/**
  * \file killcovidscene.h
  * \brief Main scene of the Kill Covid Game
  */
#ifndef KILLCOVIDSCENE_H
#define KILLCOVIDSCENE_H

#include <helper.h>
#include <gamechoicewidget.h>
#include <user.h>
#include <syringe.h>
#include <virus.h>
#include <arrow.h>
#include <usersdata.h>
#include <fstream>
#include <QCloseEvent>

class KillCovidScene : public QGraphicsScene
{
     Q_OBJECT

public:
    KillCovidScene(user* _player, int hScore, int yScore, bool continueFlag);
    user* player;

    QLabel *title, *bestScore, *yourScore, *gameState;
    QPushButton *playButton, *backButton;

    QLabel *speedLabel, *scoreLabel, *chancesLabel;
    QPushButton *saveExit;

    Syringe* syringe;
    Arrow* arrow;
    QVector<Virus*> viruses;

    QTimer *virusAdder, *checker;

    int speed, score, chances, neededScore, killed;
    int bestScoreVal, yourScoreVal;
    bool gameStarted, shooting;

    std::ofstream ofsV;

    /**
     * @brief Sets the grid layout of the initial buttons
     */
    void setInitialGridLayout();

    /**
     * @brief Initializes the values of the initial buttons
     * @param state 1 if we just won a game, 2 if we just lost a game and 0 if we did not play yet
     */
    void setInitialButtons(int state);

    /**
     * @brief Initializes the values of the in-game buttons
     */
    void setGameButtons();

    /**
     * @brief Continues a previous game according to the info stored in a text file
     */
    void continueGame();

    /**
     * @brief Handles ending a game
     * Removes items from the scene and computes the scores history
     * @param won Is true if the player won the game, false otherwise
     */
    void endGame(bool won);

    /**
     * @brief Handles pressing on a key
     * If the game has not started, F1 to start it
     * If the game has started, any key will trigger the shoot ability
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Shows the arrow once the shot has ended
     */
    void showArrow();

    /**
     * @brief Moves the player according to the arrow's orientation
     */
    void shoot();

    /**
     * @brief Changes the speed of all the items in the screen
     * @param nSpeed The new rolling speed
     */
    void changeSpeed(int nSpeed);


public slots:
    /**
     * @brief Checks for all collisions in the screeen
     * Handles item going out of bounds
     * Handles collisions due to shootings
     */
    void checkCollisions();

    /**
     * @brief Saves the game and exit
     * Stores the current state of the game in a text file
     */
    void saveAndExit();

    /**
     * @brief Goes to the game selection screen
     */
    void goBack();

    /**
     * @brief Starts the game
     */
    void startGame();

    /**
     * @brief Adds a virus on the top of the screen
     * Its x coordinate and type are random
     */
    void addVirus();
};

#endif // KILLCOVIDSCENE_H
