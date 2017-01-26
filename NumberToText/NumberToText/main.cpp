#include <iostream>
#include <string>
#include <algorithm>

#include "IntToWord.h"

using namespace std;

int main()
{
	string stringNum;
	long long int num;
	string stringLang;
	int lang;
	char flag;
	bool numFlag;
	char delimiter = ',';

	cout << "===Number to Word Converter===" << endl << endl;
	do {
		cout << "Enter a Number: ";
		//Check the input number valid or not
		do {
			getline(cin, stringNum);
			if (stringNum.find(delimiter)) {
				stringNum.erase(remove(stringNum.begin(), stringNum.end(), delimiter), stringNum.end());
			}
			try {
				num = stoll(stringNum);
				break;
			}
			catch (...) {
				cout << "Please Enter a Valid Number: ";
			}
		} while (true);

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
			lang = stoi(stringLang);
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

		cout << endl << "Want to convert more number ? (Y / N) ";
		cin >> flag;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << endl;
	} while (flag == 'Y' || flag == 'y');

	system("PAUSE");
	return 0;
}