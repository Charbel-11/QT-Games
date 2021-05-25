#include "user.h"
#include <fstream>
#include <QBuffer>
#include <QFile>
#include <string>
#include <QDir>

user::user() { }

QString user::getUsername() const {  return username; }
void user::setUsername(const QString &_u) { username = _u;}

QString user::getPassword() const { return password;}
void user::setPassword(const QString &_p) {  password = _p; }

QString user::getFirstName() const { return firstName; }
void user::setFirstName(const QString &_fn) { firstName = _fn;}

QString user::getLastName() const { return lastName;}
void user::setLastName(const QString &_ln) { lastName = _ln;}

QDate user::getDOB() const {  return dateOfBirth;}
void user::setDOB(const QDate &adateOfBirth) { dateOfBirth = adateOfBirth;}

bool user::getGender() const { return gender; }
void user::setGender(const bool _g) { gender = _g; }

QPixmap user::getProfilePicture() const { return profilePicture; }
void user::setProfilePicture(const QPixmap &_pp) { profilePicture = _pp; }

QVector<int> user::getScoresG1() const { return scoresG1; }
void user::setScoresG1(const QVector<int> &_scoresG1) { scoresG1 = _scoresG1; }

QVector<int> user::getScoresG2() const { return scoresG2; }
void user::setScoresG2(const QVector<int> &_scoresG2) { scoresG2 = _scoresG2; }

int user::getG1Difficulty() const { return game1Difficulty; }
void user::setG1Difficulty(const int _d){ game1Difficulty = _d; }

int user::getG2Difficulty() const { return game2Difficulty; }
void user::setG2Difficulty(const int _d){ game2Difficulty = _d; }

int user::getMaxScoreG1() const { return maxScoreG1; }
void user::updateMaxScoreG1(const int _score){ maxScoreG1 = std::max(maxScoreG1, _score); }

int user::getMaxScoreG2() const { return maxScoreG2; }
void user::updateMaxScoreG2(const int _score){ maxScoreG2 = std::max(maxScoreG2, _score); }


void user::writeOnFile() const{
    //Creates a data folder in case it doesn't exist
    QDir().mkdir("data");
    QDir().mkdir("data/" + username);

    std::string dirP = "data/" + username.toStdString();
    std::ofstream ofs(dirP + "/account.txt");  //Open the file

    ofs << username.toStdString() << '\n';
    ofs << password.toStdString() << '\n';
    ofs << firstName.toStdString() <<'\n';
    ofs << lastName.toStdString() << '\n';
    ofs << dateOfBirth.toString().toStdString() << '\n';
    ofs << gender << '\n';

    ofs << scoresG1.size() << ' ';
    for(auto &x : scoresG1) { ofs << x << ' '; }
    ofs << '\n';
    ofs << scoresG2.size() << ' ';
    for(auto &x : scoresG2) { ofs << x << ' '; }
    ofs << '\n';

    ofs << maxScoreG1 << '\n';
    ofs << maxScoreG2 << '\n';

    ofs << game1Difficulty << '\n';
    ofs << game2Difficulty << '\n';

    //Stores the picture on its own png file
    QString path = "data/" + username + "/pic.png";
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    profilePicture.save(&file, "PNG");
}
