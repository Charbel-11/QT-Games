#include "reversiscene.h"
#include <iostream>

ReversiScene::ReversiScene(user* _player, bool continueFlag)
{
    player = _player;
    setBackgroundBrush(QWidget().palette().background());

    setGameLayout();
    setGameButtons();
    if (!continueFlag) { setInitialGameState(); }
    else { setPreviousGameState(); }

    clock = new QTimer();
    QObject::connect(clock, SIGNAL(timeout()), this, SLOT(changeTime()));
    clock->start(1000);
}

void ReversiScene::setGameLayout(){
    p1Label = new QLabel("Player 1");
    p1Label->setStyleSheet("font: 25px");
    p1Label->setGeometry(25, 0, 125, 40);
    p1Color = new QLabel;
    p1Color->setPixmap(QPixmap(":/images/BlackDisc.png").scaled(40, 40, Qt::KeepAspectRatio));
    p1Color->setGeometry(150, 0, 40, 40);

    p1ScoreLabel = new QLabel("Discs: ");
    p1ScoreLabel->setStyleSheet("font: 25px");
    p1ScoreLabel->setGeometry(25, 40, 200, 40);
    p1TimeLabel = new QLabel("Time: ");
    p1TimeLabel->setStyleSheet("font: 25px");
    p1TimeLabel->setGeometry(25, 80, 200, 40);

    this->addWidget(p1Label);
    this->addWidget(p1Color);
    this->addWidget(p1ScoreLabel);
    this->addWidget(p1TimeLabel);

    p2Label = new QLabel("Player 2");
    p2Label->setStyleSheet("font: 25px");
    p2Label->setGeometry(300, 0, 125, 40);
    p2Color = new QLabel;
    p2Color->setPixmap(QPixmap(":/images/WhiteDisc.png").scaled(40, 40, Qt::KeepAspectRatio));
    p2Color->setGeometry(425, 0, 40, 40);

    p2ScoreLabel = new QLabel("Discs: ");
    p2ScoreLabel->setStyleSheet("font: 25px");
    p2ScoreLabel->setGeometry(300, 40, 200, 40);
    p2TimeLabel = new QLabel("Time: ");
    p2TimeLabel->setStyleSheet("font: 25px");
    p2TimeLabel->setGeometry(300, 80, 200, 40);

    this->addWidget(p2Label);
    this->addWidget(p2Color);
    this->addWidget(p2ScoreLabel);
    this->addWidget(p2TimeLabel);

    grid = QVector<QVector<QPushButton*>>(8);
    gridState = QVector<QVector<int>>(8);
    gridNums = QVector<QLabel*>(8);
    gridLetters = QVector<QLabel*>(8);

    for(int i = 0; i < 8; i++){
        grid[i] = QVector<QPushButton*>(8);
        gridState[i] = QVector<int>(8);

        gridNums[i] = new QLabel(QString::number(i+1));
        gridNums[i]->setAlignment(Qt::AlignCenter);
        gridNums[i]->setGeometry(50*(i+1), 120, 50, 50);
        this->addWidget(gridNums[i]);

        gridLetters[i] = new QLabel(QString('A'+i));
        gridLetters[i]->setAlignment(Qt::AlignCenter);
        gridLetters[i]->setGeometry(0, 120 + 50*(i+1), 50, 50);
        this->addWidget(gridLetters[i]);

        for(int j = 0; j < 8; j++){
            grid[i][j] = new QPushButton;
            QObject::connect(grid[i][j], SIGNAL(clicked(bool)), this, SLOT(handleChoice()));
        }
    }
}

void ReversiScene::setInitialGameState(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            gridState[i][j] = 0;
            grid[i][j]->setFixedSize(QSize(50, 50));
            grid[i][j]->setIcon(QIcon(":/images/EmptyDisc.png"));
            grid[i][j]->setIconSize(QSize(50, 50));
            grid[i][j]->setGeometry(50 + 50*j, 170 + 50*i, 50, 50);
            if (!grid[i][j]->isVisible()) this->addWidget(grid[i][j]);
        }
    }

    grid[3][3]->setIcon(QIcon(":/images/WhiteDisc.png"));
    grid[4][4]->setIcon(QIcon(":/images/WhiteDisc.png"));
    gridState[3][3] = gridState[4][4] = 2;
    grid[3][4]->setIcon(QIcon(":/images/BlackDisc.png"));
    grid[4][3]->setIcon(QIcon(":/images/BlackDisc.png"));
    gridState[3][4] = gridState[4][3] = 1;

    discsW = discsB = 2;
    p1ScoreLabel->setText("Discs: " + QString::number(discsB));
    p2ScoreLabel->setText("Discs: " + QString::number(discsW));

    timeLeftP1 = timeLeftP2 = 15*60;
    if (player->getG2Difficulty() == 2){ timeLeftP1 = timeLeftP2 = 10*60; }
    else if (player->getG2Difficulty() == 3){ timeLeftP1 = timeLeftP2 = 5*60; }

    int min = timeLeftP1/60;
    p1TimeLabel->setText("Time: " + QString::number(min) + ":00");
    p2TimeLabel->setText("Time: " + QString::number(min) + ":00");

    passCount = 0;
    isP1Turn = false;
    switchTurn();
}

void ReversiScene::setPreviousGameState(){
    QString username = player->getUsername();
    std::string path = "data/" + username.toStdString() + "/G2.txt";
    std::ifstream ifs(path);

    ifs >> isP1Turn >> timeLeftP1 >> timeLeftP2 >> passCount;
    discsB = discsW = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            ifs >> gridState[i][j];
            grid[i][j]->setFixedSize(QSize(50, 50));

            if (gridState[i][j] == 0){ grid[i][j]->setIcon(QIcon(":/images/EmptyDisc.png")); }
            else if (gridState[i][j] == 1){ grid[i][j]->setIcon(QIcon(":/images/BlackDisc.png")); discsB++; }
            else if (gridState[i][j] == 2){ grid[i][j]->setIcon(QIcon(":/images/WhiteDisc.png")); discsW++; }
            else { grid[i][j]->setIcon(QIcon(":/images/EmptyDiscToSelect.png")); }
            grid[i][j]->setIconSize(QSize(50, 50));
            grid[i][j]->setGeometry(50 + 50*j, 170 + 50*i, 50, 50);
            this->addWidget(grid[i][j]);
        }
    }

    p1ScoreLabel->setText("Discs: " + QString::number(discsB));
    p2ScoreLabel->setText("Discs: " + QString::number(discsW));

    int min1 = timeLeftP1/60, sec1 = timeLeftP1 % 60;
    int min2 = timeLeftP2/60, sec2 = timeLeftP2 % 60;
    p1TimeLabel->setText("Time: " + QString::number(min1) + (sec1 < 10 ? ":0" : ":")  + QString::number(sec1));
    p2TimeLabel->setText("Time: " + QString::number(min2) + (sec2 < 10 ? ":0" : ":")  + QString::number(sec2));

    isP1Turn = !isP1Turn;
    switchTurn();
}

void ReversiScene::setGameButtons(){
    passBut = new QPushButton("Pass");
    passBut->setGeometry(100, 600, 100, 50);
    passBut->setEnabled(false);

    saveExitBut = new QPushButton("Save and Exit");
    saveExitBut->setStyleSheet("font: 13px; color: red;");
    saveExitBut->setGeometry(300, 600, 100, 50);

    playAgainBut = new QPushButton("Play Again");
    playAgainBut->setGeometry(100, 600, 100, 50);
    exitBut = new QPushButton("Exit");
    exitBut->setGeometry(300, 600, 100, 50);

    this->addWidget(passBut);
    this->addWidget(saveExitBut);
    this->addWidget(playAgainBut);
    this->addWidget(exitBut);
    playAgainBut->hide(); exitBut->hide();

    QObject::connect(passBut, SIGNAL(clicked(bool)), this, SLOT(passTurn()));
    QObject::connect(saveExitBut, SIGNAL(clicked(bool)), this, SLOT(saveAndExit()));
    QObject::connect(playAgainBut, SIGNAL(clicked(bool)), this, SLOT(playAgain()));
    QObject::connect(exitBut, SIGNAL(clicked(bool)), this, SLOT(goBack()));
}

void ReversiScene::switchTurn(){
    if (isP1Turn){
        p1Label->setStyleSheet("color: gray; font: 25px");
        p1ScoreLabel->setStyleSheet("color: gray; font: 25px");
        p1TimeLabel->setStyleSheet("color: gray; font: 25px");

        p2Label->setStyleSheet("color: black; font: 25px");
        p2ScoreLabel->setStyleSheet("color: black; font: 25px");
        p2TimeLabel->setStyleSheet("color: black; font: 25px");
    }
    else{
        p1Label->setStyleSheet("color: black; font: 25px");
        p1ScoreLabel->setStyleSheet("color: black; font: 25px");
        p1TimeLabel->setStyleSheet("color: black; font: 25px");

        p2Label->setStyleSheet("color: gray; font: 25px");
        p2ScoreLabel->setStyleSheet("color: gray; font: 25px");
        p2TimeLabel->setStyleSheet("color: gray; font: 25px");
    }
    isP1Turn = !isP1Turn;
    HighlightPossibleMoves();
}

void ReversiScene::changeTime(){
    if (isP1Turn){
        timeLeftP1--;
        int min1 = timeLeftP1/60, sec1 = timeLeftP1 % 60;
        p1TimeLabel->setText("Time: " + QString::number(min1) + (sec1 < 10 ? ":0" : ":")  + QString::number(sec1));
    }
    else{
        timeLeftP2--;
        int min2 = timeLeftP2/60, sec2 = timeLeftP2 % 60;
        p2TimeLabel->setText("Time: " + QString::number(min2) + (sec2 < 10 ? ":0" : ":")  + QString::number(sec2));
    }
    if (timeLeftP1 == 0 || timeLeftP2 == 0){ endGame(); }
}

void ReversiScene::passTurn(){
    switchTurn();
    passCount++;
    if (passCount == 2){ endGame(); }
}

void ReversiScene::handleChoice(){
    int i, j;
    bool found = false;
    for (i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if (sender() == grid[i][j]){ found = true; break; }
        }
        if (found){ break; }
    }

    if (gridState[i][j] != 3){ return; }
    passCount = 0;
    flipDiscs(i, j);
}

void ReversiScene::flipDiscs(int i, int j){
    int dx[] = {0, 1, -1}, dy[] = {0, 1, -1};

    int curPlayer = isP1Turn ? 1 : 2;
    gridState[i][j] = curPlayer;
    for(auto &x : dx){
        for(auto &y : dy){
            if (!x && !y){ continue; }

            int ni = i + x, nj = j + y;
            while(ni < 8 && ni >= 0 && nj < 8 && nj >= 0){
                if (gridState[ni][nj] == 0 || gridState[ni][nj] == 3){ break; }
                if (gridState[ni][nj] == curPlayer){
                    if (!(ni == i+x && nj == j+y)){
                        ni -= x; nj -= y;
                        while(!(ni == i && nj == j)){
                            gridState[ni][nj] = curPlayer;
                            ni -= x; nj -= y;
                        }
                    }
                    break;
                }
                ni += x;  nj += y;
            }
        }
    }

    discsB = discsW = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (gridState[i][j] == 1){ grid[i][j]->setIcon(QIcon(":/images/BlackDisc.png")); discsB++; }
            else if (gridState[i][j] == 2){ grid[i][j]->setIcon(QIcon(":/images/WhiteDisc.png")); discsW++; }
            else if (gridState[i][j] == 3){
                gridState[i][j] = 0;
                grid[i][j]->setIcon(QIcon(":/images/EmptyDisc.png"));
            }
        }
    }

    p1ScoreLabel->setText("Discs: " + QString::number(discsB));
    p2ScoreLabel->setText("Discs: " + QString::number(discsW));
    switchTurn();
}

void ReversiScene::HighlightPossibleMoves(){
    int dx[] = {0, 1, -1}, dy[] = {0, 1, -1};

    int curPlayer = isP1Turn ? 1 : 2;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (gridState[i][j] != 0){ continue; }
            for(auto &x : dx){
                for(auto &y : dy){
                    if (!x && !y){ continue; }

                    int ni = i + x, nj = j + y;
                    while(ni < 8 && ni >= 0 && nj < 8 && nj >= 0){
                        if (gridState[ni][nj] == 0 || gridState[ni][nj] == 3){ break; }
                        if (gridState[ni][nj] == curPlayer){
                            if (!(ni == i+x && nj == j+y)) { gridState[i][j] = 3; }
                            break;
                        }
                        ni += x;  nj += y;
                    }
                }
            }
        }
    }

    bool moveAvailable = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (gridState[i][j] == 3){
                grid[i][j]->setIcon(QIcon(":/images/EmptyDiscToSelect.png"));
                moveAvailable = true;
            }
        }
    }
    passBut->setEnabled(!moveAvailable);
}

void ReversiScene::endGame(){
    clock->stop();
    p1Label->hide(); p1Color->hide();
    p1ScoreLabel->hide(); p1TimeLabel->hide();
    p2Label->hide(); p2Color->hide();
    p2ScoreLabel->hide(); p2TimeLabel->hide();

    passBut->hide(); saveExitBut->hide();
    playAgainBut->show(); exitBut->show();

    int pWon = 1;
    if (timeLeftP1 == 0){ pWon = 2; }
    else if (timeLeftP2 == 0){ pWon = 1; }
    else if (discsW > discsB){ pWon = 2; }

    winner = new QLabel("The winner is: Player " + QString::number(pWon));
    winner->setStyleSheet("font: 30px");
    winner->setAlignment(Qt::AlignCenter);
    winner->setGeometry(50, 0, 400, 50);
    if (timeLeftP1 == 0 || timeLeftP2 == 0){  winInfo = new QLabel("By timeout"); }
    else{ winInfo = new QLabel("With " + QString::number(std::abs(discsW-discsB)) + " extra discs"); }
    winInfo->setStyleSheet("font: 20px");
    winInfo->setAlignment(Qt::AlignCenter);
    winInfo->setGeometry(100, 50, 300, 50);

    this->addWidget(winner);
    this->addWidget(winInfo);


    QString username = player->getUsername();
    QString path = "data/" + username + "/G2.txt";
    QFile().remove(path);

    int score = discsB - discsW;
    if (pWon == 1){ score = std::max(score, 0); }
    QVector<int> scoresG2 = player->getScoresG2();
    scoresG2.push_back(score);
    if (scoresG2.size() > 10){ scoresG2.removeAt(0); }
    player->setScoresG2(scoresG2);
    player->updateMaxScoreG2(score);
    player->writeOnFile();

    usersData::tryUpdateMaxG2(abs(score));
}

void ReversiScene::playAgain(){
    winner->hide(); winInfo->hide();

    p1Label->show(); p1Color->show();
    p1ScoreLabel->show(); p1TimeLabel->show();
    p2Label->show(); p2Color->show();
    p2ScoreLabel->show(); p2TimeLabel->show();

    passBut->show(); saveExitBut->show();
    playAgainBut->hide(); exitBut->hide();
    passBut->setEnabled(false);

    setInitialGameState();
    clock->start(1000);
}

void ReversiScene::saveAndExit(){
    QString username = player->getUsername();
    std::string path = "data/" + username.toStdString() + "/G2.txt";
    std::ofstream ofs(path);

    ofs << isP1Turn << " " << timeLeftP1 << " " << timeLeftP2 << " " << passCount << '\n';
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            ofs << gridState[i][j]<<' ';
        }
        ofs << '\n';
    }

    ofs.close();
    goBack();
}

void ReversiScene::goBack(){
    Helper::openWidget(new GameChoiceWidget(player));
    Helper::closeView();
}
