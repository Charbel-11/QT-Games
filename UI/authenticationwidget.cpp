#include "authenticationwidget.h"
#include <signinwidget.h>
#include <signupwidget.h>
#include <gamechoicewidget.h>
#include <user.h>
#include <helper.h>
#include <usersdata.h>

AuthenticationWidget::AuthenticationWidget(QWidget *parent) : QWidget(parent) {
    //Initialize components
    setWindowTitle("QT Games");
    usersData::readAllUsers();       //Gather all previously registered players' info

    welcomeLabel = new QLabel("Welcome");
    welcomeLabel->setStyleSheet("font: 60px");

    QSize size(300, 100);
    signInButton = new QPushButton("Sign In");
    signInButton->setFixedSize(size);
    signInButton->setStyleSheet("font: 30px");

    signUpButton = new QPushButton("Sign Up");
    signUpButton->setFixedSize(size);
    signUpButton->setStyleSheet("font: 30px");

    guestButton = new QPushButton("Play as Guest");
    guestButton->setFixedSize(size);
    guestButton->setStyleSheet("font: 30px");

//    names = new QLabel("By Charbel Chucri");
    names = new QLabel();

   //Sets the layout
    gridLayout = new QVBoxLayout;
    setGridLayout();
    setLayout(gridLayout);

    //Connects the signals to the slots
    QObject::connect(signInButton, SIGNAL(clicked(bool)), this, SLOT(openSignInMenu()));
    QObject::connect(signUpButton, SIGNAL(clicked(bool)), this, SLOT(openSignUpMenu()));
    QObject::connect(guestButton, SIGNAL(clicked(bool)), this, SLOT(playAsGuest()));
}

void AuthenticationWidget::setGridLayout(){
    gridLayout->addItem(new QSpacerItem(10, 30));
    gridLayout->addWidget(welcomeLabel, 1, Qt::AlignCenter);
    gridLayout->addItem(new QSpacerItem(10, 20));
    gridLayout->addWidget(signInButton, 1, Qt::AlignCenter);
    gridLayout->addWidget(signUpButton, 1, Qt::AlignCenter);
    gridLayout->addWidget(guestButton, 1, Qt::AlignCenter);
    gridLayout->addWidget(names, 1, Qt::AlignBottom | Qt::AlignRight);

    gridLayout->setSpacing(30);
}

void AuthenticationWidget::openSignInMenu(){
    Helper::openWidget(new SignInWidget);
    this->close();
}

void AuthenticationWidget::openSignUpMenu(){
    Helper::openWidget(new signupWidget);
    this->close();
}

void AuthenticationWidget::playAsGuest(){
    user* guest = new user();
    guest->setFirstName("NA");
    guest->setLastName("NA");
    guest->setUsername("Guest");
    guest->setPassword("NA");
    guest->setGender(1);
    guest->setDOB(QDate(QDate().currentDate().year(), QDate().currentDate().month(), (QDate().currentDate().day()+28)%29));
    guest->setG1Difficulty(1);
    guest->setG2Difficulty(1);

    QString path = "data/Guest/G1.txt";
    QFile().remove(path);
    path = "data/Guest/G2.txt";
    QFile().remove(path);

    Helper::openWidget(new GameChoiceWidget(guest));
    this->close();
}

