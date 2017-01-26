//Function Definitions

#include "IntToWord.h"
#include <math.h>

const char* const IntToWord::ones[][20] = { { "zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" },
											{ "nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "duabelas", "tigabelas", "empatbelas", "lima belas", "enambelas", "tujuhbelas", "delapanbelas", "sembilanbelas" } };

const char* const IntToWord::tens[][8] = { { "twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety" } };

const char* const IntToWord::denom[][21] = { { "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion",
											"tredecillion", "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion" } };

const char* const IntToWord::hundred[] = { " hundred" };

const char* const IntToWord::negative[] = { "negative " };

IntToWord::IntToWord() {
	newNum = 0;
}

IntToWord::IntToWord(long long int num, int lang) {
	newNum = num;
	newLang = lang;
}

IntToWord::~IntToWord() {

}

long long int IntToWord::getNum() const {
	return newNum;
}

int IntToWord::getLang() const {
	return newLang;
}

void IntToWord::setNum(long long int num) {
	newNum = num;
}

void IntToWord::setLang(int lang) {
	newLang = lang;
}

string IntToWord::convert_nn(long long int val, int lang) {
	if (val < 20) {
		return ones[lang][val];
	}
	for (int i = 0; i < sizeof(tens); i++) {
		string dcap = tens[lang][i];
		long long int dval = 20 + 10 * i;
		if (dval + 10 > val) {
			if ((val % 10) != 0) {
				return dcap + "-" + ones[lang][val % 10];
			}
			return dcap;
		}
	}
}

string IntToWord::convert_nnn(long long int val, int lang) {
	string word = "";
	long long int rem = val / 100;
	long long int mod = val % 100;
	if (rem > 0){
		word = ones[lang][rem];
		word += hundred[lang];
		if (mod > 0) {
			word = word;
			word += " ";
		}
	}
	if (mod > 0) {
		word = word + convert_nn(mod, 0);
	}
	return word;
}

string IntToWord::convert_number(long long int val, int lang) {
	string sign = "";
	if (val < 0) {
		sign = negative[lang];
		val = abs(val);
	}
	if (val < 100) {
		return sign + convert_nn(val, lang);
	}
	if (val < 1000) {
		return sign + convert_nnn(val, lang);
	}
	for (int i = 0; i < sizeof(denom); i++) {
		int didx = i - 1;
		long long int dval = long long int(pow(1000, i));
		if (dval > val) {
			long long int mod = long long int(pow(1000, didx));
			long long int l = val / mod;
			long long int r = val - (l * mod);
			string ret = convert_nnn(l, lang) + " " + denom[lang][didx];
			if (r > 0) {
				ret = ret + " " + convert_number(r, lang);
			}
			return sign + ret;
		}
		

	}
}