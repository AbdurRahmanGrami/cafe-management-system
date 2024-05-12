#pragma once

#include <iostream>
#include "Customer.h"

class Faculty : public Customer {
public:
    // Default constructor
    Faculty();

    // Parameterized constructor
    Faculty(const string& userID, const string& userName, const string& password);

    void ViewMenu() const override;
    void PlaceOrder() override;
    void ViewOrderHistory() override;
    void LeaveAComment() const override;
    void ReserveTable() override;

private:
    void ViewSpecificMenu(const Customer& customer) const;
};
