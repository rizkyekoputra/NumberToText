#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num,
		leftDigit,
		RightDigit;

	string ones[] = { "Zero",
					"One",
					"Two",
					"Three",
					"Four",
					"Five",
					"Six",
					"Seven",
					"Eight",
					"Nine",
					"Ten",
					"Eleven",
					"Twelve",
					"Thirteen",
					"Fourteen",
					"Fifteen",
					"Sixteen",
					"Seventeen",
					"Eighteen",
					"Nineteen" };

	string tens[] = { "Twenty",
					"Thirty",
					"Fourty",
					"Fifty",
					"Sixty",
					"Seventy",
					"Eighty",
					"Ninety" };

	string denom[] = { "thousand",
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

	cout << "Enter a Number: ";
	cin >> num;

	if (num <= 0 || num >= 100)
	{
		cout << "The number is not between 1-99." << endl;
	}
	else if (num >= 1 && num <= 19)
	{
		cout << "The number you have entered is " << ones[num] << endl;
	}
	else if (num >= 20 && num <= 99) 
	{
		leftDigit = num / 10;
		RightDigit = num % 10;

		if (RightDigit != 0)
		{
			cout << "The number you have enetered is " << tens[leftDigit - 2] << " " << ones[RightDigit] << endl;
		} 
		else
		{
			cout << "The number you have enetered is " << tens[leftDigit - 2] << endl;
		}
		
	}

	system("PAUSE");
	return 0;
}