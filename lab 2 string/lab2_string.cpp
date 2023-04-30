#include <iostream>
#include <cstring>
#include "CustomString.h"

std::ostream& operator<<(std::ostream& out, pb::CustomString& s) {
    char* str = s.c_str();
    for (int i = 0; i < s.length(); i++) {
        out << str[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, pb::CustomString& s) {
    char* str = new char[INT_MAX];
    in >> str;
    s = pb::CustomString(str);
    delete str;
    return in;
}


int main() {
    pb::CustomString a = pb::CustomString("aas");
    pb::CustomString b = pb::CustomString("bb");
   
    pb::CustomString c = a + b;
    pb::CustomString y;
    pb::CustomString u = "aaa";
    pb::CustomString p = b;
   
    a[1] = 'b';
    std::cout << a << std::endl;
    a += b;
    std::cout << a << std::endl;
    bool t = 0;
    t = (a == b);
    std::cout << t << std::endl;
    std::cout << y<<std::endl;
    std::cin >> y;
    std::cout << std::endl;
    std::cout << y << std::endl;
   
    std::cout << a.length() << std::endl;
    std::cout << b.length() << std::endl;
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    
    std::cout << a[10] << std::endl;
    std::cout << a.at(10) << std::endl;
    std::cout << a.c_str() << std::endl;
    std::cout << a.find('s') << std::endl;
   
   
    return 0;
}
