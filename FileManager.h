#pragma once
#include <string>
#include "User.h"
#include "MenuItem.h"
#include "Order.h"
#include "Rating.h"
#include "Payment.h"

class FileManager {
public:
    static void SaveUserToFile(const User& user, const string& fileName);
    static void SaveMenuItemToFile(const MenuItem& menuItem, const string& fileName);
    static void SaveOrderToFile(const Order& order, const string& fileName);
    static void SaveRatingToFile(const Rating& rating, const string& fileName);
    static void SavePaymentToFile(const Payment& payment, const string& fileName);
};
