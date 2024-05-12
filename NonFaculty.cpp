// NonFaculty.cpp
#include "NonFaculty.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Order.h"
#include "MenuItem.h"
using namespace std;

void NonFaculty::ViewMenu() const {
    Customer::ViewMenu();
    cout << "Welcome to the NonFaculty Menu!" << endl;
    cout << "Non-Faculty Menu:\n";
    cout << "1. Sandwich - $3.50\n";
    cout << "2. Water - $1.20\n";
    cout << "3. Coffee - $2.50\n";

}


void NonFaculty::PlaceOrder() {
    cout << "Placing an order...\n";
    ViewMenu(); // Display the menu here by callinh viewmenu function/method

    Order newOrder(getUserID(), getUserName()); // Creation og a new order object with NonFaculty's id and Name

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

    newOrder.CalculateTotal(); // calculation of total price of the order
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

void NonFaculty::ViewOrderHistory() {
}

void NonFaculty::LeaveAComment() const {
    cout << "You are leaving a comment as Non Faculty.\n";
    cout << "Please enter your comment: ";

    // Clear any remaining newline characters in the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string comment;
    getline(cin, comment);

    // Saving the comment to a file
    ofstream commentFile("nonfaculty_comments.txt", ios::app); // ios::app to append to the file
    if (commentFile.is_open()) {
        commentFile << "Non Faculty Comment:\n";
        commentFile << comment << "\n\n";
        commentFile.close();
        cout << "Your comment has been saved.\n";
    }
    else {
        cout << "Error: Unable to save the comment.\n";
    }
}

void NonFaculty::ReserveTable() {
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
