// BigInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "BigInt.hpp"

bool is_valid_number(const std::string& num);
void notify_invalid_input(const std::string& input);

int _tmain(int argc, _TCHAR* argv[])
{
	//constructor tests
	std::string s = "10";
	BigInt large_int(s);
	BigInt large_int2(large_int);
	BigInt int_test(1000000);
	BigInt str_test = "789";
	BigInt int_test2 = -777;
	
	/*
	//cin test 
	BigInt cin_test;
	std::cout << "Please enter number for BigInt cin_test: ";
	std::cin >> cin_test;
	*/

	//unary tests (don't forget postfix)
	str_test = -str_test;
	str_test = ++str_test;

	if (is_valid_number(s)) {
		std::cout << "Your number is: " << str_test << '\n';
	}
	else
		notify_invalid_input(s);
	return 0;
}

/*
    Utility functions
    -----------------
*/

bool is_valid_number(const std::string& num) {
    for (char digit : num)
        if (digit < '0' || digit > '9')
			if (digit != '+' && digit != '-')
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

BigInt::BigInt(const BigInt& num) {
    value = num.value;
    sign = num.sign;
}

BigInt::BigInt(const std::string num) {
    if (num[0] == '+' || num[0] == '-') {     // check for sign
        std::string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        }
        else {
            notify_invalid_input(num);
            exit(EXIT_FAILURE);
        }
    }
    else {      // if no sign is specified
        if (is_valid_number(num)) {
            value = num;
            sign = '+';    // positive by default
        }
        else {
            notify_invalid_input(num);
            exit(EXIT_FAILURE);
        }
    }
}


BigInt::BigInt(const long long num) {
    value = std::to_string(num);
    if (num < 0) {
        sign = '-';
        value = value.substr(1);    // remove minus sign from value
    }
    else
        sign = '+';
}


/*
	I/O stream operators
	--------------------
*/

std::istream& operator>>(std::istream& in, BigInt& num) {
	std::string input;
	in >> input;
	num = BigInt(input);  // remove sign from value and set sign, if exists

	return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& num) {
    if (num.sign == '-')
        out << num.sign;
    out << num.value;

    return out;
}

/*
    Assignment operators
    --------------------
*/


void BigInt::operator=(const BigInt& num) {
    value = num.value;
    sign = num.sign;
}

void BigInt::operator=(const long long num) {
    BigInt temp(num);
    value = temp.value;
    sign = temp.sign;
}

void BigInt::operator=(const std::string num) {
    BigInt temp(num);
    value = temp.value;
    sign = temp.sign;
}

/*
	Unary operators
    ---------------
*/


BigInt BigInt::operator-() {
    BigInt temp;

    temp.value = value;
    if (value != "0") {
        if (sign == '+')
            temp.sign = '-';
        else
            temp.sign = '+';
    }

    return temp;
}

BigInt BigInt::operator++() {
	BigInt temp = *this;

	if (value.back() != '9')
		temp.value.back() += 1;
	else {
		//int count;
		//while (value.back() == '9') {
			temp.value.pop_back();
			temp.value.back() += 1;
			//++count;
		//}
		//for (; count > 0; --count) {
			temp.value.push_back('0');
		//}
	}
	/*^^^ Will not work on numbers that end in successive 9s, and negatuve numbers ^^^*/
	/*^^^ Probably implement addition operation and use that for this function ^^^*/
	return temp;
}

// TODO

/*

//    Arithmetic operators
    --------------------


// TODO



//    Arithmetic-assignment operators
    -------------------------------


// TODO

*/

/*
//    Relational operators
    --------------------


bool BigInt::operator>(const BigInt& num) {
    if (sign == num.sign)
        return (value > num.value);
    else
        return (sign == '+');
}

bool BigInt::operator>(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value > temp.value);
    else
        return (sign == '+');
}

bool BigInt::operator>=(const BigInt& num) {
    if (sign == num.sign)
        return (value >= num.value);
    else
        return (sign == '+');
}

bool BigInt::operator>=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value >= temp.value);
    else
        return (sign == '+');
}

bool BigInt::operator<(const BigInt& num) {
    if (sign == num.sign)
        return (value < num.value);
    else
        return (sign == '-');
}

bool BigInt::operator<(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value < temp.value);
    else
        return (sign == '-');
}

bool BigInt::operator<=(const BigInt& num) {
    if (sign == num.sign)
        return (value <= num.value);
    else
        return (sign == '-');
}

bool BigInt::operator<=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value <= temp.value);
    else
        return (sign == '-');
}

bool BigInt::operator==(const BigInt& num) {
    if (sign == num.sign)
        return (value > num.value);

    return false;
}

bool BigInt::operator==(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value == temp.value);

    return false;
}

bool BigInt::operator!=(const BigInt& num) {
    if (sign == num.sign)
        return (value != num.value);

    return true;
}

bool BigInt::operator!=(const long long num) {
    BigInt temp(num);

    if (sign == temp.sign)
        return (value != temp.value);

    return true;
}

*/

#ifdef DEBUG
int main() {
    BigInt num;

    num = -51311531;

    if (-num == 51311531)
        std::cout << "Big integer : " << num << "\n";
}

#endif

