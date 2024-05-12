#include "Student.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Student::ViewMenu() const {
    Customer::ViewMenu();
    cout << "Welcome to the Student Menu!" << endl;
    cout << "1. Aloo - $4.99\n";
    cout << "2. Biryani - $6.00\n";
    cout << "3. Lassi - $2.00\n";
    cout << "4. Paratha  $3.99\n";
}

void Student::PlaceOrder() {
    cout << "Placing an order...\n";
    ViewMenu(); 

    //Order newOrder(getUserID(), getUserName()); 

    int itemNumber, quantity;
    char choice;
    bool isOrdering = true;

    while (isOrdering) {
        cout << "Enter item number to order: ";
        cin >> itemNumber;
        cout << "Enter quantity: ";
        cin >> quantity;

       // newOrder.AddItem(itemNumber, quantity); // Add item to the order

        cout << "Add more items? (y/n): ";
        cin >> choice;
        isOrdering = (choice == 'y' || choice == 'Y');
    }

    /*   newOrder.CalculateTotal();
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
    */
}

void Student::ViewOrderHistory() {
}

void Student::LeaveAComment() const {
    cout << "You are leaving a comment as a student.\n";
    cout << "Please enter your comment: ";

    // Clear any remaining newline characters in the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string comment;
    getline(cin, comment); // Allowing for multi-line comments

    ofstream commentFile("student_comments.txt", ios::app);
    if (commentFile.is_open()) {
        commentFile << "Student Comment:\n";
        commentFile << comment << "\n\n";
        commentFile.close();
        cout << "Your comment has been saved.\n";
    }
    else {
        cout << "Error: Unable to save the comment.\n";
    }
}

void Student::ReserveTable() {
    cout << "Student is reserving a table." << endl;

    int availableTables[MAX_TABLES] = { 1, 2, 3, 4, 5 };

    cout << "Available Tables: ";
    for (int i = 0; i < MAX_TABLES; ++i) {
        cout << availableTables[i] << " ";
    }
    cout << endl;

    int chosenTable;
    cout << "Enter the table number you want to reserve: ";
    cin >> chosenTable;

    bool tableAvailable = false;
    for (int i = 0; i < MAX_TABLES; ++i) {
        if (availableTables[i] == chosenTable) {
            availableTables[i] = -1; // Assuming -1 represents a reserved table
            tableAvailable = true;
            cout << "Table " << chosenTable << " reserved successfully!" << endl;
            break;
        }
    }

    if (!tableAvailable) {
        cout << "Sorry, the selected table is not available. Please choose another one." << endl;
    }
}
