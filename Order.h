#pragma once
#include "Customer.h"
#include "MenuItem.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Order : public Customer {
private:
    int OrderID;
    double TotalPrice;
    int CustomerID;
    string OrderStatus;
    const MenuItem* ItemsOrdered[MAX_ITEMS];
    int Quantities[MAX_ITEMS];

public:

    Order();
    Order(int orderId, int customerId);
    Order(string getUserID, string getUserName);
    void AddItem(const MenuItem& menuItem, int quantity);
    void RemoveItem(const MenuItem& menuItem);
    void CalculateTotal();
    void ConfirmOrder();
    void CancelOrder();

    // getter  declarations
    int GetOrderID() const;
    double GetTotalPrice() const;
    string GetOrderStatus() const;
    int GetCustomerID() override;
};
