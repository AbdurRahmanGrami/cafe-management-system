#pragma once
#include "User.h"
#include <string>
using namespace std;

const int MAX_TABLES = 10;
const int MAX_HISTORY = 100; // Maximum number of order history entries
const int MAX_COMMENTS = 100; // Maximum number of comments

class Customer : public User {
public:
    // Default constructor
    Customer();

    // Parameterized constructor
    Customer(const string& userID, const string& userName, const string& password);

    virtual void ViewMenu() const; 
    virtual void PlaceOrder();
    virtual void LeaveAComment() const;
    virtual void ViewOrderHistory();
    virtual void ReserveTable();
    virtual int GetCustomerID();

    void SaveOrderHistory() const;
    void LoadOrderHistory();
    void SaveComments() const;
    void LoadComments();

protected:
    string userID;
    string userName;
    string password;
    string orderHistory[MAX_HISTORY];
    string comments[MAX_COMMENTS];
    int historyCount; // Count of order history entries
    int commentCount; // Count of comments
    int CustomerID;
};
