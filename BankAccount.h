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
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    void addInterest();
};

class CheckingAccount : public BankAccount {
public:
    double overdraftLimit;

    void withdraw(double amount);
};


