#include "CafeStaff.h"
#include <iostream>
using namespace std;

CafeStaff::CafeStaff() {

}

CafeStaff::CafeStaff(const string& userID, const string& userName, const string& password)
    : User(userID, userName, password) {
}

void CafeStaff::ViewMenu() const {
    cout << "Displaying menu items...\n";
}

void CafeStaff::ProcessOrder() {
    cout << "Processing order...\n";
}

void CafeStaff::AddMenuItem(const string& itemName) {
    cout << "Adding menu item: " << itemName << endl;
}

void CafeStaff::RemoveMenuItem(const string& itemName) {
    cout << "Removing menu item: " << itemName << endl;
}
