#pragma once

#include <complex.h>

class Complex
{
	public:
		Complex(std::string str_number);
		Complex(std::complex<double> complex_number);

		friend std::ostream& operator<< (std::ostream &ostr, const Complex &num);
		
		Complex operator+(const Complex &other);
		Complex operator-(const Complex &other);
		Complex operator*(const Complex &other);
		Complex operator/(const Complex &other);

		std::complex<double> num;

};

Complex::Complex (std::string str_number)
{
	std::string str_re = "";

	for (auto symb : str_number)
	{
		if (symb == ' ' && str_re.size()) break;
		if (str_re.size() && (symb == '+' || symb == '-')) break;
		if (symb != ' ' && symb != '+') str_re += symb;
	}
	
	str_number.replace(0, str_re.size()+1, "");
	while (str_number.find(' ') != std::string::npos)
		str_number.replace(str_number.find(' '), 1, "");

	this->num = std::complex<double>(std::stod(str_re), std::stod(str_number));
}

Complex::Complex (std::complex<double> complex_number)
{
	this->num = complex_number;
}

std::ostream& operator<< (std::ostream &ostr, const Complex &number)
{
	std::cout << "re: " << number.num.real() << " im: " << number.num.imag() << " ";

	return ostr << ( number.num.real() == -0.0 ? 0.0 : number.num.real() ) << 
		( number.num.imag() >= 0.0 ? "+" : "") <<
		( number.num.imag() == -0.0 ? 0.0 : number.num.imag() ) << 'j';
}

Complex Complex::operator+ (const Complex &other)
{
	return Complex(this->num + other.num);
}

Complex Complex::operator- (const Complex &other)
{
	return Complex(this->num - other.num);
}

Complex Complex::operator* (const Complex &other)
{
	return Complex(this->num * other.num);
}

Complex Complex::operator/ (const Complex &other)
{
	return Complex(this->num / other.num);
}













