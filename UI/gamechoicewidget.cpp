#include "gamechoicewidget.h"
#include "authenticationwidget.h"
#include "gameinfowidget.h"
#include "helper.h"

GameChoiceWidget::GameChoiceWidget(user* _player, QWidget *parent) : QWidget(parent)
{
    player = _player;

    setWindowTitle("Choose Games");
    title = new QLabel("Choose a Game");
    title->setStyleSheet("font: 50px");

    name = new QLabel(player->getUsername());
    name->setStyleSheet("font: 40px");
    pic = new QLabel();
    QPixmap pp = player->getProfilePicture();
    if (!pp.isNull()) { pic->setPixmap(pp.scaled(100, 100, Qt::KeepAspectRatio)); }
    pic->setStyleSheet("font: 40px");
    pic->setFixedSize(100, 100);

    game1Name = new QLabel("Kill Covid-19");
    game1Name->setAlignment(Qt::AlignCenter);
    game1Name->setStyleSheet("font: 30px");
    game2Name = new QLabel("Reversi");
    game2Name->setAlignment(Qt::AlignCenter);
    game2Name->setStyleSheet("font: 30px");

    game1Button = new QPushButton();
    game1Button->setFixedSize(QSize(215, 300));
    game1Button->setIcon(QIcon(":/images/covidPic.jpeg"));
    game1Button->setIconSize(QSize(350, 350));
    game2Button = new QPushButton();
    game2Button->setFixedSize(QSize(215, 300));
    game2Button->setIcon(QIcon(":/images/ReversiLogo.png"));
    game2Button->setIconSize(QSize(215, 300));

   //Used to wish a happy birthday on the user's birthday
    message = new QLabel("");
    QDate today = QDate().currentDate();
    if (player->getDOB().day() == today.day() && player->getDOB().month() == today.month()){
        message->setText("Happy birthday!!!");
    }
    message->setStyleSheet("font: 30px");
    message->setAlignment(Qt::AlignCenter);

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(QSize(125, 75));

    //Sets the layout
    layout = new QVBoxLayout;
    setGridLayout();
    setLayout(layout);

    //Connects the signals to the slots
    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
    QObject::connect(game1Button, SIGNAL(clicked(bool)), this, SLOT(openGame1Info()));
    QObject::connect(game2Button, SIGNAL(clicked(bool)), this, SLOT(openGame2Info()));
}

void GameChoiceWidget::setGridLayout(){
    QGridLayout *topLeftLayout = new QGridLayout;
    topLeftLayout->addWidget(name, 0, 0);
    topLeftLayout->addWidget(pic, 1, 0, 1, 3);

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addItem(topLeftLayout, 0, 0, Qt::AlignLeft);
    topLayout->addWidget(title, 0, 1, Qt::AlignCenter);
    topLayout->addWidget(backButton, 0, 2, Qt::AlignRight);

    QGridLayout *middleLayout = new QGridLayout;
    middleLayout->addWidget(game1Name, 0, 1);
    middleLayout->addWidget(game2Name, 0, 3);
    middleLayout->addItem(new QSpacerItem(10, 20), 1, 1);
    middleLayout->addWidget(game1Button, 2, 1);
    middleLayout->addWidget(game2Button, 2, 3);

    layout->addItem(topLayout);
    layout->addItem(new QSpacerItem(0, 50));
    layout->addItem(middleLayout);
    layout->addWidget(message, 0, Qt::AlignBottom);
    layout->setSpacing(0);
}

void GameChoiceWidget::openGame1Info(){
    Helper::openWidget(new gameInfoWidget(1, player));
    this->close();
}

void GameChoiceWidget::openGame2Info(){
    Helper::openWidget(new gameInfoWidget(2, player));
    this->close();
}

void GameChoiceWidget::goBack(){
    Helper::openWidget(new AuthenticationWidget);
    this->close();
}
