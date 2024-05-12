#include "Faculty.h"
#include "Order.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Faculty::Faculty() : Customer() {
}

// Parameterized constructor
Faculty::Faculty(const string& userID, const string& userName, const string& password)
    : Customer(userID, userName, password) {
}

void Faculty::ViewMenu() const {
    cout << "Displaying Faculty menu items...\n";

    // Displayin the Faculty menu
    cout << "Faculty Menu:\n";
    cout << "1. Burger - $5.99\n";
    cout << "2. Pizza - $7.99\n";
    cout << "3. Sausage - $1.50\n";
    cout << "4. Juice - $2.50\n";
    cout << "5. Coffee - $1.99\n";
    cout << "6. French Fries - $4.99\n\n";

    //  Student Menu
    cout << "Student Menu:\n";
    cout << "1. Roll Paratha - $4.99\n";
    cout << "2. Lollipop - $1.00\n";
    cout << "3. Chips- $2.00\n";
    cout << "4. Sandwich - $3.99\n\n";

    // NonFaculty emnu
    cout << "Non-Faculty Menu:\n";
    cout << "1. Sandwich - $3.50\n";
    cout << "2. Water - $1.20\n";
    cout << "3. Coffee - $2.50\n";
}


void Faculty::PlaceOrder() {
    cout << "Placing an order...\n";
    ViewMenu(); // Display the menu

    Order newOrder(getUserID(), getUserName()); // Create a new order object with Faculty's ID and Name

    int itemNumber, quantity;
    char choice;
    bool isOrdering = true;

    while (isOrdering) {
        cout << "Enter item number to order: ";
        cin >> itemNumber;
        cout << "Enter quantity: ";
        cin >> quantity;

     //   newOrder.AddItem(itemNumber, quantity); // Add item to the order

        cout << "Add more items? (y/n): ";
        cin >> choice;
        isOrdering = (choice == 'y' || choice == 'Y');
    }

    newOrder.CalculateTotal(); // Calculate total price of the order
    cout << "Total Price: $" << newOrder.GetTotalPrice() << endl;

    cout << "Confirm order? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        newOrder.ConfirmOrder();
        cout << "Order confirmed. Order ID: " << newOrder.GetOrderID() << endl;
    }
    else {
        newOrder.CancelOrder();
        cout << "Order cancelled.\n";
    }
}

void Faculty::ViewOrderHistory() {

}

void Faculty::LeaveAComment() const {
    cout << "You are leaving a comment as faculty.\n";
    cout << "Please enter your comment: ";

    // Clear any remaining newline characters in the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string comment;
    getline(cin, comment);

    ofstream commentFile("faculty_comments.txt", ios::app);
    if (commentFile.is_open()) {
        commentFile << "Faculty Comment:\n";
        commentFile << comment << "\n\n";
        commentFile.close();
        cout << "Your comment has been saved.\n";
    }
    else {
        cout << "Error: Unable to save the comment.\n";
    }
}

void Faculty::ReserveTable() {
    cout << "Customer is reserving a table." << endl;

    int availableTables[MAX_TABLES] = { 1, 2, 3, 4, 5 };

    // Display available tables
    cout << "Available Tables: ";
    for (int i = 0; i < MAX_TABLES; ++i) {
        cout << availableTables[i] << " ";
    }
    cout << endl;

    // Ask the customer to choose a table
    int chosenTable;
    cout << "Enter the table number you want to reserve: ";
    cin >> chosenTable;

    // Check if the chosen table is available
    bool tableAvailable = false;
    for (int i = 0; i < MAX_TABLES; ++i) {
        if (availableTables[i] == chosenTable) {
            // Table is available, mark it as reserved
            availableTables[i] = -1; // We assume that -1 represents a reserved table
            tableAvailable = true;
            cout << "Table " << chosenTable << " reserved successfully!" << endl;
            break;
        }
    }

    if (!tableAvailable) {
        // if table is not available
        cout << "Sorry, the selected table is not available. Please choose another one." << endl;
    }
}

void Faculty::ViewSpecificMenu(const Customer& customer) const {
   
}
