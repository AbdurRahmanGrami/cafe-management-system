#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void FileManager::SaveUserToFile(const User& user, const string& fileName) {
    ofstream out(fileName, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    out << user.getUserID() << "," << user.getUserName() << "," << user.getPassword() << endl;
    out.close();
}

void FileManager::SaveMenuItemToFile(const MenuItem& menuItem, const string& fileName) {
    ofstream out(fileName, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    out << menuItem.GetItemID() << "," << menuItem.GetItemName() << ","
        << menuItem.GetItemDescription() << "," << menuItem.GetPrice() << endl;
    out.close();
}

void FileManager::SaveOrderToFile(const Order& order, const string& fileName) {
    ofstream out(fileName, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    out << order.GetOrderID() << "," << order.GetTotalPrice() << "," << order.GetOrderStatus() << endl;
    out.close();
}

void FileManager::SaveRatingToFile(const Rating& rating, const string& fileName) {
    ofstream out(fileName, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    out << rating.GetRatingID() << "," << rating.GetMenuItemID() /*<< ","  << rating.GetCustomerID() << "," */ << rating.GetScore() << "," << rating.GetComment() << endl;
    out.close();
}

void FileManager::SavePaymentToFile(const Payment& payment, const string& fileName) {
    ofstream out(fileName, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    //Writinh payment data to file
    out << payment.GetPaymentID() << "," << payment.GetOrderID() << ","
        << payment.GetAmount() << "," << payment.GetPaymentStatus() << endl;
    out.close();
}
