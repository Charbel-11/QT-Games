#include "signinwidget.h"
#include <authenticationwidget.h>
#include <gamechoicewidget.h>
#include <helper.h>
#include <usersdata.h>

SignInWidget::SignInWidget(QWidget *parent) : QWidget(parent){
    //Initialize widgets
    QSize size(250, 100);
    title = new QLabel("Sign In");
    title->setStyleSheet("font: 60px");

    setWindowTitle("Sign In");

    usernameLabel = new QLabel("Username");
    usernameLabel->setStyleSheet("font: 40px");
    passwordLabel = new QLabel("Password");
    passwordLabel->setStyleSheet("font: 40px");

    usernameBox = new QLineEdit;
    usernameBox->setStyleSheet("font: 40px");
    passwordBox = new QLineEdit;
    passwordBox->setEchoMode(QLineEdit::Password);
    passwordBox->setStyleSheet("font: 40px");

    errorMsg = new QLabel();
    errorMsg->setStyleSheet("font: 20px; color: red");

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(size);

    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("background-color: green; font: 40px;");
    submitButton->setFixedSize(size);

    gridLayout = new QVBoxLayout;

    //Set layout
    setGridLayout();
    setLayout(gridLayout);

    //Connects the signals to slots
    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(trySigningIn()));
}

void SignInWidget::setGridLayout(){
    //Setting username/password
    QVBoxLayout *core = new QVBoxLayout;
    core->addWidget(errorMsg);
    core->addWidget(usernameLabel);
    core->addWidget(usernameBox);
    core->addItem(new QSpacerItem(10, 10));
    core->addWidget(passwordLabel);
    core->addWidget(passwordBox);
    core->setMargin(50);
    core->setSpacing(15);

    //Setting buttons
    QGridLayout *buttonsLayout = new QGridLayout;
    buttonsLayout->addWidget(backButton, 0, 0);
    buttonsLayout->addItem(new QSpacerItem(10, 10), 0, 1);
    buttonsLayout->addWidget(submitButton, 0, 2);

    gridLayout->addItem(new QSpacerItem(10, 20));
    gridLayout->addWidget(title, 1, Qt::AlignCenter);
    gridLayout->addItem(core);
    gridLayout->addItem(buttonsLayout);
    gridLayout->addItem(new QSpacerItem(10, 20));
}

void SignInWidget::goBack(){
    Helper::openWidget(new AuthenticationWidget);
    this->close();
}
void SignInWidget::trySigningIn(){
    user* player = usersData::correctUserPass(usernameBox->text(), passwordBox->text());

    if (player != nullptr){
        GameChoiceWidget *nextWidget = new GameChoiceWidget(player);
        Helper::openWidget(nextWidget);
        this->close();
    }
    else{
        errorMsg->setText("Username or Password is incorrect");
    }
}
