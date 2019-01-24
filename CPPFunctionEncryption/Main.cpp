// Robert M Wood Jr.
// CPW 218
// 01/24/19
// Function Encryption

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
int encryptDig(int digit);
int decryptDig(int digit);

// Assignment
// A company that wants to send data over the internet has asked you to write 
// a program that will encrypt the data so that it may be transmitted more securely.
// All the data is transmitted as four - digit integers.Your application should read
// a four - digit integer entered by the user and encrypt it as follows : 
// Replace each digit with the result of adding 7 to the digit and getting the remainder
// after dividing the new value by 10. Then swap the first digit with the third and 
// the second with the fourth.Then print the encrypted number.
//
//Write code to decrypt an encrypted number to form the original number.

int main() {

	int digit = 0;
	
	cout << "What is the number? ";
	cin >> digit;
	cout << endl;
	
	int newEncrypted = encryptDig(digit);


	cout << digit << " encrypted is " << encryptDig(digit) << endl;

	cout << endl;

	cout << newEncrypted << " decrypted is " << decryptDig(newEncrypted);
	cout << endl;
	
	system("pause");
	return 0;
}

int encryptDig(int digit) {
	// 1234 -> 8901 -> 0819 is what it should do if starts at 1234
	
	int fourth = (digit % 10 + 7) % 10;
	int third = (digit / 10 % 10 + 7 ) % 10;
	int second = (digit / 100 % 10 + 7) % 10;
	int first = (digit / 1000 % 10 + 7) % 10;

	return 1000 * third + 100 * fourth + 10 * first + second;
}

int decryptDig(int digit) {
	// 0819 -> 8901 -> 1234 is what it should do if starts at 0819

	int fourth = ((digit/100) + 3) % 10;
	int third = ((digit / 1000) + 3) % 10;
	int second = ((digit) + 3) % 10;
	int first = ((digit / 10 ) + 3) % 10;

	return 1000 * first + second *  100 + third * 10 + fourth  ;
}

