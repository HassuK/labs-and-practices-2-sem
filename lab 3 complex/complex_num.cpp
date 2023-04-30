#pragma once
#include "comlex_num.h"
#include <iostream>

ComplexNumber::ComplexNumber(double r, double im) : r(r), im(im) {}

ComplexNumber::ComplexNumber(const ComplexNumber& val) : im(val.im), r(val.r) {}



ComplexNumber& ComplexNumber::operator=(const ComplexNumber& val) {
    r = val.r;
    im = val.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& val) {
    double new_r = r * val.r - im * val.im;
    double new_im = r * val.im + val.r * im;
    r = new_r;
    im = new_im;
    return *this;
}


ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& val) {
    r += val.r;
    im += val.im;
    return *this;
}


ComplexNumber ComplexNumber::operator+(const ComplexNumber& val) {
    return ComplexNumber(r + val.r, im + val.im);
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber& val) {
    return { r * val.r - im * val.im, r * val.im + val.r * im };
}

ComplexNumber ComplexNumber::operator++() {
    r++;
    return *this;
}

ComplexNumber ComplexNumber::operator++(int) {
    ComplexNumber copy = *this;
    ++r;
    return copy;
}




double ComplexNumber::getRealPart() {
    return r;
}

double ComplexNumber::getImaginaryPart() {
    return im;
}
