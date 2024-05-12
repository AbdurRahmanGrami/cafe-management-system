#pragma once
#include "User.h"
#include "MenuItem.h"
#include <string>
using namespace std;

class CafeStaff : public User, public MenuItem {
public:
    // Constructor
    CafeStaff();
    CafeStaff(const string& userID, const string& userName, const string& password);

    
    void ViewMenu() const override;
    void ProcessOrder();
    void AddMenuItem(const string& itemName);
    void RemoveMenuItem(const string& itemName);

};
