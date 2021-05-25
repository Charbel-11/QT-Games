#include "scores.h"

Scores::Scores(user *_player, int _gameID, QWidget *parent) : QWidget(parent)
{
    player = _player;
    gameID = _gameID;
    QString s = (gameID == 1 ? "Kill Covid-19" : "Reversi");
    title = new QLabel(s + " Scores");
    title->setStyleSheet("font: 50px");
    setWindowTitle(s + " Scores");

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(QSize(250, 100));

    if (gameID == 1){ gameScores = player->getScoresG1(); }
    else { gameScores = player->getScoresG2(); }

    QString st("");
    for(int i = 0; i < gameScores.size(); i++){
        st += QString::number(gameScores[i]);
        if (i != gameScores.size() - 1){ st.push_back(", "); }
    }
    scoresLabel = new QLabel(st);
    scoresLabel->setStyleSheet("font: 30px");

    note = new QLabel("Note: Games where you saved and exited do not show here as the game is not over yet");


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addWidget(scoresLabel, 0, Qt::AlignLeft);
    showGraph(layout);
    layout->addWidget(note, 0, Qt::AlignLeft);
    layout->addWidget(backButton, 0, Qt::AlignCenter);
    layout->addItem(new QSpacerItem(30, 30));

    setLayout(layout);

    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
}

void Scores::showGraph(QVBoxLayout *layout){
     QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
     for(int i = 0; i < gameScores.size(); i++){
         series->append(i, gameScores[i]);
     }

     QtCharts::QChart *chart = new QtCharts::QChart();
     chart->legend()->hide();
     chart->addSeries(series);
     chart->createDefaultAxes();
     chart->setTitle("Performance Graph");

     QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     layout->addWidget(chartView);
}

void Scores::goBack(){
    Helper::openWidget(new gameInfoWidget(gameID, player));
    this->close();
}
