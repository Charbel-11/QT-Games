#include "gameinfowidget.h"
#include <QFileInfo>
#include <usersdata.h>

bool fileExists(QString path) {
    QFileInfo check_file(path);
    return check_file.exists() && check_file.isFile();
}

gameInfoWidget::gameInfoWidget(int ID, user* _player, QWidget *parent) : QWidget(parent)
{
    gameID = ID; player = _player;
    difficulty = 1;
    title = new QLabel(gameID == 1 ? "Kill Covid-19" : "Reversi");
    setWindowTitle(title->text());
    title->setStyleSheet("font: 50px");

    std::vector<int> top3Scores;
    if (gameID == 1){
        yScore = player->getMaxScoreG1();
        top3Scores = usersData::topScoresG1;
    }
    else{
        yScore = player->getMaxScoreG2();
        top3Scores = usersData::topScoresG2;
    }

    yourScore = new QLabel("Your Best Score: " + QString::number(yScore));
    yourScore->setStyleSheet("font: 25px");
    bestScore = new QLabel("Top 3 Scores: " + QString::number(top3Scores[0]) + ", " + QString::number(top3Scores[1]) + ", " + QString::number(top3Scores[2]));
    bestScore->setStyleSheet("font: 25px");

    gameImage = new QLabel("Game Image");
    if (gameID==1){
        gameImage->setPixmap(QPixmap(":/images/covidPic.jpeg").scaled(100, 150, Qt::KeepAspectRatio));
    }
    else{
         gameImage->setPixmap(QPixmap(":/images/ReversiLogo.png").scaled(100, 150, Qt::KeepAspectRatio));
    }
    gameImage->setAlignment(Qt::AlignCenter);
    gameImage->setFixedSize(QSize(100, 150));

    QSize size(250, 85);
    newGameButton = new QPushButton("New Game");
    newGameButton->setFixedSize(size);
    newGameButton->setStyleSheet("font: 25px");
    continueGameButton = new QPushButton("Continue Game");
    continueGameButton->setFixedSize(size);
    continueGameButton->setStyleSheet("font: 25px");
    scoresButton = new QPushButton("Previous Scores");
    scoresButton->setFixedSize(size);
    scoresButton->setStyleSheet("font: 25px");
    instructionsButton = new QPushButton("Instructions");
    instructionsButton->setFixedSize(size);
    instructionsButton->setStyleSheet("font: 25px");
    difficultyButton = new QPushButton("Change Difficulty");
    difficultyButton->setFixedSize(size);
    difficultyButton->setStyleSheet("font: 25px");

    QString username = player->getUsername();
    QString path = "data/" + username + "/G" + QString::number(gameID) + ".txt";
    if (!fileExists(path)){
        continueGameButton->setEnabled(false);
    }

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(QSize(125, 75));

    //Sets the layout
    layout = new QVBoxLayout;
    setGridLayout();
    setLayout(layout);

    //Connects the signals to the slots
    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
    QObject::connect(difficultyButton, SIGNAL(clicked(bool)), this, SLOT(changeDifficulty()));
    QObject::connect(instructionsButton, SIGNAL(clicked(bool)), this, SLOT(openInstructions()));
    QObject::connect(scoresButton, SIGNAL(clicked(bool)), this, SLOT(viewScores()));
    QObject::connect(newGameButton, SIGNAL(clicked(bool)), this, SLOT(newGame()));
    QObject::connect(continueGameButton, SIGNAL(clicked(bool)), this, SLOT(continueGame()));
}

void gameInfoWidget::setGridLayout(){
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(gameImage);
    topLayout->addItem(new QSpacerItem(200, 50), 0, 0);
    topLayout->addWidget(title, 0, 1, Qt::AlignCenter);
    topLayout->addWidget(backButton, 0, 2, Qt::AlignRight);

    QHBoxLayout *scores = new QHBoxLayout;
    scores->addItem(new QSpacerItem(45,10));
    scores->addWidget(bestScore);
    scores->addItem(new QSpacerItem(60,10));
    scores->addWidget(yourScore);

    QVBoxLayout *buttons0 = new QVBoxLayout;
    buttons0->addWidget(instructionsButton);
    buttons0->addWidget(difficultyButton);
    buttons0->setSpacing(20);

    QVBoxLayout *buttons = new QVBoxLayout;
    buttons->addWidget(newGameButton);
    buttons->addWidget(continueGameButton);
    buttons->addWidget(scoresButton);
    buttons->setSpacing(20);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addItem(new QSpacerItem(50, 50));
    hLayout->addItem(buttons0);
    hLayout->addItem(new QSpacerItem(100, 100));
    hLayout->addItem(buttons);

    layout->addItem(topLayout);
    layout->addItem(scores);
    layout->addItem(hLayout);
    layout->addItem(new QSpacerItem(50, 50));
}

void gameInfoWidget::goBack(){
    Helper::openWidget(new GameChoiceWidget(player));
    this->close();
}

void gameInfoWidget::changeDifficulty(){
    Helper::openWidget(new DifficultyWidget(player, gameID));
    this->close();
}

void gameInfoWidget::openInstructions(){
    Helper::openWidget(new InstructionsWidget(player, gameID));
    this->close();
}

void gameInfoWidget::viewScores(){
    Helper::openWidget(new Scores(player, gameID));
    this->close();
}

void gameInfoWidget::newGame(){
    if (gameID == 1){
        Helper::openView(new KillCovidScene(player, yScore, 0, false), 500, 700, "Kill Covid-19");
    }
    else{
        Helper::openView(new ReversiScene(player, false), 500, 700, "Reversi");
    }
    this->close();
}

void gameInfoWidget::continueGame(){
    if (gameID == 1){
        Helper::openView(new KillCovidScene(player, yScore, 0, true), 500, 700, "Kill Covid-19");
    }
    else{
        Helper::openView(new ReversiScene(player, true), 500, 700, "Reversi");
    }
    this->close();
}
