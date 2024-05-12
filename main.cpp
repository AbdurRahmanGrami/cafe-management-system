#include <iostream>
#include <string>
#include "Administrator.h"
#include "CafeStaff.h"
#include "Faculty.h"
#include "NonFaculty.h"
#include "Student.h"

using namespace std;

int main() {
    int userType;
    cout << "Enter a number corresponding to your user type:"<<endl;
    cout << "1. Administrator" << endl;
    cout << "2. Cafe Staff" << endl;
    cout << "3. Faculty" << endl;
    cout << "4. Non-Faculty" << endl;
    cout << "5. Student" << endl;
    cout << "Enter your choice: ";
    cin >> userType;

    switch (userType) {
    case 1: {
        Administrator admin;
        int adminChoice;
        do {
			cout << "Administrator selected.\n";
			cout << "Administrator Options:\n";
			cout << "1. View Menu\n";
			cout << "2. Add Menu Item\n";
			cout << "3. Remove Menu Item\n";
			cout << "4. Manage Inventory\n";
			cout << "5. View Order History\n";
			cout << "6. Add Notification\n";
			cout << "7. Remove Notification\n";
			cout << "8. Manage Discount/Promotion\n";
			cout << "9. Rate Menu Item\n";
			cout << "10. Display from File\n";
			cout << "11. View Users from File\n";
			cout << "12. View Menu Items from File\n";
			cout << "13. View Orders from File\n";
			cout << "14. View Ratings from File\n";
			cout << "15. View Payments from File\n";
			cout << "16. Calculate Monthly Earnings\n";
			cout << "0. Logout\n";
			cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
            case 1:
                admin.ViewMenu();
                break;
            case 2:
                admin.AddMenuItem();
                break;
            case 3:
                admin.RemoveMenuItem();
                break;
            case 4:
                admin.ManageInventory();
                break;
            case 5:
                admin.ViewOrderHistory();
                break;
            case 6:
                admin.AddNotification();
                break;
            case 7:
                admin.RemoveNotification();
                break;
            case 8:
                admin.ManageDiscountPromotion();
                break;
            case 9:
                admin.RateMenuItem();
                break;
            case 10:
                admin.DisplayFromFile();
                break;
            case 11:
                admin.ViewUsersFromFile();
                break;
            case 12:
                admin.ViewMenuItemsFromFile();
                break;
            case 13:
                admin.ViewOrdersFromFile();
                break;
            case 14:
                admin.ViewRatingsFromFile();
                break;
            case 15:
                admin.ViewPaymentsFromFile();
                break;
            case 16:
                admin.CalculateMonthlyEarnings();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (adminChoice != 0);
        break;
    }
    case 2: {
        CafeStaff cafeStaff;
        int cafeStaffChoice;
        do {
            cout << "Cafe Staff selected.\n";
            cout << "Enter your choice (0 to logout): ";
			cout << "Cafe Staff Options:\n";
			cout << "1. View Menu\n";
			cout << "2. Process Order\n";
			cout << "3. Add Menu Item\n";
			cout << "4. Remove Menu Item\n";
			cout << "0. Logout\n";
            cin >> cafeStaffChoice;

            switch (cafeStaffChoice) {
            case 1:
                cafeStaff.ViewMenu();
                break;
            case 2:
                cafeStaff.ProcessOrder();
                break;
            case 3: {
                string itemName;
                cout << "Enter the menu item name to add: ";
                cin >> itemName;
                cafeStaff.AddMenuItem(itemName);
                break;
            }
            case 4: {
                string itemName;
                cout << "Enter the menu item name to remove: ";
                cin >> itemName;
                cafeStaff.RemoveMenuItem(itemName);
                break;
            }
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (cafeStaffChoice != 0);
        break;
    }
    case 3: {
        Faculty faculty;
        int facultyChoice;
        do {
            cout << "Faculty selected.\n";
            cout << "Enter your choice: " << endl;
			cout << "Faculty Options:\n";
			cout << "1. View Menu\n";
			cout << "2. Place Order\n";
			cout << "3. View Order History\n";
			cout << "4. Leave A Comment\n";
			cout << "5. Reserve Table\n";
			cout << "0. Logout\n";
            cin >> facultyChoice;

            switch (facultyChoice) {
            case 1:
                faculty.ViewMenu();
                break;
            case 2:
                faculty.PlaceOrder();
                break;
            case 3:
                faculty.ViewOrderHistory();
                break;
            case 4:
                faculty.LeaveAComment();
                break;
            case 5:
                faculty.ReserveTable();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (facultyChoice != 0);
        break;
    }
    case 4: {
        NonFaculty nonFaculty;
        int nonFacultyChoice;
        do {
            cout << "Non-Faculty selected.\n";
            cout << "Enter your choice: \n" << endl;
            cout << "Non-Faculty Options:\n";
            cout << "1. View Menu\n";
            cout << "2. Place Order\n";
            cout << "3. View Order History\n";
            cout << "4. Leave A Comment\n";
            cout << "5. Reserve Table\n";
            cout << "0. Logout\n";
            cin >> nonFacultyChoice;

            switch (nonFacultyChoice) {
            case 1:
                nonFaculty.ViewMenu();
                break;
            case 2:
                nonFaculty.PlaceOrder();
                break;
            case 3:
                nonFaculty.ViewOrderHistory();
                break;
            case 4:
                nonFaculty.LeaveAComment();
                break;
            case 5:
                nonFaculty.ReserveTable();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (nonFacultyChoice != 0);
        break;
    }

    case 5: {
        Student student;
        int studentChoice;
        do {
            cout << "Student selected" << endl;
            cout << "Enter your choice: ";
            cout << "Student Options:\n";
            cout << "1. View Menu\n";
            cout << "2. Place Order\n";
            cout << "3. View Order History\n";
            cout << "4. Leave A Comment\n";
            cout << "5. Reserve Table\n";
            cout << "0. Logout\n";

            cin >> studentChoice;

            switch (studentChoice) {
            case 1:
                student.ViewMenu();
                break;
            case 2:
                student.PlaceOrder();
                break;
            case 3:
                student.ViewOrderHistory();
                break;
            case 4:
                student.LeaveAComment();
                break;
            case 5:
                student.ReserveTable();
                break;
                
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (studentChoice != 0);
        break;
    }
    default:
        cout << "Invalid user type.\n";
    }

    return 0;
}