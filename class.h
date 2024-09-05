#pragma once

#include <iostream>
#include <string>

class BankAccount {

public:
    // Base class constructors and destructors
    BankAccount();
    virtual ~BankAccount();

    // Member functions
    void deposit(double amount);
    virtual void withdraw(double amount);
    void display();

    // Setters
    void setAccountHolderName(const std::string& name);
    void setAccountNumber(int number);
    void setBalance(double amount);

    // Getters
    std::string getAccountHolderName() const;
    int getAccountNumber() const;
    double getBalance() const;

protected:
    int accountNumber;
    std::string accountHolderName;
    double balance;
};

// Derived classes
class SavingsAccount : public BankAccount {

public:
    SavingsAccount();
    virtual ~SavingsAccount();

    void addInterest();

private:
    double interestRate;

};

class CheckingAccount : public BankAccount {

public:
    CheckingAccount();
    virtual ~CheckingAccount();

    void withdraw(double amount) override;

    double getOverdraftLimit() const { return overdraftLimit; }

private:
    double overdraftLimit;
};
