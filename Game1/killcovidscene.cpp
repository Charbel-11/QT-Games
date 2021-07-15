#include "killcovidscene.h"

KillCovidScene::KillCovidScene(user *_player, int hScore, int yScore, bool continueFlag)
{
    player = _player;

    QMatrix rm; rm.rotate(90);
    setBackgroundBrush(QBrush(QImage(":/images/Background.jpg").scaledToHeight(800).scaledToWidth(750).transformed(rm)));
    setSceneRect(0, 0, 500, 700);

    bestScoreVal = hScore; yourScoreVal = yScore;

    if (continueFlag){ continueGame(); }
    else{
        setInitialButtons(0);
        setInitialGridLayout();
    }
}

void KillCovidScene::setInitialButtons(int state){
    gameStarted = false;
    killed = 0;

    playButton = new QPushButton("Play (or press F1)");
    playButton->setStyleSheet("font: 30px");

    title = new QLabel("KILL COVID-19");
    title->setStyleSheet("font: bold 50px; color: white; background-color: rgba(0,0,0,0%)");

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("font: 30px");

    yourScore = new QLabel("Your Score: " + QString::number(yourScoreVal));
    yourScore->setStyleSheet("font: 30px; color: white; background-color: rgba(0,0,0,0%)");

    bestScore = new QLabel("Your Best Score: " + QString::number(bestScoreVal));
    bestScore->setStyleSheet("font: 30px; color: white; background-color: rgba(0,0,0,0%)");

    if (state == 0){
        gameState = new QLabel("");
        gameState->setStyleSheet("background-color: rgba(0,0,0,0%)");
    }
    else if (state == 1){
        gameState = new QLabel("Winner");
        gameState->setStyleSheet("font: 50px; color: green; background-color: rgba(0,0,0,0%)");
    }
    else if (state == 2){
        gameState = new QLabel("Loser");
        gameState->setStyleSheet("font: 50px; color: red; background-color: rgba(0,0,0,0%)");
    }

    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
    QObject::connect(playButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));
}

void KillCovidScene::setInitialGridLayout(){
    title->setGeometry(50, 40, 450, 100);
    gameState->setGeometry(160, 125, 300, 100);
    yourScore->setGeometry(135, 225, 250, 100);
    bestScore->setGeometry(110, 300, 300, 100);
    playButton->setGeometry(100, 425, 300, 100);
    backButton->setGeometry(100, 550, 300, 100);

    this->addWidget(title);
    this->addWidget(gameState);
    this->addWidget(yourScore);
    this->addWidget(bestScore);
    this->addWidget(playButton);
    this->addWidget(backButton);
}

void KillCovidScene::startGame(){
    this->removeItem(title->graphicsProxyWidget());
    this->removeItem(gameState->graphicsProxyWidget());
    this->removeItem(yourScore->graphicsProxyWidget());
    this->removeItem(bestScore->graphicsProxyWidget());
    this->removeItem(playButton->graphicsProxyWidget());
    this->removeItem(backButton->graphicsProxyWidget());

    QDir().mkdir("data");
    QString username = player->getUsername();
    QDir().mkdir("data/" + username);
    std::string path = "data/" + username.toStdString() + "/G1.txt";

    std::ofstream ofs(path);
    ofs << 0 << " " << 150 << " ";
    if (player->getG1Difficulty() == 1){ ofs << 5 << " " << 1 << '\n'; }
    else if (player->getG1Difficulty() == 2) { ofs << 3 << " " << 1 << '\n'; }
    else{ ofs << 3 << " " << 2 << '\n'; }

    //Set initial state
    std::string empty(4, '.');
    std::string playerPos = empty; playerPos[3] = 'x';
    ofs << empty << '\n' << empty << '\n' << empty << '\n' << playerPos << '\n';
    for(int i = 4; i < 10; i++){
        if (i == 6 || i == 8){
            int j = rand() % 4;
            int type = rand() % 3;
            std::string virusPos = empty;
            virusPos[j] = '0'+type;
            ofs << virusPos<<'\n';
        }
        else { ofs << empty << '\n'; }
    }
    ofs.close();

    continueGame();
}

void KillCovidScene::continueGame(){
    gameStarted = true; shooting = false;

    QString username = player->getUsername();
    std::string path = "data/" + username.toStdString() + "/G1.txt";
    std::ifstream ifs(path);

    int curScore, neededS, chancesLeft, curSpeed;
    ifs >> curScore >> neededS >> chancesLeft >> curSpeed;
    score = curScore;
    chances = chancesLeft;
    neededScore = neededS;
    speed = curSpeed;

    for(int i = 0; i < 10; i++){
        std::string s; ifs >> s;
        for(int j = 0; j < 4; j++){
            if (s[j] == 'x'){
                syringe = new Syringe(j + 1, i + 1, speed);
                addItem(syringe);
            }
            else if (s[j] != '.'){
                int type = s[j]-'0';
                Virus* virus = new Virus(type, j+1, i+1, speed);
                viruses.push_back(virus);
                addItem(virus);
            }
        }
    }

    ifs.close();

    setGameButtons();
}

void KillCovidScene::setGameButtons(){
    speedLabel = new QLabel("Speed x" + QString::number(speed));
    speedLabel->setStyleSheet("font: 25px; color: white; background-color: rgba(0,0,0,0%)");
    speedLabel->setGeometry(15, 0, 150, 75);

    scoreLabel = new QLabel("Score " + QString::number(score));
    scoreLabel->setStyleSheet("font: 25px; color: white; background-color: rgba(0,0,0,0%)");
    scoreLabel->setGeometry(200, 0, 150, 75);

    chancesLabel = new QLabel(QString::number(chances) + " chances");
    chancesLabel->setStyleSheet("font: 25px; color: white; background-color: rgba(0,0,0,0%)");
    chancesLabel->setGeometry(350, 0, 125, 75);

    saveExit = new QPushButton("Save and Exit");
    saveExit->setStyleSheet("font: 13px; color: red;");
    saveExit->setGeometry(375, 75, 100, 50);

    this->addWidget(speedLabel);
    this->addWidget(scoreLabel);
    this->addWidget(chancesLabel);
    this->addWidget(saveExit);

    QObject::connect(saveExit, SIGNAL(clicked(bool)), this, SLOT(saveAndExit()));

    virusAdder = new QTimer(this);
    QObject::connect(virusAdder, SIGNAL(timeout()), this, SLOT(addVirus()));
    virusAdder->start(4000 - 100 * speed);
    QString username = player->getUsername();
    std::string path = "data/" + username.toStdString() + "/G1.txt";
    ofsV = std::ofstream(path, std::ofstream::app);

    checker = new QTimer(this);
    QObject::connect(checker, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    checker->start(500);

   arrow = new Arrow(syringe->xC, syringe->yC, speed);
   addItem(arrow);
}

void KillCovidScene::saveAndExit(){
    int nx = (syringe->x()+94)/95, ny = (-syringe->y()+779)/80;
    checker->stop();
    virusAdder->stop();
    ofsV.close();

    QString username = player->getUsername();
    std::string path = "data/" + username.toStdString() + "/G1.txt";
    if (QFile().exists("data/" + username + "/G1.txt")){
        std::ifstream ifs(path);

        int tmp; for(int i = 0; i < 4; i++){ ifs>>tmp; }
        QVector<std::string> S;
        while(true){
            std::string s;
            getline(ifs, s);
            if (ifs.fail()){ break; }
            S.push_back(s);
        }
        ifs.close();

        int n = S.size();
        int yy = n - 10 + ny - 1;
        S[yy][nx - 1] = 'x';
        if (yy < n-1){ S[yy+1][nx-1] = '.'; }
        std::string empty(4, '.');
        std::ofstream ofs(path);

        ofs << score << " " << 150 << " " << chances << " " << speed<<'\n';
        for(int i = n - 10; i < n; i++){
            if (i < yy){ ofs << empty << '\n'; }
            else { ofs << S[i] << '\n'; }
        }
        ofs.close();
    }
    goBack();
}

void KillCovidScene::endGame(bool won){
    checker->stop();
    virusAdder->stop();
    ofsV.close();
    for(int i = 0; i < viruses.size(); i++){
        removeItem(viruses[i]);
        delete viruses[i];
    }
    viruses.clear();
    removeItem(arrow);
    delete arrow;
    removeItem(syringe);
    delete syringe;

    QString username = player->getUsername();
    QString path = "data/" + username + "/G1.txt";
    QFile().remove(path);

    this->removeItem(speedLabel->graphicsProxyWidget());
    this->removeItem(scoreLabel->graphicsProxyWidget());
    this->removeItem(chancesLabel->graphicsProxyWidget());
    this->removeItem(saveExit->graphicsProxyWidget());

    yourScoreVal = score;
    bestScoreVal = std::max(bestScoreVal, yourScoreVal);

    QVector<int> scoresG1 = player->getScoresG1();
    scoresG1.push_back(score);
    if (scoresG1.size() > 10){ scoresG1.removeAt(0); }
    player->setScoresG1(scoresG1);
    player->updateMaxScoreG1(score);
    player->writeOnFile();

    usersData::tryUpdateMaxG1(score);

    setInitialButtons(won?1:2);
    setInitialGridLayout();
}

void KillCovidScene::keyPressEvent(QKeyEvent *event){
    if(!gameStarted && event->key()==Qt::Key_F1) { startGame(); }
    else if (gameStarted && !shooting){ shoot(); }
}

void KillCovidScene::goBack(){
    Helper::openWidget(new GameChoiceWidget(player));
    Helper::closeView();
}

void KillCovidScene::showArrow(){
    arrow->xC = syringe->xC;
    arrow->yC = syringe->yC;
    arrow->initializePos();
    arrow->show();
    shooting = false;
}

void KillCovidScene::shoot(){
    syringe->shoot(arrow->rotation());
    arrow->hide();
    shooting = true;
}

void KillCovidScene::addVirus(){
    std::string empty(4, '.');
    int j = rand() % 4;
    int type = rand() % 3;
    std::string virusPos = empty;
    virusPos[j] = '0'+type;
    if (ofsV.is_open()){ ofsV << virusPos<< '\n' << empty << '\n'; }

    Virus* virus = new Virus(type, j+1, 10, speed);
    viruses.push_back(virus);
    addItem(virus);
}

void KillCovidScene::changeSpeed(int nSpeed){
    if (nSpeed > 16){ nSpeed = 16; }

    speed = nSpeed;
    speedLabel->setText("Speed x" + QString::number(speed));

    if (arrow) { arrow->changeSpeed(speed); }
    syringe->changeSpeed(speed);


    QVector<Virus*> curViruses;
    for(int i = 0; i < viruses.size(); i++){
        if (viruses[i]->isVisible()){
            viruses[i]->changeSpeed(speed);
            curViruses.push_back(viruses[i]);
        }
        else{ delete viruses[i]; }
    }
    viruses = curViruses;

    virusAdder->stop();
    virusAdder->start(4000 - 150 * speed);
}

void KillCovidScene::checkCollisions(){
    for(QGraphicsItem *col : collidingItems(syringe)){
        Virus *v = dynamic_cast<Virus*>(col);
        if (v==nullptr){ continue; }
        if (v->dead){ continue; }

        int nx = (v->x()+94)/95, ny = (-v->y()+700+79)/80;

        v->smashed();
        killed++;
        if (killed % 5 == 0){ changeSpeed(speed == 1 ? 2 : speed + 2); }

        if (v->type == 0){ if (score + 3 <= 150) score += 3; }
        else if (v->type == 1){ if (score + 5 <= 150) score += 5; }
        else{ if (score + 7 <= 150) score += 7; }
        scoreLabel->setText("Score " + QString::number(score));

        syringe->shooter->stop();
        syringe->xC = nx; syringe->yC = ny;
        syringe->initializePos();
        showArrow();
        arrow->setZValue(1);
        syringe->setZValue(1);

        if (score == 150){ endGame(true); }
        return;
    }

    if (syringe->x() < 75){
        chances--;
        syringe->shooter->stop();
        syringe->xC = 1; syringe->yC = (-syringe->y()+779)/80;
        syringe->initializePos();
        showArrow();
    }
    else if (syringe->x() > 400){
        chances--;
        syringe->shooter->stop();
        syringe->xC = 4; syringe->yC = (-syringe->y()+779)/80;
        syringe->initializePos();
        showArrow();
    }

    int limit = 600;
    if (syringe->y() > limit || syringe->y() < -100){ endGame(false); return; }

    for(int i = 0; i < viruses.size(); i++){
        if (viruses[i]->y() > limit){
            viruses[i]->hide();
            if (!viruses[i]->dead){ chances--; }
            viruses[i]->dead = true;
        }
    }

    chancesLabel->setText(QString::number(chances) + (chances == 1 ? " chance" : " chances"));
    if (chances < 0){ endGame(false); return; }
}
