#include "Customer.h"
#include"User.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Customer::Customer() 
    : userID(""), userName(""), password(""), historyCount(0), commentCount(0) {
}

// Parameterized constructor
Customer::Customer(const string& userID, const string& userName, const string& password)
    : User(userID, userName, password), historyCount(0), commentCount(0) {
}

void Customer::ViewMenu() const {
    cout << "Displaying customer-specific menu items...\n";
}

void Customer::PlaceOrder() {
}

void Customer::ViewOrderHistory() {
}

void Customer::LeaveAComment() const {
   
}

void Customer::ReserveTable() {
  
}

int Customer::GetCustomerID()
{
    return CustomerID;
}


void Customer::SaveOrderHistory() const {
    ofstream file("order_history.txt", ios::app);
    if (file.is_open()) {
        for (const auto& order : orderHistory) {
            file << order << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file for saving order history.\n";
    }
}

void Customer::LoadOrderHistory() {
    ifstream file("order_history.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            orderHistory[historyCount++] = line;
        }
        file.close();
    } else {
        cerr << "Unable to open file for loading order history.\n";
    }
}

void Customer::SaveComments() const {
    ofstream file("comments.txt", ios::app);
    if (file.is_open()) {
        for (const auto& comment : comments) {
            file << comment << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file for saving comments.\n";
    }
}

void Customer::LoadComments() {
    ifstream file("comments.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            comments[commentCount++] = line;
        }
        file.close();
    } else {
        cerr << "Unable to open file for loading comments.\n";
    }
}
