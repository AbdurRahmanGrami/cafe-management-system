#include "MenuItem.h"
using namespace std;

MenuItem::MenuItem()
    : ItemID(0), ItemName(""), ItemDescription(""), Price(0.0), QuantityInStock(0) {//default
}

MenuItem::MenuItem(int itemId, const string& itemName, const string& itemDescription, double price, int quantityInStock) {
        //  parameterised constructor
        ItemID = itemId;
        ItemName = itemName;
        ItemDescription = itemDescription;
        Price = price;
        QuantityInStock = quantityInStock;
}


void MenuItem::UpdateStock(int newStock) {
    QuantityInStock = newStock;
    cout << "Stock for " << ItemName << " updated to " << newStock << "." << endl;
}

int MenuItem::GetItemID() const {
    return ItemID;
}

string MenuItem::GetItemName() const {
    return ItemName;
}

string MenuItem::GetItemDescription() const {
    return ItemDescription;
}

double MenuItem::GetPrice() const {
    return Price;
}

int MenuItem::GetQuantityInStock() const {
    return QuantityInStock;
}

void MenuItem::ViewMenu() const {
    cout << "Displaying menu items...\n";
}