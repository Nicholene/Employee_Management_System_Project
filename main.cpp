//Employee Management System

#include <iostream>

using namespace std;


class Employee {
private:
    string name = "No name";
    int userId = 0;
    string userType = "General";

public:
    Employee() {};


    Employee (string name, int userId) {
        this->name = name;
        this->userId = userId;
    }

    Employee (string name, int userId, string userType) {
        this->name = name;
        this->userId = userId;
        this->userType = userType;
    }


    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Employee::name = name;
    }

    int getUserId() const {
        return userId;
    }

    void setUserId(int userId) {
        Employee::userId = userId;
    }

    const string &getUserType() const {
        return userType;
    }

    void setUserType(const string &userType) {
        Employee::userType = userType;
    }


    void viewEmployee() {
        cout << "Employee's Name: "<<name << endl
             << "ID: "<< userId << endl
             << "Usertype: " << userType << endl;
    }
};


int main() {

    // Generate sample employee data - can hold up to 100 employees.
    int const rosterMaxSize = 100;
    Employee roster[rosterMaxSize] = {};

    Employee bob("Bob",1,"HR");
    Employee sarah("Sarah",2,"Management");
    Employee jason("Jason",3);
    Employee luke("Luke",4);
    Employee jen("Jen",5);
    Employee tom("Tom",6);

    roster[0] = bob;
    roster[1] = sarah;
    roster[2] = jason;
    roster[3] = luke;
    roster[4] = jen;
    roster[5] = tom;


    cout << "Hello, welcome to the EMS 2023 log-in screen!\nEnter your employee ID: ";
    string userId;
    cin >> userId;


    string userName = "No Name";
    string userType = "No Type";

    for (int i=0; i < rosterMaxSize; i++ ) {
        if (roster[i].getUserId() == stoi(userId)) {
            cout << "Welcome your information is as follows:\n";
            roster[i].viewEmployee();
            userName =  roster[i].getName();
            userType = roster[i].getUserType();
        }

    }

    string userInput = "";
    if (userType == "HR") {

        while (userInput != "quit") {
            cout
                    << "As a human resource manager, type \"view\" to view, \"add\" to add, \"modify\" to modify or \"delete\" to delete an employee.\n"
                       "Type \"quit\" to close\n";
            cin >> userInput;
            if (userInput == "view") {
                cout << "Enter Employee ID: ";
                cin >> userInput;

                for (int i = 0; i < rosterMaxSize; i++) {
                    if (roster[i].getUserId() == stoi(userInput)) {
                        cout << "Requested Information: \n";
                        roster[i].viewEmployee();

                    }
                }
            }

            if (userInput == "add") {
                cout << "New Employee Name: ";
                cin >> userInput;
                string newEmployeeName = userInput;

                cout << "New Employee ID: ";
                cin >> userInput;
                int newEmployeeUserID = stoi(userInput);

                cout << "New Employee Type: (HR, Management, or General) ";
                cin >> userInput;
                string newEmployeeType = userInput;

                Employee newEmployee(newEmployeeName, newEmployeeUserID, newEmployeeType);

                int rosterSize = 0;

                for (int i = 0; i < rosterMaxSize; i++) {
                    if (roster[i].getUserId() > 0) {
                        rosterSize += 1;
                    }
                }

                roster[rosterSize] = newEmployee;
                cout << "Successfully added new employee!\n";
                roster[rosterSize].viewEmployee();

            }


            if (userInput == "modify") {
                cout << "Enter Employee ID: ";
                cin >> userInput;
                int index = 1;

                for (int i = 0; i < rosterMaxSize; i++) {
                    if (roster[i].getUserId() == stoi(userInput)) {
                        cout << "Requested Information to Modify: \n";
                        roster[i].viewEmployee();
                        index = i;
                        break;
                    }
                }

                cout << "Enter number to modify to the following:  1 - Name, 2 - ID, 3 - userType: ";
                cin >> userInput;
                if (userInput == "1") {
                    cout << "Enter a new name: ";
                    cin >> userInput;
                    roster[index].setName(userInput);
                    userInput = "";
                }
                if (userInput == "2") {
                    cout << "Enter a new ID: ";
                    cin >> userInput;
                    roster[index].setUserId(stoi(userInput));
                    userInput = "";
                }
                if (userInput == "3") {
                    cout << "Enter a new userType: (HR, Management, General) ";
                    cin >> userInput;
                    roster[index].setUserType(userInput);
                    userInput = "";
                }
                cout << "Modified Employee Information: \n";
                roster[index].viewEmployee();

            }

            if (userInput == "delete") {
                cout << "Enter Employee ID: ";
                cin >> userInput;
                int index = -1;

                for (int i = 0; i < rosterMaxSize; i++) {
                    if (roster[i].getUserId() == stoi(userInput)) {
                        cout
                                << "Are you sure you want to delete the employee with the information below?: \nType: \"yes\"\n";
                        roster[i].viewEmployee();
                        index = i;
                    }
                }
                cin >> userInput;
                if (userInput == "yes") {
                    roster[index].setUserId(0);
                    roster[index].setName("DELETED");
                    roster[index].setUserType("DELETED");
                    roster[index].viewEmployee();

                }
            }
        }
    }

    if (userType == "Management") {
        while (userInput != "quit") {
            cout << "As a manager, type \"view\" to view an employee's data based on employee ID."
                    "\n Type \"quit\" to close\n" ;
            cin >> userInput;
            if (userInput == "view") {
                cout << "Enter Employee ID: ";
                cin >> userInput;

                for (int i=0; i < rosterMaxSize; i++ ) {
                    if (roster[i].getUserId() == stoi(userInput)) {
                        cout << "Requested Information: \n";
                        roster[i].viewEmployee();

                    }}
            }
        }
    }
    cout << "Goodbye";


    return 0;
}