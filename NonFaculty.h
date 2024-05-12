#pragma once
#include "Customer.h"
#include <string>

class NonFaculty : public Customer {
public:
    // Default constructor
    NonFaculty() {}

    // Parameterized constructor
    NonFaculty(const string& userID, const string& userName, const string& password)
        : Customer(userID, userName, password) {}

    // Overridden methods from Customer
    void ViewMenu() const override;
    void PlaceOrder() override;
    void ViewOrderHistory() override;
    void LeaveAComment() const override;
    void ReserveTable() override;
};
