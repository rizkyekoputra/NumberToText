//Function Definitions

#include "IntToWord.h"
#include <math.h>

const char* const IntToWord::ones[] = { "zero",
										"one",
										"two",
										"three",
										"four",
										"five",
										"six",
										"seven",
										"eight",
										"nine",
										"ten",
										"eleven",
										"twelve",
										"thirteen",
										"fourteen",
										"fifteen",
										"sixteen",
										"seventeen",
										"eighteen",
										"nineteen" };

const char* const IntToWord::tens[] = { "twenty",
										"thirty",
										"fourty",
										"fifty",
										"sixty",
										"seventy",
										"eighty",
										"ninety" };

const char* const IntToWord::denom[] = { "",
										"thousand",
										"million",
										"billion",
										"trillion",
										"quadrillion",
										"quintillion",
										"sextillion",
										"septillion",
										"octillion",
										"nonillion",
										"decillion",
										"undecillion",
										"duodecillion",
										"tredecillion",
										"quattuordecillion",
										"sexdecillion",
										"septendecillion",
										"octodecillion",
										"novemdecillion",
										"vigintillion" };

IntToWord::IntToWord() {
	newNum = 0;
}

IntToWord::IntToWord(int num, string lang) {
	newNum = num;
	newLang = lang;
}

IntToWord::~IntToWord() {

}

int IntToWord::getNum() const {
	return newNum;
}

string IntToWord::getLang() const {
	return newLang;
}

void IntToWord::setNum(int num) {
	newNum = num;
}

void IntToWord::setLang(string lang) {
	newLang = lang;
}

string IntToWord::convert_nn(int val) {
	if (val < 20) {
		return ones[val];
	}
	for (int i = 0; i < sizeof(tens); i++) {
		string dcap = tens[i];
		int dval = 20 + 10 * i;
		if (dval + 10 > val) {
			if ((val % 10) != 0) {
				return dcap + "-" + ones[val % 10];
			}
			return dcap;
		}
	}
}

string IntToWord::convert_nnn(int val) {
	string word = "";
	int rem = val / 100;
	int mod = val % 100;
	if (rem > 0){
		word = ones[rem];
		word += " hundred";
		if (mod > 0) {
			word = word;
			word += " ";
		}
	}
	if (mod > 0) {
		word = word + convert_nn(mod);
	}
	return word;
}

string IntToWord::convert_number(int val) {
	if (val < 100) {
		return convert_nn(val);
	}
	if (val < 1000) {
		return convert_nnn(val);
	}
	for (int i = 0; i < sizeof(denom); i++) {
		int didx = i - 1;
		int dval = int(pow(1000, i));
		if (dval > val) {
			int mod = int(pow(1000, didx));
			int l = val / mod;
			int r = val - (l * mod);
			string ret = convert_nnn(l) + " " + denom[didx];
			if (r > 0) {
				ret = ret + ", " + convert_number(r);
			}
			return ret;
		}
		

	}
}