#pragma once

#include <iostream>
#include <string>

class BankAccount {
public:
    int accountNumber;
    std::string accountHolderName;
    double balance;

    BankAccount(); // Default constructor

    void deposit(double amount);
    void withdraw(double amount);
    void display();
    virtual void addInterest();  // Declare addInterest as virtual
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    SavingsAccount(); // Default constructor

    void addInterest() override;
};

class CheckingAccount : public BankAccount {
public:
    double overdraftLimit;

    CheckingAccount(); // Default constructor

    void withdraw(double amount);
};
