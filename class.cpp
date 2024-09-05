#include "class.h"

// Base class constructor
BankAccount::BankAccount()
    : accountNumber(0), accountHolderName(""), balance(0) {}

// Base class destructor
BankAccount::~BankAccount() {
    std::cout << "Account " << accountNumber << " removed" << std::endl;
}


// Setters
void BankAccount::setAccountHolderName(const std::string& name) {
    accountHolderName = name;
}
void BankAccount::setAccountNumber(int number) {
    accountNumber = number;
}
void BankAccount::setBalance(double amount) {
    balance = amount;
}


// Getters
std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}
int BankAccount::getAccountNumber() const {
    return accountNumber;
}
double BankAccount::getBalance() const {
    return balance;
}

// Derived class constructors and destructors
SavingsAccount::SavingsAccount()
    : BankAccount(), interestRate(0) {}

SavingsAccount::~SavingsAccount() {
    std::cout << "Savings Account " << accountNumber << " removed" << std::endl;
}

CheckingAccount::CheckingAccount()
    : BankAccount(), overdraftLimit(0) {}

CheckingAccount::~CheckingAccount() {
    std::cout << "Checking Account " << accountNumber << " removed" << std::endl;
}

// Base class member functions
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

// Derived class member functions
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

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}