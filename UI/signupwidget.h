/**
  * \file signupwidget.h
  * \brief Widget where a new user can sign up
  */
#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class signupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit signupWidget(QWidget *parent = nullptr);

private:
    QLabel *title;
    QLabel *firstNameLabel, *lastNameLabel;
    QLabel *usernameLabel, *passwordLabel, *confirmpasswordLabel;
    QLabel *birthdayLabel;
    QLabel *pic, *picLabel;
    QLabel *errorMsg;

    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmpasswordLineEdit;

    QCalendarWidget* birthdayWidget;

    QLabel *genderLabel;
    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;

    QGroupBox* pictureBox;

    QPushButton *browseButton;
    QPushButton *submitButton;
    QPushButton *backButton;

    QVBoxLayout *mainVBoxLayout;

    /**
     * @brief Sets the layout of the widget
     */
    void setInternalLayout();

    /**
     * @brief Checks that a string is complex
     * @param s The string to check
     * @return True if the string is complex, false otherwise
     */
    bool strIsComplex(const QString &s);

public slots:
    /**
     * @brief Goes back to the authentication screen
     */
    void goBack();

    /**
     * @brief Checks if data entered is valid. If so, signs the user up.
     */
    void trySigningUp();

    /**
     * @brief Allow for browsing a picture on the local PC
     */
    void browsePicture();
};

#endif // SIGNUPWIDGET_H
