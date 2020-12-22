#include "usersdata.h"
#include <fstream>
#include <QDirIterator>
#include <iostream>

std::vector<user*> usersData::allUsers;
std::vector<int> usersData::topScoresG1;
std::vector<int> usersData::topScoresG2;

usersData::usersData() { }

void usersData::addUser(user *newUser){ allUsers.push_back(newUser); }

void usersData::readAllUsers(){
    allUsers.clear();

    std::vector<QString> usernames;
    QDirIterator it("data");
    while(it.hasNext()){
        it.next();
        if (it.fileName() != "" && it.fileName() != "." && it.fileName() != ".."){
            usernames.push_back(it.fileName());
        }
    }

    for(auto &s : usernames){
        std::ifstream ifs("data/" + s.toStdString() + "/account.txt");

        user* curUser = new user();
        //Extract the information from data.txt
        std::string curUsername, curPassword, curFirstName, curLastName;
        std::string date = "";
        int g1D, g2D;

        bool gender; int s1, s2;
        ifs >> curUsername; if (ifs.fail()){ break; }
        ifs >> curPassword >> curFirstName >> curLastName;
        for(int i = 0; i < 4; i++){
            std::string tmp; ifs >> tmp;
            date += tmp;
            if (i != 3){ date.push_back(' '); }
        }
        ifs >> gender;

        ifs >> s1;
        QVector<int> scores1(s1);
        for(auto &x : scores1){ ifs >> x; }
        ifs >> s2;
        QVector<int> scores2(s2);
        for(auto &x : scores2){ ifs >> x; }

        int maxScoreG1, maxScoreG2;
        ifs >> maxScoreG1 >> maxScoreG2;

        ifs >> g1D >> g2D;

        QPixmap pic; pic.load("data/" + s + "/pic.png");

        //Sets the user class
        QString help;
        curUser->setUsername(help.fromStdString(curUsername));
        curUser->setPassword(help.fromStdString(curPassword));
        curUser->setFirstName(help.fromStdString(curFirstName));
        curUser->setLastName(help.fromStdString(curLastName));
        curUser->setDOB(QDate().fromString(help.fromStdString(date)));
        curUser->setGender(gender);
        curUser->setProfilePicture(pic);
        curUser->setScoresG1(scores1);
        curUser->setScoresG2(scores2);
        curUser->setG1Difficulty(g1D);
        curUser->setG2Difficulty(g2D);
        curUser->updateMaxScoreG1(maxScoreG1);
        curUser->updateMaxScoreG2(maxScoreG2);

        allUsers.push_back(curUser);
    }

    QString pathG1 = "data/TopScoresG1.txt";
    QString pathG2 = "data/TopScoresG2.txt";
    topScoresG1.clear(); topScoresG1.resize(3, 0);
    topScoresG2.clear(); topScoresG2.resize(3, 0);
    if (QFile().exists(pathG1)){
        std::ifstream ifs(pathG1.toStdString());
        for(int i = 0; i < 3; i++){ ifs >> topScoresG1[i]; }
        ifs.close();
    }
    if (QFile().exists(pathG2)){
        std::ifstream ifs(pathG2.toStdString());
        for(int i = 0; i < 3; i++){ ifs >> topScoresG2[i]; }
        ifs.close();
    }
}

bool usersData::containsUsername(const QString &u){
    for(auto &it : allUsers){
        if (it->getUsername() == u){ return true; }
    }
    return false;
}

//Returns a pointer to the user class in case of successful sign in
user* usersData::correctUserPass(const QString &username, const QString &password){
    if (username == "Guest") { return nullptr; }
    for(const auto &it : allUsers){
        if (it->getUsername() == username){
            if(it->getPassword() == password){ return it; }
            return nullptr;
        }
    }
    return nullptr;
}

int usersData::getMaxG1(){
    return topScoresG1[0];
}

int usersData::getMaxG2(){
    return topScoresG2[0];
}

void usersData::tryUpdateMaxG1(int nScore){
    sort(topScoresG1.rbegin(), topScoresG1.rend());
    if (topScoresG1.back() >= nScore){ return; }

    topScoresG1.pop_back();
    topScoresG1.push_back(nScore);
    sort(topScoresG1.rbegin(), topScoresG1.rend());

    std::string path = "data/TopScoresG1.txt";
    std::ofstream ofs(path);
    for(int i = 0; i < 3; i++){ ofs << topScoresG1[i] << ' '; }
    ofs << '\n'; ofs.close();
}

void usersData::tryUpdateMaxG2(int nScore){
    sort(topScoresG2.rbegin(), topScoresG2.rend());
    if (topScoresG2.back() >= nScore){ return; }

    topScoresG2.pop_back();
    topScoresG2.push_back(nScore);
    sort(topScoresG2.rbegin(), topScoresG2.rend());

    std::string path = "data/TopScoresG2.txt";
    std::ofstream ofs(path);
    for(int i = 0; i < 3; i++){ ofs << topScoresG2[i] << ' '; }
    ofs << '\n'; ofs.close();
}
