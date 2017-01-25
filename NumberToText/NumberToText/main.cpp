#include <iostream>
#include <string>

#include "IntToWord.h"

using namespace std;

int main()
{
	int num;
	string lang;

	cout << "Enter a Number: ";
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please Enter a Valid Number: ";
		cin >> num;
	}

	cout << "Enter output Language: ";
	getline(cin, lang);

	IntToWord number_1(num, lang);
	int angka = number_1.getNum();
	
	cout << endl << "The number you enter is " << number_1.convert_number(angka) << endl;

	system("PAUSE");
	return 0;
}