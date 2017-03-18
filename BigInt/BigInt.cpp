// BigInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "BigInt.hpp"

bool is_valid_number(const std::string& num);
void notify_invalid_input(const std::string& input);

int _tmain(int argc, _TCHAR* argv[])
{

	BigInt bI;
	std::string s = "10";
	if (is_valid_number(s)) {
		std::cout << "Your number is: " << s << '\n';
	}
	else
		notify_invalid_input(s);
	return 0;
}

/*
    Utility functions
    -----------------
*/

//in: passed string. out: 
bool is_valid_number(const std::string& num) {
    for (char digit : num)
        if (digit < '0' || digit > '9')
            return false;

    return true;
}

void notify_invalid_input(const std::string& input) {
    std::cout << "Invalid input! Expected an integer, got \'" << input << "\'.\n";
}

/*
    Constructors
    ------------
*/

BigInt::BigInt() {
    value = "0";
    sign = '+';
}