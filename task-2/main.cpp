#include "AnyType.h"
#include <iostream>

int main() {
    AnyType a(5);
    AnyType b(5.0f);
    AnyType c(5.0);
    AnyType d(true);
    AnyType e('a');
    AnyType f((unsigned char) 'a');
    AnyType g((short int) 5);

    int i = static_cast<int>(a);
    try {
    float j = static_cast<float>(a);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}