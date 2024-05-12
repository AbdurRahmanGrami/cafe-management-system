#pragma once
#include "User.h"
#include "MenuItem.h"
#include "Rating.h"
#include <string>
#include <fstream>

class Administrator : public User {
private:
    static const int MAX_MENU_ITEMS = 100;
    static MenuItem* facultyMenu;
    static MenuItem* studentMenu;
    static MenuItem* nonFacultyMenu;

    static int facultyMenuCount;
    static int studentMenuCount;
    static int nonFacultyMenuCount;

    MenuItem* menu; // Pointer for dynamic allocation
    int itemCount;

    static const int MAX_INVENTORY_ITEMS = 100;
    static const int MAX_ORDER_HISTORY_ITEMS = 100;
    static const int MAX_NOTIFICATIONS = 100;

    string* inventory; // Pointer for dynamic allocation
    string* orderHistory; // Pointer for dynamic allocation
    string* notifications; // Pointer for dynamic allocation

    int inventoryCount;
    int orderHistoryCount;
    int notificationCount;

    void displayMenuWithIDs(ifstream& menuFile) const;
    void displayExistingRatings(int menuItemID, ifstream& ratingFile) const;
    void displayExistingDiscounts(int menuItemID, ifstream& discountFile) const;    
    bool isValidMenuItemID(int menuItemID, ifstream& file) const;

public:
    Administrator(); // Constructor
    ~Administrator(); // Destructor

    void ViewMenu() const;
    void AddMenuItem();
    void RemoveMenuItem();
    void ManageInventory();
    void ManageDiscountPromotion();
    void ViewOrderHistory();
    void AddNotification();
    void RemoveNotification();
    void RateMenuItem();
    void DisplayFromFile();
    void ViewUsersFromFile();
    void ViewMenuItemsFromFile();
    void ViewOrdersFromFile();
    void ViewRatingsFromFile();
    void ViewPaymentsFromFile();
    void CalculateMonthlyEarnings();
};