#include <iostream>
#include <string>

#include "IntToWord.h"

using namespace std;

int main()
{
	long long int num;
	string stringLang;
	int lang;

	cout << "===Number to Word Converter===" << endl << endl;
	cout << "Enter a Number: ";
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please Enter a Valid Number: ";
		cin >> num;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "----------------------" << endl;
	cout << "Language Option" << endl;
	cout << "----------------------" << endl;
	cout << "0. " << "English (default)" << endl;
	cout << "1. " << "Indonesia" << endl;
	cout << "2. " << "Vietnam" << endl;
	cout << "----------------------" << endl;

	cout << "Enter output Language: ";
	getline(cin, stringLang);
	if (stringLang == "") {
		lang = 0;
	}
	else {
		lang = std::stoi(stringLang);
	}

	IntToWord number_1(num, lang);
	long long int numbers = number_1.getNum();
	int languages = number_1.getLang();
	
	// if other language not yet developed
	if (lang != 0) {
		cout << endl << "Language not yet developed" << endl << endl;
	}
	else {
		cout << endl << "The number you enter is: " << number_1.convert_number(numbers, languages) << endl << endl;
	}

	system("PAUSE");
	return 0;
}