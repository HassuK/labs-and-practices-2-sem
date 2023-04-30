#include <iostream>
#include <vector>
#include "comlex_num.h"

std::ostream& operator<<(std::ostream& out, ComplexNumber& num) {
	out << "Re:" << num.getRealPart() << " Im:" << num.getImaginaryPart() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, ComplexNumber& num) {
	double re, im;
	in >> re >> im;
	num = ComplexNumber(re, im);
	return in;
}

void main() {
	ComplexNumber d;
	ComplexNumber sum, mult;
	

	std::cout << d;

	std::cout << "Input real part and imaginary part" << std::endl;
	std::cin >> d;
	std::cout << d;

	ComplexNumber a{2, 1};
	ComplexNumber b(2, 3);
	ComplexNumber copy{ a };
	std::cout << copy;
	mult = a * b;
	sum = a + b;
	std::cout << mult << sum;
	std::cout << a << b;
	a++;
	std::cout << a;
	++a;
	std::cout << a;

}


