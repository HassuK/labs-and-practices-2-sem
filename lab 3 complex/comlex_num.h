#pragma once
#include <iostream>



class ComplexNumber {
private:
    double im;
    double r;

public:
    ComplexNumber(double im = 0., double r =0.);
    ComplexNumber(const ComplexNumber& val);

    ComplexNumber& operator=(const ComplexNumber& val);
    ComplexNumber& operator *= (const ComplexNumber& val);
    ComplexNumber& operator += (const ComplexNumber& val);
    ComplexNumber operator*(const ComplexNumber& val);
    ComplexNumber operator+(const ComplexNumber& val);
    ComplexNumber operator++(); 
    ComplexNumber operator++(int);
    ~ComplexNumber() {};

    double getRealPart();
    double getImaginaryPart();
};
