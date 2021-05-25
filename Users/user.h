/**
  * \file user.h
  * \brief Contains the information of a registered user
  */
#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QMap>
#include <QImage>
#include <QPixmap>

class user
{
public:
    user();

    QString getUsername() const;
    QString getPassword() const;
    QString getFirstName() const;
    QString getLastName() const;
    QDate getDOB() const;
    bool getGender() const;
    QPixmap getProfilePicture() const;
    QVector<int> getScoresG1() const;
    QVector<int> getScoresG2() const;
    int getG1Difficulty() const;
    int getG2Difficulty() const;
    int getMaxScoreG1() const;
    int getMaxScoreG2() const;

    void setUsername(const QString &_u);
    void setPassword(const QString &_p);
    void setFirstName(const QString &_fn);
    void setLastName(const QString &_ln);
    void setDOB(const QDate &_dob);
    void setGender(const bool _g);
    void setProfilePicture(const QPixmap &_pp);
    void setScoresG1(const QVector<int> &_scoreG1);
    void setScoresG2(const QVector<int> &_scoreG2);
    void setG1Difficulty(const int _d);
    void setG2Difficulty(const int _d);
    void updateMaxScoreG1(const int _score);
    void updateMaxScoreG2(const int _score);

    /**
     * @brief Writes all the needed information in a text file
     */
    void writeOnFile() const;

private:
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QDate dateOfBirth;
    bool gender;
    QPixmap profilePicture;
    QVector<int> scoresG1, scoresG2;
    int game1Difficulty, game2Difficulty;
    int maxScoreG1 = 0, maxScoreG2 = 0;
};

#endif // USER_H
