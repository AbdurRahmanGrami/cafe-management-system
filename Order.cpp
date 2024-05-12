#include "Order.h"
#include "MenuItem.h"
using namespace std;

Order::Order() : OrderID(0), CustomerID(0), TotalPrice(0), OrderStatus("In Progress") {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        ItemsOrdered[i] = nullptr;
        Quantities[i] = 0;
    }
}

Order::Order(int orderId, int customerId)
{
}


Order::Order(string getUserID, string getUserName) {


}

void Order::AddItem(const MenuItem& menuItem, int quantity) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (ItemsOrdered[i] == nullptr) {
            ItemsOrdered[i] = &menuItem;
            Quantities[i] = quantity;
            cout << quantity << " " << menuItem.GetItemName() << "(s) added to the order." << endl;
            return; // Item added, exit the function
        }
    }
    cout << "Order is full. Cannot add more items." << endl;
}

void Order::RemoveItem(const MenuItem& menuItem) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (ItemsOrdered[i] == &menuItem) {
            // Found the item, remove it
            cout << menuItem.GetItemName() << " removed from the order." << endl;
            ItemsOrdered[i] = nullptr;
            Quantities[i] = 0;
            return; // Item removed, exitin da function
        }
    }
    cout << menuItem.GetItemName() << " not found in the order." << endl;
}

void Order::CalculateTotal() {
    TotalPrice = 0;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (ItemsOrdered[i] != nullptr) {
            // Addiiton of the price of each item multiplied by its quantity
            TotalPrice += ItemsOrdered[i]->GetPrice() * Quantities[i];
        }
    }
    cout << "Total price calculated: $" << TotalPrice << endl;
}

void Order::ConfirmOrder()
{
    OrderStatus = "Confirmed";
    cout << "Order confirmed. Thank you!" << endl;
}

void Order::CancelOrder()
{
    OrderStatus = "Cancelled";
    cout << "Order cancelled." << endl;
}

int Order:: GetCustomerID()  {
    return CustomerID; 
}

double Order::GetTotalPrice() const {
    
    return TotalPrice;

}

int Order::GetOrderID() const {
    return OrderID;
}

string Order::GetOrderStatus() const {
    return OrderStatus;
}