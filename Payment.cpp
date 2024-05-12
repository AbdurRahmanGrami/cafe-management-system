#include "Payment.h"
#include <iostream>

Payment::Payment(int id, int orderID, double amount) : PaymentID(id), OrderID(orderID), Amount(amount) {}

bool Payment::ProcessPayment()
{
    cout << "Processing payment for order ID " << OrderID << endl;
    cout << "Amount to be paid: $" << Amount << endl;

    char confirm;
    cout << "Confirm payment? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        cout << "Payment successful! Thank you for your purchase." << endl;
        
        return true;  // Return true for successful payment
    }
    else
    {
        cout << "Payment cancelled. Returning to menu." << endl;
        return false;  // Return false for cancelled payment
    }
}

// Getter methods
int Payment::GetPaymentID() const
{
    return PaymentID;
}

int Payment::GetOrderID() const
{
    return OrderID;
}

double Payment::GetAmount() const
{
    return Amount;
}

string Payment::GetPaymentStatus() const
{
    return PaymentStatus;
}

// Setter methods
void Payment::SetPaymentID(int id)
{
    PaymentID = id;
}

void Payment::SetOrderID(int orderID)
{
    OrderID = orderID;
}

void Payment::SetAmount(double amount)
{
    Amount = amount;
}

void Payment::SetPaymentStatus(const string& paymentStatus)
{
    PaymentStatus = paymentStatus;
}