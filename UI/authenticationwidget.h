/**
  * \file authenticationwidget.h
  * \brief Initial screen where a user signs up, logs in or plays as guest
  */
#ifndef AUTHENTICATIONWIDGET_H
#define AUTHENTICATIONWIDGET_H

#include <QWidget>
#include <QtWidgets>

class AuthenticationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AuthenticationWidget(QWidget *parent = nullptr);
    QLabel *welcomeLabel, *names;
    QPushButton *signInButton, *signUpButton, *guestButton;

    QVBoxLayout *gridLayout;

    void setGridLayout();

public slots:
    /**
     * @brief Opens the Sign In menu
     */
    void openSignInMenu();
    /**
     * @brief Opens the Sign Up menu
     */
    void openSignUpMenu();
    /**
     * @brief Opens the main menu as a guest
     */
    void playAsGuest();
};

#endif // AUTHENTICATIONWIDGET_H
