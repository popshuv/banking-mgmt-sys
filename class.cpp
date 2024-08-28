#include "class.h"

// Default constructor for BankAccount
BankAccount::BankAccount()
    : accountNumber(0), accountHolderName(""), balance(0) {}

// Constructor for BankAccount with parameters
BankAccount::BankAccount(int accNumber, const std::string& accHolderName, double initBalance)
    : accountNumber(accNumber), accountHolderName(accHolderName), balance(initBalance) {}

// Default constructor for SavingsAccount
SavingsAccount::SavingsAccount()
    : BankAccount(), interestRate(0) {}

// Constructor for SavingsAccount with parameters
SavingsAccount::SavingsAccount(int accNumber, const std::string& accHolderName, double initBalance, double rate)
    : BankAccount(accNumber, accHolderName, initBalance), interestRate(rate) {}

// Default constructor for CheckingAccount
CheckingAccount::CheckingAccount()
    : BankAccount(), overdraftLimit(0) {}

// Constructor for CheckingAccount with parameters
CheckingAccount::CheckingAccount(int accNumber, const std::string& accHolderName, double initBalance, double limit)
    : BankAccount(accNumber, accHolderName, initBalance), overdraftLimit(limit) {}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    balance -= amount;
}

void BankAccount::display() {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder Name: " << accountHolderName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::addInterest() {
    // Default implementation: do nothing or throw an exception
    throw std::logic_error("Interest can only be applied to savings accounts.");
}

void SavingsAccount::addInterest() {
    balance += balance * (interestRate / 100);
}

void CheckingAccount::withdraw(double amount) {
    if (balance - amount < overdraftLimit) {
        std::cout << "Insufficient funds" << std::endl;
    }
    else {
        balance -= amount;
    }
}
