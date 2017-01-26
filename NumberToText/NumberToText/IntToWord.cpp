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

IntToWord::IntToWord(long long int num, string lang) {
	newNum = num;
	newLang = lang;
}

IntToWord::~IntToWord() {

}

long long int IntToWord::getNum() const {
	return newNum;
}

string IntToWord::getLang() const {
	return newLang;
}

void IntToWord::setNum(long long int num) {
	newNum = num;
}

void IntToWord::setLang(string lang) {
	newLang = lang;
}

string IntToWord::convert_nn(long long int val) {
	if (val < 20) {
		return ones[val];
	}
	for (int i = 0; i < sizeof(tens); i++) {
		string dcap = tens[i];
		long long int dval = 20 + 10 * i;
		if (dval + 10 > val) {
			if ((val % 10) != 0) {
				return dcap + "-" + ones[val % 10];
			}
			return dcap;
		}
	}
}

string IntToWord::convert_nnn(long long int val) {
	string word = "";
	long long int rem = val / 100;
	long long int mod = val % 100;
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

string IntToWord::convert_number(long long int val) {
	string sign = "";
	if (val < 0) {
		sign = "negative ";
		val = abs(val);
	}
	if (val < 100) {
		return sign + convert_nn(val);
	}
	if (val < 1000) {
		return sign + convert_nnn(val);
	}
	for (int i = 0; i < sizeof(denom); i++) {
		int didx = i - 1;
		long long int dval = long long int(pow(1000, i));
		if (dval > val) {
			long long int mod = long long int(pow(1000, didx));
			long long int l = val / mod;
			long long int r = val - (l * mod);
			string ret = convert_nnn(l) + " " + denom[didx];
			if (r > 0) {
				ret = ret + " " + convert_number(r);
			}
			return sign + ret;
		}
		

	}
}