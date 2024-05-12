#pragma once
#include <iostream>
#include <string>
using namespace std;

class MenuItem {
public:
    int ItemID;
    string ItemName;
    string ItemDescription;
    double Price;
    int QuantityInStock;

    MenuItem();
    virtual void ViewMenu() const;

    MenuItem(int itemId, const string& itemName, const string& itemDescription, double price, int quantityInStock);
    void UpdateStock(int newStock);
    int GetItemID() const;
    string GetItemName() const;
    string GetItemDescription() const;
    double GetPrice() const;
    int GetQuantityInStock() const;
};


