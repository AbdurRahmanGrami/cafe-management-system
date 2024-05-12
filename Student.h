#pragma once
#include "Customer.h"
#include "User.h"
#include <string>

class Student : public Customer {
public:
    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(const string& userID, const string& userName, const string& password)
        : Customer(userID, userName, password) {}

   //customer overriden methof=ds
    void ViewMenu() const override;
    void PlaceOrder() override;
    void ViewOrderHistory() override;
    void LeaveAComment() const override;
    void ReserveTable() override;
};
