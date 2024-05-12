#include <string>
#include <iostream>
using namespace std;

class Payment
{
protected:
    int PaymentID;
    int OrderID;
    double Amount;
    string PaymentStatus;

public:
    Payment(int id, int orderID, double amount);

    // Getter methods
    int GetPaymentID() const;
    int GetOrderID() const;
    double GetAmount() const;
    string GetPaymentStatus() const;

    // Setter methods
    void SetPaymentID(int id);
    void SetOrderID(int orderID);
    void SetAmount(double amount);
    void SetPaymentStatus(const string& paymentStatus);

    bool ProcessPayment();
  
};