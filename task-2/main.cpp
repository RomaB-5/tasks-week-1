#include "AnyType.h"

struct X 
{
    int x = 10;
    int y;
};

int main() {
    
    AnyType a(5);
    AnyType b(5.0);
    AnyType c(true);
    AnyType d('a');
    //AnyType e("Hello");
    AnyType f(5.0f);
    AnyType g(5.0L);
    AnyType h(L'a');
    AnyType i(u'a');
    //AnyType j(nullptr);
    //AnyType k(static_cast<void*>(nullptr));
    //AnyType l(static_cast<std::nullptr_t>(nullptr));
    AnyType m(static_cast<char16_t>(u'a'));
    AnyType n(static_cast<char32_t>(U'a'));
    AnyType o(static_cast<wchar_t>(L'a'));
    AnyType p(static_cast<unsigned char>(5));
    AnyType q(static_cast<unsigned short>(5));
    AnyType r(static_cast<unsigned int>(5));
    AnyType s(static_cast<unsigned long>(5));
    AnyType t(static_cast<unsigned long long>(5));
    AnyType u(static_cast<long double>(5.0L));
    AnyType v(static_cast<long long>(5));
    AnyType w(static_cast<long>(5));
    AnyType x(static_cast<int>(5));
    AnyType y(static_cast<float>(5.0f));
    AnyType z(static_cast<double>(5.0));

    AnyType res = 1;
    try 
    {
        res.to<double>();
    }
    catch (BadAnyTypeException &e)
    {
        std::cout<<e.what()<<std::endl;
    }

}