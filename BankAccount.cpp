#include <iostream>
#include <string>


class BankAccount {

public:
    int accountNumber;
    std::string accountHolderName;  
    double balance;

    void deposit(double amount) {
		balance += amount;
	}

    void withdraw(double amount) {
        balance -= amount;
    }

    void display() {
		std::cout << "Account Number: " << accountNumber << std::endl;
		std::cout << "Account Holder Name: " << accountHolderName << std::endl;
		std::cout << "Balance: " << balance << std::endl;
	}

    virtual void addInterest() {
        // Default implementation: do nothing or throw an exception
        throw std::logic_error("Interest can only be applied to savings accounts.");
    }
};

class SavingsAccount : public BankAccount {
    double interestRate = 3.5;

    void addInterest() override {
		balance += balance * interestRate;
	}
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

    void withdraw(double amount) {
        if (balance - amount < overdraftLimit) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            balance -= amount;
        }
    }
};