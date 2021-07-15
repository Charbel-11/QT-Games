/**
  * \file gameinfowidget.h
  * \brief Screen where the player can access information about a game
  */
#ifndef GAMEINFOWIDGET_H
#define GAMEINFOWIDGET_H

#include "gamechoicewidget.h"
#include "helper.h"
#include "scores.h"
#include "instructionswidget.h"
#include "difficultywidget.h"
#include "../Game1/killcovidscene.h"
#include "../Game2/reversiscene.h"

class gameInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gameInfoWidget(int ID, user* _player, QWidget *parent = nullptr);
    int gameID;
    int difficulty, yScore;
    user *player;
    QLabel *title, *bestScore, *yourScore, *gameImage;
    QPushButton *backButton, *newGameButton, *continueGameButton, *scoresButton, *instructionsButton, *difficultyButton;

    QVBoxLayout *layout;

    void setGridLayout();

public slots:
    /**
     * @brief Goes back to the game choice screen
     */
    void goBack();
    /**
     * @brief Opens the change difficulty scene
     */
    void changeDifficulty();
    /**
     * @brief Opens the instruction scene
     */
    void openInstructions();
    /**
     * @brief Opens the score scene
     */
    void viewScores();
    /**
     * @brief Starts a new game instance
     */
    void newGame();
    /**
     * @brief Continues a previous game instance
     * It is disabled in case there are no saved and unfinished game
     */
    void continueGame();
};

#endif // GAMEINFOWIDGET_H
