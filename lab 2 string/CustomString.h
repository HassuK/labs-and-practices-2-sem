#pragma once

#include <cstring>
#include <istream>

namespace pb {
    class CustomString {
    private:
        char* str = nullptr;
        std::size_t size;
    public:
        CustomString(size_t size=0, char base_char='\0');
        CustomString(const char* str);
        CustomString(const CustomString& s);
       
        ~CustomString();
        char at(size_t index);
        size_t length() ;
        char* c_str();
        int find(char c);
        CustomString& operator += (const CustomString& str);
        CustomString& operator = (const CustomString& str);
        CustomString operator + (const CustomString& str);
        char& operator [](size_t index);
        bool operator == (const CustomString& str);
        bool operator < (const CustomString& str);
        bool operator > (const CustomString& str);

    };


}