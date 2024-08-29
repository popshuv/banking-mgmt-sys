#include "class.h"

BankAccount::BankAccount()
    : accountNumber(0), accountHolderName(""), balance(0) {}

SavingsAccount::SavingsAccount()
    : BankAccount(), interestRate(0) {}

CheckingAccount::CheckingAccount()
    : BankAccount(), overdraftLimit(0) {}

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
