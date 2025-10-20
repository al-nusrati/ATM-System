#include <iostream>
using namespace std;

class ATM {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    int pin;

public:

    class InvalidAmount { };                // amount is negative or zero
    class InsufficientBalance { };          // amount is exceeding balance 
    class ZeroBalance { };                  // balance is zero
    class InvalidPIN { };                   // pin is less than 4 and greater than 5 

    ATM(int accNum, string name, double bal, int p) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = bal;
        pin = p;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw InvalidAmount();
        
        balance += amount;
        cout << "Successfully deposited PKR" << amount << endl;
        cout << "New balance: PKR" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw InvalidAmount();
        
        if (amount > balance)
            throw InsufficientBalance();
        
        balance -= amount;
        cout << "Successfully withdrawn PKR" << amount << endl;
        cout << "Remaining balance: PKR" << balance << endl;
    }

    void checkBalance() {
        if (balance == 0)
            throw ZeroBalance();
        
        cout << "Current balance: PKR" << balance << endl;
    }

    void changePIN(int newPIN) {
   
        if (newPIN < 1000 || newPIN > 9999)
            throw InvalidPIN();
        
        pin = newPIN;
        cout << "PIN successfully changed!" << endl;
    }

    void displayInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: PKR" << balance << "\n\n";
    }
};

int main() {
    ATM account(12345, "Jawad Ahmed", 1000, 1234);
    
    account.displayInfo();

    cout << "\nDepositing positive amount: " << endl;
    try {
        account.deposit(500);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }


    cout << "\nDepositing 0 amount: " << endl;
    try {
        account.deposit(0);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }

    cout << "\nDepositing a negative number: " << endl;
    try {
        account.deposit(-100);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }

    cout << "\nWithdraw valid amount from balance: " << endl;
    try {
        account.withdraw(300);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }
    catch (ATM::InsufficientBalance) {
        cout << "Exception: Insufficient balance!" << endl;
    }

    cout << "\nWithdrawing amount more than in balance: " << endl;
    try {
        account.withdraw(5000);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }
    catch (ATM::InsufficientBalance) {
        cout << "Exception: Insufficient balance!" << endl;
    }

    cout << "\nChanging pin: " << endl;
    try {
        account.changePIN(5678);
    }
    catch (ATM::InvalidPIN) {
        cout << "Exception: Invalid PIN! PIN must be exactly 4 digits." << endl;
    }

    cout << "\nChanging pin to more than 4 digits: " << endl;
    try {
        account.changePIN(12345);
    }
    catch (ATM::InvalidPIN) {
        cout << "Exception: Invalid PIN! PIN must be exactly 4 digits." << endl;
    }

    cout << "\nCheck Balance: " << endl;
    try {
        account.checkBalance();
    }
    catch (ATM::ZeroBalance) {
        cout << "Exception: Balance is zero!" << endl;
    }

    system("pause>0");
    return 0;
}