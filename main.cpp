#include <iostream>
#include <string>
#include <unordered_map>
#include "BankAccount.h"

int main() {
	std::unordered_map<std::string, BankAccount*> accounts;
	int select{};
	std::cout << "Select an account type to create: \n"
		<< "1. Create a new account\n"
		<< "2. Display account information\n"
		<< "3. Deposit money into an account\n"
		<< "4. Withdraw money from an account\n"
		<< "5. Apply interest to a savings account\n"
		<< "6. Exit the program\n";
	std::cin >> select;

	do {
		switch (select) {
		case 1: {
			int accountType{};
			std::cout << "Select the type of account you want to create: \n"
				<< "1. Savings Account\n"
				<< "2. Checking Account\n";
			std::cin >> accountType;

			switch (accountType) {
			case 1:
			{
				std::cout << "You have selected to create a Savings Account.\n";
				SavingsAccount savingsAccount;
				std::cout << "Enter the account number: ";
				std::cin >> savingsAccount.accountNumber;
				std::cout << "Enter the account holder name: ";
				std::cin >> savingsAccount.accountHolderName;
				std::cout << "Enter the balance: ";
				std::cin >> savingsAccount.balance;
				std::cout << "Enter the interest rate: ";
				std::cin >> savingsAccount.interestRate;
				break;
			}
			case 2:
			{
				std::cout << "You have selected to create a Checking Account.\n";
				CheckingAccount checkingAccount;
				std::cout << "Enter the account number: ";
				std::cin >> checkingAccount.accountNumber;
				std::cout << "Enter the account holder name: ";
				std::cin >> checkingAccount.accountHolderName;
				std::cout << "Enter the balance: ";
				std::cin >> checkingAccount.balance;
				std::cout << "Enter the overdraft limit: ";
				std::cin >> checkingAccount.overdraftLimit;
				break;
			}
			default:
				std::cout << "Invalid selection. Returning to main menu.\n";
				break;
			}
			break;
		}
		case 2:
			std::cout << "Enter the account holder's name to display information: ";
			std::string name;
			std::cin >> name;

			if (accounts.find(name) != accounts.end()) {
				accounts[name]->display();
			} else {
				std::cout << "No account found for the holder name: " << name << "\n";
			}
			break;

			break;
		case 3:
			// tba
			break;
		case 4:
			// tba
			break;
		case 5:
			// tba
			break;
		case 6:
			std::cout << "Exiting the program.\n";
			break;
		default:
			std::cout << "Invalid selection. Please try again.\n";
			break;
		}
	} while (select != 6);

	return 0;
}
