/**
  * \file scores.h
  * \brief Shows up to the last 10 previous scores of a game
  * Also generates a performance graph
  */
#ifndef SCORES_H
#define SCORES_H

#include <gameinfowidget.h>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

class Scores : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The widget is initialized with the gameID so we know which description to use.
     */
    explicit Scores(user *_player, int _gameID, QWidget *parent = nullptr);

    int gameID;

    user *player;
    QLabel* title, *scoresLabel, *note;
    QPushButton *backButton;
    QVector<int> gameScores;

    /**
     * @brief Generates a performance graph and add it to the layout
     * @param layout The layout we want to add the graph to
     */
    void showGraph(QVBoxLayout *layout);

public slots:
    /**
     * @brief Gets us back to the game info screen of the corresponding game.
     */
    void goBack();
};

#endif // SCORES_H
