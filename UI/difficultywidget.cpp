#include "difficultywidget.h"

DifficultyWidget::DifficultyWidget(user* _player, int _gameID, QWidget *parent) : QWidget(parent)
{
    player = _player; gameID = _gameID;
    title = new QLabel("Choose Difficulty");
    title->setStyleSheet("font: 50px");
    setWindowTitle("Choose Difficulty");

    easyB = new QRadioButton("Easy");
    easyB->setStyleSheet("font: 30px");
    mediumB = new QRadioButton("Medium");
    mediumB->setStyleSheet("font: 30px");
    hardB = new QRadioButton("Hard");
    hardB->setStyleSheet("font: 30px");

    int curD = player->getG1Difficulty();
    if (gameID == 2){ curD = player->getG2Difficulty(); }

    if (curD == 1){ easyB->setChecked(true); }
    else if (curD == 2){ mediumB->setChecked(true); }
    else { hardB->setChecked(true); }

    if (gameID == 1){
        easyD = new QLabel("1x initial speed, 5 misses allowed");
        easyD->setStyleSheet("font: 20px");
        mediumD = new QLabel("1x initial speed, 3 misses allowed");
        mediumD->setStyleSheet("font: 20px");
        hardD = new QLabel("2x initial speed, 3 misses allowed");
        hardD->setStyleSheet("font: 20px");
    }
    else{
        easyD = new QLabel("15 min to make moves");
        easyD->setStyleSheet("font: 20px");
        mediumD = new QLabel("10 min to make moves");
        mediumD->setStyleSheet("font: 20px");
        hardD = new QLabel("5 min to make moves");
        hardD->setStyleSheet("font: 20px");
    }

    confirmB = new QPushButton("Confirm");
    confirmB->setStyleSheet("background-color: green; font: 30px;");
    confirmB->setFixedSize(QSize(250, 100));

    setGridLayout();
    setLayout(layout);

    QObject::connect(confirmB, SIGNAL(clicked(bool)), this, SLOT(confirmChoice()));
}

void DifficultyWidget::setGridLayout(){
    QGroupBox *diffGroup = new QGroupBox;
    QVBoxLayout *boxLayout = new QVBoxLayout;
    boxLayout->addWidget(easyB, 0, Qt::AlignCenter);
    boxLayout->addWidget(mediumB, 0, Qt::AlignCenter);
    boxLayout->addWidget(hardB, 0, Qt::AlignCenter);
    diffGroup->setLayout(boxLayout);

    QVBoxLayout *Descriptions = new QVBoxLayout;
    Descriptions->addWidget(easyD);
    Descriptions->addWidget(mediumD);
    Descriptions->addWidget(hardD);

    QHBoxLayout *tmp = new QHBoxLayout;
    tmp->addWidget(diffGroup);
    tmp->addItem(new QSpacerItem(50, 50));
    tmp->addItem(Descriptions);

    layout = new QVBoxLayout;
    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addItem(tmp);
    layout->addItem(new QSpacerItem(75, 75));
    layout->addWidget(confirmB, 0, Qt::AlignCenter);
    layout->addItem(new QSpacerItem(50, 50));
}

void DifficultyWidget::confirmChoice(){
    int difficulty = 1;
    if (mediumB->isChecked()){ difficulty = 2; }
    else if (hardB->isChecked()){ difficulty = 3; }

    if (gameID == 1){ player->setG1Difficulty(difficulty); }
    else { player->setG2Difficulty(difficulty); }

    if (player->getUsername() != "Guest")
        player->writeOnFile();  //Override the player settings

    Helper::openWidget(new gameInfoWidget(gameID, player));
    this->close();
}
