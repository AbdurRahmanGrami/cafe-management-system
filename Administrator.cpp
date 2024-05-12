// Administrator.cpp
#include "Administrator.h"
#include "MenuItem.h"
#include "Rating.h"
#include "Payment.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Static member initialization
MenuItem* Administrator::facultyMenu = new MenuItem[Administrator::MAX_MENU_ITEMS];
MenuItem* Administrator::studentMenu = new MenuItem[Administrator::MAX_MENU_ITEMS];
MenuItem* Administrator::nonFacultyMenu = new MenuItem[Administrator::MAX_MENU_ITEMS];
int Administrator::facultyMenuCount = 0;
int Administrator::studentMenuCount = 0;
int Administrator::nonFacultyMenuCount = 0;

Administrator::Administrator() {
    menu = new MenuItem[MAX_MENU_ITEMS];
    inventory = new string[MAX_INVENTORY_ITEMS];
    orderHistory = new string[MAX_ORDER_HISTORY_ITEMS];
    notifications = new string[MAX_NOTIFICATIONS];
    itemCount = 0;
    inventoryCount = 0;
    orderHistoryCount = 0;
    notificationCount = 0;
}

Administrator::~Administrator() {
    delete[] menu;
    delete[] inventory;
    delete[] orderHistory;
    delete[] notifications;
}

void Administrator::ViewMenu() const {
    // Implementation for Administrator viewing menu
    cout << "Viewing menu as Administrator..." << endl;

    // Display the menu
    cout << "Menu items:" << endl;
    for (int i = 0; i < itemCount; ++i) {
        cout << "ID: " << menu[i].ItemID << "\tName: " << menu[i].ItemName
            << "\tDescription: " << menu[i].ItemDescription << "\tPrice: $" << menu[i].Price << endl;
    }
    cout << endl;
}

void Administrator::AddMenuItem() {
    // Implementation for adding a menu item
    cout << "Adding a new menu item..." << endl;

    int newItemID;
    string newItemName, newItemDescription;
    double newItemPrice, newQuantityinStock;

    cout << "Enter Item ID: ";
    cin >> newItemID;
    cout << "Enter Item Name: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, newItemName);
    cout << "Enter Item Description: ";
    getline(cin, newItemDescription);
    cout << "Enter Item Price: $";
    cin >> newItemPrice;
    cout << "Enter Quantity in Stock: ";
    cin >> newQuantityinStock;


    // Add the new item to the menu
    if (itemCount < MAX_MENU_ITEMS) {
        menu[itemCount++] = MenuItem(newItemID, newItemName, newItemDescription, newItemPrice, newQuantityinStock);
        cout << "New menu item added successfully." << endl;
    }
    else {
        cout << "Menu is full. Cannot add more items." << endl;
    }
}

void Administrator::RemoveMenuItem() {
    // Implementation for removing a menu item
    cout << "Removing a menu item..." << endl;

    int itemToRemove;
    cout << "Enter the Item ID to remove: ";
    cin >> itemToRemove;

    // Search for the item in the menu
    int indexToRemove = -1;
    for (int i = 0; i < itemCount; ++i) {
        if (menu[i].ItemID == itemToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        // Shift elements to remove the item
        for (int i = indexToRemove; i < itemCount - 1; ++i) {
            menu[i] = menu[i + 1];
        }
        --itemCount;
        cout << "Menu item removed successfully." << endl;
    }
    else {
        cout << "Item not found in the menu." << endl;
    }
}


void Administrator::ManageInventory() {
    // Implementation for managing inventory
    cout << "Managing inventory..." << endl;

    // Example: Add items to inventory
    if (inventoryCount < MAX_INVENTORY_ITEMS) {
        cout << "Enter a new item for inventory: ";
        cin >> inventory[inventoryCount];
        inventoryCount++;
    }
    else {
        cout << "Inventory is full. Cannot add more items." << endl;
    }
}

void Administrator::ViewOrderHistory() {
    // Implementation for viewing order history
    cout << "Viewing order history..." << endl;

    // Example: Display order history
    for (int i = 0; i < orderHistoryCount; ++i) {
        cout << orderHistory[i] << endl;
    }
}

void Administrator::AddNotification() {
    // Implementation for adding a notification
    cout << "Adding a notification..." << endl;

    // Example: Add notification
    if (notificationCount < MAX_NOTIFICATIONS) {
        cout << "Enter a new notification: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, notifications[notificationCount]);
        notificationCount++;
    }
    else {
        cout << "Notification limit reached. Cannot add more notifications." << endl;
    }
}

void Administrator::RemoveNotification() {
    // Implementation for removing a notification
    cout << "Removing a notification..." << endl;

    // Example: Remove notification
    if (notificationCount > 0) {
        notificationCount--;
        cout << "Notification removed successfully." << endl;
    }
    else {
        cout << "No notifications to remove." << endl;
    }
}


void Administrator::ManageDiscountPromotion() {
    // Implementation for managing discounts and promotions
    cout << "Managing discounts and promotions...\n";

    // Read menu items from file or database
    ifstream menuFile("menu_data.txt");
    if (!menuFile.is_open()) {
        cout << "Error opening menu file for reading.\n";
        return;
    }

    // Display current menu with IDs
    cout << "Current Menu:\n";
    displayMenuWithIDs(menuFile);
    menuFile.close();

    // Prompt for the menu item to apply discount/promotion
    int menuItemID;
    cout << "Enter the ID of the menu item to apply discount/promotion: ";
    cin >> menuItemID;

    // Read existing discounts/promotions from file or database
    ifstream discountFile("discount_data.txt");
    if (!discountFile.is_open()) {
        cout << "Error opening discount file for reading.\n";
        return;
    }

    // Check if the menu item ID is valid
    if (!isValidMenuItemID(menuItemID, discountFile)) {
        cout << "Invalid menu item ID.\n";
        discountFile.close();
        return;
    }

    // Display existing discounts/promotions for the selected menu item
    Administrator::displayExistingDiscounts(menuItemID, discountFile);
    discountFile.close();

    // Prompt for a new discount/promotion value
    double newDiscount;
    cout << "Enter the new discount/promotion value (in percentage): ";
    cin >> newDiscount;

    // Write the new discount/promotion to the file
    ofstream discountOutFile("discount_data.txt", ios::app);
    if (!discountOutFile.is_open()) {
        cout << "Error opening discount file for writing.\n";
        return;
    }

    discountOutFile << menuItemID << "\t" << newDiscount << endl;
    discountOutFile.close();

    cout << "Discount/Promotion applied successfully!\n";
}
void Administrator::RateMenuItem() {
    // Implementation for rating a menu item using the Rating class
    cout << "Rating a menu item...\n";

    // Read menu items from file or database
    ifstream menuFile("menu_data.txt");
    if (!menuFile.is_open()) {
        cout << "Error opening menu file for reading.\n";
        return;
    }

    // Display current menu with IDs
    cout << "Current Menu:\n";
    displayMenuWithIDs(menuFile);
    menuFile.close();

    // Prompt for the menu item to rate
    int menuItemID;
    cout << "Enter the ID of the menu item to rate: ";
    cin >> menuItemID;

    // Read existing ratings from file or database
    ifstream ratingFile("rating_data.txt");
    if (!ratingFile.is_open()) {
        cout << "Error opening rating file for reading.\n";
        return;
    }

    // Check if the menu item ID is valid
    if (!isValidMenuItemID(menuItemID, ratingFile)) {
        cout << "Invalid menu item ID.\n";
        ratingFile.close();
        return;
    }

    // Display existing ratings for the selected menu item
    displayExistingRatings(menuItemID, ratingFile);
    ratingFile.close();

    // Prompt for a new rating
    int newRating;
    cout << "Enter the new rating (between 1 and 5): ";
    cin >> newRating;

    // Check if the new rating is valid
    if (newRating < 1 || newRating > 5) {
        cout << "Invalid rating value. Ratings must be between 1 and 5.\n";
        return;
    }

    // Prompt for a comment
    cout << "Enter a comment for the rating: ";
    cin.ignore(); // Clear the newline character from the stream
    string newComment;
    getline(cin, newComment);

    // Create a Rating object
    Rating newRatingObject;
    // Assign values to the Rating object
    newRatingObject.MenuItemID = menuItemID;
    newRatingObject.CustomerID = 1;  // Assuming the customer ID (adjust as needed)
    newRatingObject.Score = newRating;
    newRatingObject.Comment = newComment;

    // Call the Rate function of the Rating object
    newRatingObject.Rate();

    // Write the new rating to the file
    ofstream ratingOutFile("rating_data.txt", ios::app);
    if (!ratingOutFile.is_open()) {
        cout << "Error opening rating file for writing.\n";
        return;
    }

    // Write the new rating to the file
    ratingOutFile << menuItemID << "\t" << newRatingObject.CustomerID << "\t" << newRatingObject.Score
        << "\t" << newRatingObject.Comment << endl;
    ratingOutFile.close();

    cout << "Menu item rated successfully!\n";
}

// Helper function to display menu items with IDs
void Administrator::displayMenuWithIDs(ifstream& file) const {
    int id;
    string name, description;
    double price;
    while (file >> id >> name >> description >> price) {
        cout << "ID: " << id << "\tName: " << name << "\tDescription: " << description << "\tPrice: $" << price << endl;
    }
}

// Helper function to check if a menu item ID is valid
bool Administrator::isValidMenuItemID(int menuItemID, std::ifstream& file) const {
    int id;
    string name, description;
    double price;
    while (file >> id >> name >> description >> price) {
        if (id == menuItemID) {
            return true; // Valid menu item ID
        }
    }
    return false; // Invalid menu item ID
}

// Helper function to display existing discounts/promotions for a menu item
void Administrator::displayExistingDiscounts(int menuItemID, ifstream& file) const {
    int id;
    double discount;
    while (file >> id >> discount) {
        if (id == menuItemID) {
            cout << "Existing Discount/Promotion for Menu Item ID " << menuItemID << ": " << discount << "%\n";
            return;
        }
    }
    cout << "No existing discount/promotion for Menu Item ID " << menuItemID << "\n";
}

// Helper function to display existing ratings for a menu item
void Administrator::displayExistingRatings(int menuItemID, ifstream& file) const {
    int id, userID, rating;
    while (file >> id >> userID >> rating) {
        if (id == menuItemID) {
            cout << "Existing Rating for Menu Item ID " << menuItemID << ": " << rating << " by User ID " << userID << "\n";
        }
    }
    cout << "No existing ratings for Menu Item ID " << menuItemID << "\n";
}

void Administrator::DisplayFromFile() {
}

void Administrator::ViewUsersFromFile() {
}

void Administrator::ViewMenuItemsFromFile() {
}

void Administrator::ViewOrdersFromFile() {
}

void Administrator::ViewRatingsFromFile() {
}

void Administrator::ViewPaymentsFromFile() {
}

void Administrator::CalculateMonthlyEarnings() {
    ifstream orderFile("orders.txt");

    if (!orderFile.is_open()) {
        cerr << "Error opening orders file." << endl;
        return;
    }

    int year, month, day;
    double totalPrice;
    double totalEarnings = 0.0;
    int ordersCount = 0;

    while (orderFile >> year >> month >> day >> totalPrice) {

        // Get the current date
        time_t now = time(0);
        tm currentDate;

        // Usiny localtime_s to avoid the unsafe behavior
        if (localtime_s(&currentDate, &now) == 0) {
            // Check to see if order was made in the current month
            if (year == currentDate.tm_year + 1900 && month == currentDate.tm_mon + 1) {
                ordersCount++;
                totalEarnings += totalPrice;
            }
        }
        else {
            cerr << "Error getting current date." << endl;
        }
    }

    orderFile.close();

    cout << "Total earnings for the current month: $" << totalEarnings << endl;
    cout << "Total number of orders: " << ordersCount << endl;
}

