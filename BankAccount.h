#pragma once

#include <iostream>
#include <string>

class BankAccount {
public:
    int accountNumber;
    std::string accountHolderName;
    double balance;

    void deposit(double amount);
    void withdraw(double amount);
    void display();
    virtual void addInterest();
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    void addInterest() override;
};

class CheckingAccount : public BankAccount {
public:
    double overdraftLimit;

    void withdraw(double amount);
};


