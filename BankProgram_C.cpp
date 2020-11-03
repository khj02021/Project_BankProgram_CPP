/* Library */
#include <iostream>
#include <cstdlib>
#include <cstring>

/* Macro */
#define MAX_NAME_LENGTH 20
#define MAX_ACCOUNT_LENGTH 20

/* Structure */
struct account {
	char accNum[MAX_ACCOUNT_LENGTH];
	char name[MAX_NAME_LENGTH];
	double balance;
};
typedef struct account Account;

/* Function Prototypes */
void printMenu();
void makeAccount(Account** account, int* accCount);
void allocateInfo(Account* account, int accCount);
void deposit(Account* account, int accCount);
void withdraw(Account* account, int accCount);
void showAccount(Account* account, int accCount);

/* Namespace */
using namespace std;

/*******************************************************************************
 * main function
*******************************************************************************/
int main(void) {
	int choice;
	Account* account = NULL;
	int accCount = 0;

	while(1) {
		printMenu();
		cout << ">> ";
		cin >> choice;
		cout << endl;
	
		switch(choice) {
			case 1:
				makeAccount(&account, &accCount);
				break;
			case 2:
				deposit(account, accCount);
				break;
			case 3:
				withdraw(account, accCount);
				break;
			case 4:
				showAccount(account, accCount);
				break;
			case 5:
				cout << "Exiting..." << endl;
				cout << endl;
				free(account);
				return 0;
			default:
				cout << "Enter between 1 and 5" << endl;
				cout << endl;
				break;
		}
	}

	return 0;
}

/*******************************************************************************
 * printMenu function prints the menu prompt
 * input: N/A
 * output: N/A
*******************************************************************************/
void printMenu() {
	cout << "------- MENU -------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Show Account info" << endl;
	cout << "5. Exit" << endl;
}

void makeAccount(Account** account, int* accCount) {
	if(*account == NULL) {
		*account = (Account*) malloc(sizeof(Account));
		allocateInfo(*account, *accCount);
		(*accCount)++;
	}
	else {
		*account = (Account*) realloc(*account, (*accCount + 1) * sizeof(Account));
		allocateInfo(*account, *accCount);
		(*accCount)++;
	}
}

void allocateInfo(Account* account, int accCount) {
	char accNum[MAX_ACCOUNT_LENGTH];
	char name[MAX_NAME_LENGTH];
	double balance;

	bool isRepeated;

	while(1) {
		isRepeated = false;
		cout << "[Making Account]" << endl;
		cout << "Account Number: ";
		cin >> accNum;
		for(int i = 0; i < accCount; i++) {
			if(!strcmp(accNum, (account + i) -> accNum)) {
				cout << endl << "Account Number already exists...\n" << endl;
				isRepeated = true;
				break;
			}
		}
		if(isRepeated)
			continue;

		cout << "Name: ";
		cin >> name;
		cout << "Balance: ";
		cin >> balance;
		cout << endl;
		
		strcpy((account + accCount) -> accNum, accNum);
		strcpy((account + accCount) -> name, name);
		(account + accCount) -> balance = balance;
		return;
	}
}

void deposit(Account* account, int accCount) {
	char accNum[MAX_ACCOUNT_LENGTH];
	double amount;
	bool isFound = false;
	int index;
	
	if(account == NULL) {
		cout << "No account..." << endl << endl;
		return;
	}

	cout << "[Deposit]" << endl;
	cout << "Account Number: ";
	cin >> accNum;

	for(int i = 0; i < accCount; i++) {
		if(!strcmp((account + i) -> accNum, accNum)) {
			isFound = true;
			index = i;
			break;
		}
	}

	if(isFound) {
		cout << "Deposit Amount: ";
		cin >> amount;
		(account + index) -> balance += amount;
		cout << endl << "Deposit Completed..." << endl << endl;
	}
	else {
		cout << "No such account..." << endl << endl;
		deposit(account, accCount);
	}
}

void withdraw(Account* account, int accCount) {
	char accNum[MAX_ACCOUNT_LENGTH];
	double amount;
	bool isFound = false;
	int index;

	if(account == NULL) {
		cout << "No account..." << endl << endl;
		return;
	}

	cout << "[Withdraw]" << endl;
	cout << "Account Number: ";
	cin >> accNum;

	for(int i = 0; i < accCount; i++) {
		if(!strcmp((account + i) -> accNum, accNum)) {
			isFound = true;
			index = i;
			break;
		}
	}

	if(isFound) {
		cout << "Withdraw Amount: ";
		cin >> amount;
		(account + index) -> balance -= amount;
		cout << endl << "Withdraw Completed..." << endl << endl;
	}
	else {
		cout << "No such account..." << endl << endl;
		withdraw(account, accCount);
	}
}

void showAccount(Account* account, int accCount) {
	if(account == NULL)
		cout << "No account..." << endl << endl;
	else {
		for(int i = 0; i < accCount; i++) {
			cout << "Account Number: " << (account + i) -> accNum << endl;
			cout << "Name: " << (account + i) -> name << endl;
			cout << "Balance: " << (account + i) -> balance << endl << endl;
		}
	}
}
