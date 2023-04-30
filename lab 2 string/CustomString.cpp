#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CustomString.h"

namespace pb {
    
    CustomString::CustomString(const char* str) { //constructor by string
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
        size = strlen(str);
        this->str[size] = '\0';
    }

    CustomString::CustomString(size_t size, char base_char) :size(size) { //base constructor
        str = new char[size + 1];
        memset(str, base_char, size);
        str[size] = '\0';
    }


    CustomString::CustomString(const CustomString& s) { //copy constructor 
        size = s.size;
        str = new char[size + 1];
        strncpy_s(str, size + 1, s.str, size);
    }

    size_t CustomString::length() {
        return size;
    }

    char CustomString::at(size_t index) {
        if (index >= size) {
            return 0;
        }
        return str[index];
    }

    char* CustomString::c_str() {
        return str;
    }

    int CustomString::find(char c) {
        size_t ind = -1;
        for (int i = 0; i < size; i++) {
            if (str[i] == c) {
                ind = i;
                break;
            }
        }
        return ind;
    }

    CustomString& CustomString::operator+=(const CustomString& str) {
        char* new_str = new char[size + str.size + 1];
        memcpy(new_str, this->str, size);
        memcpy(new_str + size, str.str, str.size);
        size = size + str.size;
        new_str[size] = '\0';
        delete this->str;
        this->str = new_str;
        return *this;
    }

    CustomString CustomString::operator+(const CustomString& str) {
        CustomString res = CustomString("");
        res += *this;
        res += str;
        return res;
    }

    char& CustomString::operator[](size_t index)
    {
        return str[index];
    }


    bool CustomString::operator==(const CustomString& str) {
        if (this->size != str.size) {
            return false;
        }
        bool flag = true;
        for (int i = 0; i < size; i++) {
            if (str.str[i] != this->str[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    bool CustomString::operator < (const CustomString& str) {
        if (this->size < str.size) {
            return true;
        }
        else if (this->size > str.size) {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (str.str[i] > this->str[i]) {
                flag = true;
            }
            if (str.str[i] < this->str[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }


    bool CustomString::operator > (const CustomString& str) {
        if (this->size > str.size) {
            return true;
        }
        else if (this->size < str.size) {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (str.str[i] < this->str[i]) {
                flag = true;
            }
            if (str.str[i] > this->str[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    
    }


    CustomString& CustomString::operator=(const CustomString& str) {
        size = str.size;
        this->str = new char[size + 1];
        strncpy_s(this->str, size + 1, str.str, size);
        return *this;
    }

    CustomString::~CustomString() {
        delete[] str;
    }


}