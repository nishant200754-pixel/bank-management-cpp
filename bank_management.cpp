#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accNo;
    string name;
    float balance;
};
void createAccount() {
    BankAccount b;

    ofstream file("bank.txt", ios::app);

    cout << "\nEnter Account Number: ";
    cin >> b.accNo;

    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, b.name);

    cout << "Enter Initial Balance: ";
    cin >> b.balance;

    file << b.accNo << " " << b.name << " " << b.balance << endl;

    file.close();

    cout << "\nAccount Created Successfully!\n";
}

void displayAccounts() {
    ifstream file("bank.txt");

    BankAccount b;

    cout << "\n----- Account Records -----\n";

    while(file >> b.accNo >> b.name >> b.balance) {
        cout << "Account No: " << b.accNo
             << " | Name: " << b.name
             << " | Balance: " << b.balance << endl;
    }

    file.close();
}
void depositMoney() {
    int acc;
    float amount;

    cout << "\nEnter Account Number: ";
    cin >> acc;

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    cout << "\nRs. " << amount << " Deposited Successfully!\n";
}

void withdrawMoney() {
    int acc;
    float amount;

    cout << "\nEnter Account Number: ";
    cin >> acc;

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    cout << "\nRs. " << amount << " Withdrawn Successfully!\n";
}
int main() {
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
