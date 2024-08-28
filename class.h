#pragma once

#include <iostream>
#include <string>

class BankAccount {
public:
    int accountNumber;
    std::string accountHolderName;
    double balance;

    BankAccount(); // Default constructor
    BankAccount(int accNumber, const std::string& accHolderName, double initBalance);

    void deposit(double amount);
    void withdraw(double amount);
    void display();
    virtual void addInterest();  // Declare addInterest as virtual
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    // Constructor inherits default initBalance = 0 from BankAccount
    SavingsAccount(int accNumber, const std::string& accHolderName, double initBalance = 0, double rate = 0);
    SavingsAccount(); // Default constructor

    void addInterest() override;
};

class CheckingAccount : public BankAccount {
public:
    double overdraftLimit;

    // Constructor inherits default initBalance = 0 from BankAccount
    CheckingAccount(int accNumber, const std::string& accHolderName, double initBalance = 0, double limit = 0);
    CheckingAccount(); // Default constructor

    void withdraw(double amount);
};
