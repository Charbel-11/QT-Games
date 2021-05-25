/**
  * \file difficultywidget.h
  * \brief The widget where the player can change game difficulty
  */
#ifndef DIFFICULTYWIDGET_H
#define DIFFICULTYWIDGET_H

#include <gameinfowidget.h>

class DifficultyWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The widget is initialized with the player and gameID to be able to modify the player's settings and store the modifications.
     */
    explicit DifficultyWidget(user* _player, int _gameID, QWidget *parent = nullptr);

    int gameID;
    user *player;
    QPushButton *confirmB;
    QLabel *easyD, *mediumD, *hardD, *title;
    QRadioButton *easyB, *mediumB, *hardB;

    QVBoxLayout *layout;

    /**
     * @brief Sets the main grid layout of this widget.
     */
    void setGridLayout();

public slots:
    /**
     * @brief Gets us back to the game info screen of the corresponding game after saving the changes to the player's account.
     */
    void confirmChoice();
};

#endif // DIFFICULTYWIDGET_H
