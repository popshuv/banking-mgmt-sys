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
};

class SavingsAccount : public BankAccount {
    double interestRate;

    void addInterest() {
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