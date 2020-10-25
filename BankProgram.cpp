/* Library */
#include <iostream>

/* Macro */
#define MAX_NAME_LENGTH 20
#define MAX_NUM_ACCOUNT 100

/* Function Prototypes */
void printMenu();
void makeAccount();
void deposit();
void withdraw();
void showAccount();

/* Structure */
struct account {
	int accNum;
	char name[MAX_NAME_LENGTH];
	double balance;
};
typedef struct account Account;

/* Namespace */
using namespace std;

/*******************************************************************************
 * main function
*******************************************************************************/
int main(void) {
	int choice = 0;
	Account account[MAX_NUM_ACCOUNT];
	int count;

	while(choice != 5) {
		printMenu();
		cout << ">> ";
		cin >> choice;
		cout << endl;
	
		switch(choice) {
			case 1:
				makeAccount();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				showAccount();
				break;
			case 5:
				cout << "Exiting..." << endl;
				cout << endl;
				break;
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

void makeAccount() {

}

void deposit() {

}

void withdraw() {

}

void showAccount() {

}
