#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

User::User() {

}

User::User(const string& userID, const string& userName, const string& password)
    : userID(userID), userName(userName), password(password) {
    cout << "Parameterized User constructor called" << endl;
}

User::~User() {
 
}

void User::Register() {
    string username, password;
    cout << "Enter username for registration: ";
    cin >> username;
    cout << "Enter password for registration: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        cout << "Registration successful." << endl;
    }
    else {
        cout << "Error opening file for registration." << endl;
    }
    file.close();
}

bool User::Login() {
    string username, password;
    cout << "Enter username for login: ";
    cin >> username;
    cout << "Enter password for login: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful." << endl;
            file.close();
            return true; // Login successful
        }
    }

    cout << "Login failed. Incorrect username or password." << endl;
    file.close();
    return false; // Login failed
}

// Getter method definitions
string User::getUserID() const {
    return userID;
}

string User::getUserName() const {
    return userName;
}

string User::getPassword() const {
    return password;
}