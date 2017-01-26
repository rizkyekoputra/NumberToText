// Header

#include <iostream>
#include <string>

using namespace std;

#ifndef INTTOWORD_H
#define INTTOWORD_H

class IntToWord {
public:
	//Default Counstructor
	IntToWord();
	
	//Overload Construtor
	IntToWord(long long int, int);

	//Destructor
	~IntToWord();

	//Accessor Functions
	long long int getNum() const;
		// getNum - return number that we want to convert

	int getLang() const;
		// getLang - return language of converted number

	//Mutator Functions
	void setNum(long long int);
		// setNum - sets number that be convert
		// @param int - number that be convert

	void setLang(int);
		// setLang - sets language that converted wanna be
		// @param string - language that converted wanna be

	string convert_nn(long long int, int);
		// convert number to word, a value < 100 to English.
		// @param int - number that will be convert
		// @return string - number in word

	string convert_nnn(long long int, int);
		// convert number to word, a value > 100 and < 1000.
		// @param int - number that will be convert
		// @return string - number in word

	string convert_number(long long int, int);
		// convert number to word.
		// @param int - number that will be convert
		// @return string - number in word

private:
	//Member Variables
	long long int newNum;
	int newLang;
	static const char* const ones[][20];
	static const char* const tens[][8];
	static const char* const denom[][21];
	static const char* const hundred[];
	static const char* const negative[];
};

#endif