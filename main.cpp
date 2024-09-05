#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
#include "class.h"

int main() {
	std::unordered_map<std::string, BankAccount*> accounts;
	int select{};

	do {

		std::cout << "Select an account type to create: \n"
			<< "1. Create a new account\n"
			<< "2. Display account information\n"
			<< "3. Deposit money into an account\n"
			<< "4. Withdraw money from an account\n"
			<< "5. Apply interest to a savings account\n"
			<< "6. Exit the program\n";
		std::cin >> select;

		switch (select) {

		case 1: {
			int accountType{};
			std::cout << "Select the type of account you want to create: \n"
				<< "1. Savings Account\n"
				<< "2. Checking Account\n";
			std::cin >> accountType;

			std::string name;
			std::cout << "Enter the account holder name: ";
			std::cin >> name;

			double initBalance;
			std::cout << "Enter an initial balance: ";
			std::cin >> initBalance;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(10000000, 99999999);

			int randomAccountNumber = dist(gen);

			if (accountType == 1) {
				SavingsAccount* savingsAccount = new SavingsAccount();
				savingsAccount->setAccountHolderName(name);
				savingsAccount->setAccountNumber(randomAccountNumber);
				savingsAccount->setBalance(initBalance);
				accounts[name] = savingsAccount;
			}
			else if (accountType == 2) {
				CheckingAccount* checkingAccount = new CheckingAccount();
				checkingAccount->setAccountHolderName(name);
				checkingAccount->setAccountNumber(randomAccountNumber);
				checkingAccount->setBalance(initBalance);
				accounts[name] = checkingAccount;
			}
			std::cout << name << " created with Account Number: " << randomAccountNumber << std::endl;
			break;
		}


		case 2: {
			std::cout << "Enter the account holder's name to display information: ";
			std::string name;
			std::cin >> name;

			if (accounts.find(name) != accounts.end()) {
				accounts[name]->display();
			}
			else {
				std::cout << "No account found for the holder name: " << name << "\n";
			}
			break;
		}
		case 3: {
			std::cout << "Enter the account holder's name to deposit money: ";
			std::string nameDeposit;
			std::cin >> nameDeposit;

			if (accounts.find(nameDeposit) != accounts.end()) {
				double amount;
				std::cout << "Enter the amount to deposit: ";
				std::cin >> amount;
				accounts[nameDeposit]->deposit(amount);
			}
			else {
				std::cout << "No account found for the holder name: " << nameDeposit << "\n";
			}
			break;
		}
		case 4: {
			std::cout << "Enter the account holder's name to withdraw money: ";
			std::string nameWithdraw;
			std::cin >> nameWithdraw;

			if (accounts.find(nameWithdraw) != accounts.end()) {
				double amount;
				std::cout << "Enter the amount to withdraw: ";
				std::cin >> amount;

				// Check if it's a CheckingAccount to handle overdraft
				CheckingAccount* checkingAccount = dynamic_cast<CheckingAccount*>(accounts[nameWithdraw]);

				if (checkingAccount) {
					if (checkingAccount->getBalance() - amount < checkingAccount->getOverdraftLimit()) {
						std::cout << "Insufficient funds: Cannot withdraw that amount with the current overdraft limit.\n";
					}
					else {
						checkingAccount->withdraw(amount);
						std::cout << "Withdrawal successful. New balance: " << checkingAccount->getBalance() << "\n";
					}
				}
				else {
					// For SavingsAccount
					if (accounts[nameWithdraw]->getBalance() < amount) {
						std::cout << "Insufficient funds: Cannot withdraw that amount.\n";
					}
					else {
						accounts[nameWithdraw]->withdraw(amount);
						std::cout << "Withdrawal successful. New balance: " << accounts[nameWithdraw]->getBalance() << "\n";
					}
				}
			}
			else {
				std::cout << "No account found for the holder name: " << nameWithdraw << "\n";
			}
			break;
		}

		case 5: {
			std::cout << "Enter the account holder's name to apply interest: ";
			std::string nameInterest;
			std::cin >> nameInterest;

			if (accounts.find(nameInterest) != accounts.end()) {
				SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(accounts[nameInterest]);

				if (savingsAccount) {
					savingsAccount->addInterest();
					std::cout << "Interest has been applied.\n";
				}
				else {
					std::cout << "The account is not a Savings Account. Interest cannot be applied.\n";
				}
			}
			else {
				std::cout << "No account found for the holder name: " << nameInterest << "\n";
			}
			break;
		}
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
