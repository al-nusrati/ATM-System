#include <iostream>
using namespace std;

class ATM {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    int pin;

public:
    // Exception classes
    class InvalidAmount {};
    class InsufficientBalance {};
    class ZeroBalance {};
    class InvalidPIN {};

    // Constructor
    ATM(int accNum, string name, double bal, int p) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = bal;
        pin = p;
    }

    // Deposit Money
    void deposit(double amount) {
        if (amount <= 0)
            throw InvalidAmount();

        balance += amount;
        cout << "Successfully deposited $" << amount << endl;
        cout << "New balance: $" << balance << endl;
    }

    // Withdraw Money
    void withdraw(double amount) {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;
        cout << "Successfully withdrawn $" << amount << endl;
        cout << "Remaining balance: $" << balance << endl;
    }

    // Check Balance
    void checkBalance() {
        if (balance == 0)
            throw ZeroBalance();

        cout << "Current balance: $" << balance << endl;
    }

    // Change PIN
    void changePIN(int newPIN) {
        // Check if PIN is exactly 4 digits (1000-9999)
        if (newPIN < 1000 || newPIN > 9999)
            throw InvalidPIN();

        pin = newPIN;
        cout << "PIN successfully changed!" << endl;
    }

    void displayInfo() {
        cout << "\n=== Account Information ===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "==========================\n" << endl;
    }
};

int main() {
    ATM account(12345, "John Doe", 1000.0, 1234);

    cout << "=== ATM System Demo ===" << endl;
    account.displayInfo();

    // Test 1: Valid deposit
    cout << "\n--- Test 1: Deposit $500 ---" << endl;
    try {
        account.deposit(500);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }

    // Test 2: Deposit zero amount
    cout << "\n--- Test 2: Deposit $0 ---" << endl;
    try {
        account.deposit(0);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }

    // Test 3: Deposit negative amount
    cout << "\n--- Test 3: Deposit -$100 ---" << endl;
    try {
        account.deposit(-100);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }

    // Test 4: Valid withdrawal
    cout << "\n--- Test 4: Withdraw $300 ---" << endl;
    try {
        account.withdraw(300);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }
    catch (ATM::InsufficientBalance) {
        cout << "Exception: Insufficient balance!" << endl;
    }

    // Test 5: Withdraw more than balance
    cout << "\n--- Test 5: Withdraw $2000 ---" << endl;
    try {
        account.withdraw(2000);
    }
    catch (ATM::InvalidAmount) {
        cout << "Exception: Invalid amount! Amount must be positive." << endl;
    }
    catch (ATM::InsufficientBalance) {
        cout << "Exception: Insufficient balance!" << endl;
    }

    // Test 6: Change PIN with valid 4 digits
    cout << "\n--- Test 6: Change PIN to 5678 ---" << endl;
    try {
        account.changePIN(5678);
    }
    catch (ATM::InvalidPIN) {
        cout << "Exception: Invalid PIN! PIN must be exactly 4 digits." << endl;
    }

    // Test 7: Change PIN with more than 4 digits
    cout << "\n--- Test 7: Change PIN to 12345 ---" << endl;
    try {
        account.changePIN(12345);
    }
    catch (ATM::InvalidPIN) {
        cout << "Exception: Invalid PIN! PIN must be exactly 4 digits." << endl;
    }

    // Test 8: Check balance
    cout << "\n--- Test 8: Check Balance ---" << endl;
    try {
        account.checkBalance();
    }
    catch (ATM::ZeroBalance) {
        cout << "Exception: Balance is zero!" << endl;
    }

    return 0;
}