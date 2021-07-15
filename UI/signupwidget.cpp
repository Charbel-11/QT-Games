#include "signupwidget.h"
#include "helper.h"
#include "authenticationwidget.h"
#include "gamechoicewidget.h"
#include "../Users/usersdata.h"

signupWidget::signupWidget(QWidget *parent) : QWidget(parent)
{
    //Initialize widgets
    QSize size(250, 75);
    title = new QLabel("Sign Up");
    title->setStyleSheet("font: 60px");
    setWindowTitle("Sign Up");

    firstNameLabel = new QLabel("First Name");
    firstNameLabel->setStyleSheet("font: 30px");

    lastNameLabel = new QLabel("Last Name");
    lastNameLabel->setStyleSheet("font: 30px");

    usernameLabel = new QLabel("Username");
    usernameLabel->setStyleSheet("font: 30px");

    passwordLabel = new QLabel("Password");
    passwordLabel->setStyleSheet("font: 30px");

    confirmpasswordLabel = new QLabel(" Confirm\nPassword");
    confirmpasswordLabel->setStyleSheet("font: 30px");

    birthdayLabel = new QLabel("Birthday");
    birthdayLabel->setStyleSheet("font: 30px");
    birthdayLabel->setAlignment(Qt::AlignCenter);

    picLabel = new QLabel("Profile Picture");
    picLabel->setStyleSheet("font: 30px");
    picLabel->setAlignment(Qt::AlignCenter);
    pic = new QLabel();
    pic->setFixedSize(150, 150);

    errorMsg = new QLabel();
    errorMsg->setStyleSheet("font: 20px; color: red");

    birthdayWidget = new QCalendarWidget();

    firstNameLineEdit = new QLineEdit;
    firstNameLineEdit->setStyleSheet("font: 30px");
    lastNameLineEdit = new QLineEdit;
    lastNameLineEdit->setStyleSheet("font: 30px");
    usernameLineEdit = new QLineEdit;
    usernameLineEdit->setStyleSheet("font: 30px");
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setStyleSheet("font: 30px");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    confirmpasswordLineEdit = new QLineEdit;
    confirmpasswordLineEdit->setStyleSheet("font: 30px");
    confirmpasswordLineEdit->setEchoMode(QLineEdit::Password);

    genderLabel = new QLabel("Gender");
    genderLabel->setStyleSheet("font: 30px");
    maleRadioButton = new QRadioButton("Male");
    maleRadioButton->setStyleSheet("font: 20px");
    femaleRadioButton = new QRadioButton("Female");
    femaleRadioButton->setStyleSheet("font: 20px");

    browseButton = new QPushButton("Browse");
    browseButton->setStyleSheet("font: 30px");

    backButton = new QPushButton("Back");
    backButton->setStyleSheet("background-color: red; font: 40px;");
    backButton->setFixedSize(size);

    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("background-color: green; font: 40px;");
    submitButton->setFixedSize(size);

    mainVBoxLayout = new QVBoxLayout;

    setInternalLayout();
    setLayout(mainVBoxLayout);

    QObject::connect(submitButton, SIGNAL(clicked(bool)), this, SLOT(trySigningUp()));
    QObject::connect(browseButton, SIGNAL(clicked(bool)), this, SLOT(browsePicture()));
    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(goBack()));
}

void signupWidget::setInternalLayout(){
    //Setting gender group box
    QGroupBox *genderGroup = new QGroupBox;
    QHBoxLayout *tempGenderLayout = new QHBoxLayout;
    tempGenderLayout->addWidget(maleRadioButton);
    tempGenderLayout->addWidget(femaleRadioButton);
    genderGroup->setLayout(tempGenderLayout);
    genderGroup->setFixedSize(230, 75);

    //Setting buttons
    QGridLayout *buttonsLayout = new QGridLayout;
    buttonsLayout->addWidget(backButton, 0, 0);
    buttonsLayout->addItem(new QSpacerItem(10, 10), 0, 1);
    buttonsLayout->addWidget(submitButton, 0, 2);

    QGridLayout *leftGrid = new QGridLayout;
    QVBoxLayout *rightGrid = new QVBoxLayout;

    //Setting the core layout
    leftGrid->addWidget(firstNameLabel,0,0);
    leftGrid->addWidget(firstNameLineEdit,0,1);
    leftGrid->addWidget(lastNameLabel,1,0);
    leftGrid->addWidget(lastNameLineEdit,1,1);
    leftGrid->addWidget(usernameLabel,2,0);
    leftGrid->addWidget(usernameLineEdit,2,1);
    leftGrid->addWidget(passwordLabel,3,0);
    leftGrid->addWidget(passwordLineEdit, 3,1);
    leftGrid->addWidget(confirmpasswordLabel, 4,0);
    leftGrid->addWidget(confirmpasswordLineEdit, 4,1);
    leftGrid->addWidget(genderLabel,5,0);
    leftGrid->addWidget(genderGroup, 5, 1);
    leftGrid->setSpacing(10);

    QHBoxLayout *picSpaced = new QHBoxLayout;
    picSpaced->addItem(new QSpacerItem(0, 10));
    picSpaced->addWidget(pic);
    picSpaced->addItem(new QSpacerItem(0, 10));

    rightGrid->addWidget(birthdayLabel);
    rightGrid->addWidget(birthdayWidget);
    rightGrid->addWidget(picLabel);
    rightGrid->addItem(picSpaced);
    rightGrid->addWidget(browseButton);
    rightGrid->addItem(new QSpacerItem(10, 5));
    rightGrid->setSpacing(10);
    rightGrid->setMargin(10);

    QHBoxLayout *separator = new QHBoxLayout;
    separator->addItem(leftGrid);
    separator->addItem(new QSpacerItem(50, 10));
    separator->addItem(rightGrid);

    mainVBoxLayout->addWidget(title, 1, Qt::AlignCenter);
    mainVBoxLayout->addWidget(errorMsg);
    mainVBoxLayout->addItem(separator);
    mainVBoxLayout->addItem(buttonsLayout);
    mainVBoxLayout->addItem(new QSpacerItem(10, 20));
}

void signupWidget::goBack(){
    Helper::openWidget(new AuthenticationWidget);
    this->close();
}

void signupWidget::browsePicture(){
    //Can choose any file of type png, jpg, jpeg or bmp
    QString pictureFileName = QFileDialog::getOpenFileName(this, tr("Choose a picture"), "", tr("Images (*.png *.jpg *.jpeg *.bmp)"));

    //If the name is not empty, i.e. valid:
    if(QString::compare(pictureFileName, QString()) != 0 ){
        QImage image;
        if (image.load(pictureFileName)){
            image = image.scaledToWidth(pic->width(), Qt::SmoothTransformation);
            pic->setPixmap(QPixmap::fromImage(image).scaled(150, 150));
            pic->setAlignment(Qt::AlignCenter);
        }
        else{
            errorMsg->setText("Error occured while browsing for a picture");
        }
      }
}

bool signupWidget::strIsComplex(const QString &s){
    if (s.size() < 8){ return false; }
    bool low, up, num;
    low = up = num = false;

    for(auto &c : s){
        if ('0' <= c && c <= '9'){ num = true; }
        else if ('a' <= c && c <= 'z'){ low = true; }
        else if ('A' <= c && c <= 'Z'){ up = true; }
    }

    return (low && up && num);
}

void signupWidget::trySigningUp(){
    //Checks for empty fields
    bool emptyField = false;
    if (firstNameLineEdit->text() == ""){ emptyField = true; }
    else if (lastNameLineEdit->text() == ""){ emptyField = true; }
    else if (usernameLineEdit->text() == ""){ emptyField = true; }
    else if (passwordLineEdit->text() == ""){ emptyField = true; }
    else if (confirmpasswordLineEdit->text() == ""){ emptyField = true; }
    else if (!maleRadioButton->isChecked() && !femaleRadioButton->isChecked()){ emptyField = true; }
    else if (!pic->pixmap()) { emptyField = true; }
    if (emptyField){ errorMsg->setText("Some fields are empty"); return; }

    //Checks if the username is unique and not too long
    if (usersData::containsUsername(usernameLineEdit->text()) || usernameLineEdit->text() == "Guest"){ errorMsg->setText("This username is already taken"); return; }
    if (usernameLineEdit->text().size() > 20){ errorMsg->setText("Username is too long. It should be at most 20 characters"); return; }

    //Checks if password match
    if (passwordLineEdit->text() != confirmpasswordLineEdit->text()){
        errorMsg->setText("The passwords do not match");
        return;
    }

    //Checks if the password is strong enough
    if (!signupWidget::strIsComplex(passwordLineEdit->text())){
        errorMsg->setText("The password is not strong enough: It should consist of at least 8\ncharacters and contain at least one number, upper and lower case letter");
        return;
    }
    if (passwordLineEdit->text().size() > 30){ errorMsg->setText("Password is too long. It should be at most 30 characters"); return; }

    user* newUser = new user();
    newUser->setFirstName(firstNameLineEdit->text());
    newUser->setLastName(lastNameLineEdit->text());
    newUser->setUsername(usernameLineEdit->text());
    newUser->setPassword(passwordLineEdit->text());
    newUser->setGender(maleRadioButton->isChecked()?0:1);
    newUser->setDOB(birthdayWidget->selectedDate());
    newUser->setProfilePicture(*pic->pixmap());
    newUser->setG1Difficulty(1);
    newUser->setG2Difficulty(1);
    newUser->updateMaxScoreG1(0);
    newUser->updateMaxScoreG2(0);
    newUser->writeOnFile();
    usersData::addUser(newUser);

    Helper::openWidget(new GameChoiceWidget(newUser));
    this->close();
}
