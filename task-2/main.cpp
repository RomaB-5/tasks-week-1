#include "AnyType.h"
#include <iostream>

int main() {
    AnyType a = 10;
    a = 10.f;
    a = 10.0;
    a = true;
    a = 'a';
    a = true;
    a = static_cast<wchar_t>('a');

    std::cout << static_cast<wchar_t>(a) << std::endl;
    a = 15.1;
    std::cout << static_cast<double>(a) << std::endl;

    a.clear();

    a = 10;
    std::cout << static_cast<int>(a) << std::endl;
}