/**
  * \file usersdata.h
  * \brief Stores the information of all registered users
  */
#ifndef USERSDATA_H
#define USERSDATA_H

#include <vector>
#include <QString>
#include <user.h>

class usersData
{
public:
    usersData();
    static std::vector<int> topScoresG1, topScoresG2;

    /**
     * @brief Adds a new user to the class
     * @param newUser The new user to be added
     */
    static void addUser(user* newUser);

    /**
     * @brief Extracts all the information about registered users
     */
    static void readAllUsers();

    /**
     * @brief Checks whether a username is already taken
     * @param u The username to check
     * @return true if the username was already taken, false otherwise
     */
    static bool containsUsername(const QString &u);

    /**
     * @brief Checks whether this combination of username/password is valid
     * @param username The username to check
     * @param password The password to check
     * @return A pointer to the user if the combination is valid, NULL otherwise
     */
    static user* correctUserPass(const QString &username, const QString &password);

    /**
     * @brief Gets the overall max score in Game 1
     * @return The max score in Game 1
     */
    static int getMaxG1();

    /**
     * @brief Gets the overall max score in Game 2
     * @return The max score in Game 2
     */
    static int getMaxG2();

    /**
     * @brief Tries to update the max 3 scores for G1 and saves them on file
     */
    static void tryUpdateMaxG1(int nScore);

    /**
     * @brief Tries to update the max 3 scores for G2 and saves them on file
     */
    static void tryUpdateMaxG2(int nScore);

private:
    static std::vector<user*> allUsers;
};

#endif // USERSDATA_H
