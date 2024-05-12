#include "Rating.h"
#include <iostream> 
using namespace std;

Rating::Rating() : RatingID(0), MenuItemID(0), CustomerID(0), Score(0), Comment("") {
}

Rating::Rating(int ratingID, int menuItemID, int customerID, int score, const string& comment)
    : RatingID(ratingID), MenuItemID(menuItemID), CustomerID(customerID), Score(score), Comment(comment) {
}

int Rating::GetRatingID() const {
    return RatingID;
}

int Rating::GetMenuItemID() const {
    return MenuItemID;
}

int Rating::GetScore() const {
    return Score;
}

const std::string& Rating::GetComment() const {
    return Comment;
}

int Rating::GetCustomerID()  {
   
    return CustomerID; 
}

void Rating::Rate() const {
    cout << "Rating menu item " << MenuItemID << " by customer " << CustomerID << "...\n";
    cout << "Rating: " << Score << "/5\n";
    cout << "Comment: " << Comment << "\n";
}