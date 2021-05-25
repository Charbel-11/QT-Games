/**
  * \file signinwidget.h
  * \brief Widget where a user can sign in
  */
#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include <QtWidgets>

class SignInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignInWidget(QWidget *parent = nullptr);
    QLabel *title, *usernameLabel, *passwordLabel, *errorMsg;
    QLineEdit *usernameBox, *passwordBox;
    QPushButton *backButton, *submitButton;

    QVBoxLayout *gridLayout;

    void setGridLayout();

public slots:
    /**
     * @brief Goes back to the authentication screen
     */
    void goBack();

    /**
     * @brief Checks if the data entered is valid. If so, signs in.
     */
    void trySigningIn();
};

#endif // SIGNINWIDGET_H
