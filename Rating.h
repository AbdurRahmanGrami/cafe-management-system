#pragma once
#include <string>
#include "Customer.h"
using namespace std;

class Rating: public Customer {
public:
    // Members
    int RatingID;
    int MenuItemID;
    int Score;
    int CustomerID;
    string Comment;

    // Constructor
    Rating();
    Rating(int ratingID, int menuItemID, int customerID, int score, const string& comment);

    // Getters
    int GetRatingID() const;
    int GetMenuItemID() const;
    int GetScore() const;
    const string& GetComment() const;
    int GetCustomerID() override;

    void Rate() const;
};
