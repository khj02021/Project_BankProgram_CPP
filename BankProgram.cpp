#include <iostream>

void printMenu();

using namespace std;

int main(void) {
	printMenu();

	return 0;
}

void printMenu() {
	cout << "------- MENU -------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Show Account info" << endl;
	cout << "5. Exit" << endl;
}
