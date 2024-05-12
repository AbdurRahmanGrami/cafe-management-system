#pragma once
#include <string>
using namespace std;

class User {
public:
    User(); // Default constructor
    User(const string& userID, const string& userName, const string& password);
    virtual ~User(); // Virtual destructor

    virtual void Register();
    bool Login();
   

    // Getter method declarations
    string getUserID() const;
    string getUserName() const;
    string getPassword() const;

private:
    string userID;
    string userName;
    string password;

};
