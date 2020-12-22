/**
  * \file gamechoicewidget.h
  * \brief Screen where the user can choose which game he wants
  */
#ifndef GAMECHOICEWIDGET_H
#define GAMECHOICEWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <user.h>

class GameChoiceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameChoiceWidget(user* _player, QWidget *parent = nullptr);
    user* player;
    QLabel *title, *name, *pic, *message, *game1Name, *game2Name;
    QPushButton *game1Button, *game2Button, *backButton;  
    QVBoxLayout *layout;

    void setGridLayout();

public slots:
    /**
     * @brief Opens a screen specific to game 1
     */
    void openGame1Info();
    /**
     * @brief Opens a screen specific to game 2
     */
    void openGame2Info();
    /**
     * @brief Goes back to the authetincation screen
     */
    void goBack();
};

#endif // GAMECHOICEWIDGET_H
