#include <gtest/gtest.h>
#include "AnyType.h"

TEST(AnyTypeConstructor, Int) {
    AnyType a(5);
    ASSERT_EQ(5, a.to<int>());
    ASSERT_EQ(5, static_cast<int>(a));
}

TEST(AnyTypeConstructor, Double) {
    AnyType a(5.0);
    ASSERT_EQ(5.0, a.to<double>());
    ASSERT_EQ(5.0, static_cast<double>(a));
}

TEST(AnyTypeConstructor, Bool) {
    AnyType a(true);
    ASSERT_EQ(true, a.to<bool>());
    ASSERT_EQ(true, static_cast<bool>(a));
}

TEST(AnyTypeConstructor, Char) {
    AnyType a('a');
    ASSERT_EQ('a', a.to<char>());
    ASSERT_EQ('a', static_cast<char>(a));
}

TEST(AnyTypeConstructor, Float) {
    AnyType a(5.0f);
    ASSERT_EQ(5.0f, a.to<float>());
    ASSERT_EQ(5.0f, static_cast<float>(a));
}

TEST(AnyTypeConstructor, LongDouble) {
    AnyType a(5.0L);
    ASSERT_EQ(5.0L, a.to<long double>());
    ASSERT_EQ(5.0L, static_cast<long double>(a));
}

TEST(AnyTypeConstructor, WideChar) {
    AnyType a(L'a');
    ASSERT_EQ(L'a', a.to<wchar_t>());
    ASSERT_EQ(L'a', static_cast<wchar_t>(a));
}

TEST(AnyTypeConstructor, Char16) {
    AnyType a(static_cast<char16_t>(u'a'));
    ASSERT_EQ(static_cast<char16_t>(u'a'), a.to<char16_t>());
    ASSERT_EQ(static_cast<char16_t>(u'a'), static_cast<char16_t>(a));
}

TEST(AnyTypeConstructor, Char32) {
    AnyType a(static_cast<char32_t>(U'a'));
    ASSERT_EQ(static_cast<char32_t>(U'a'), a.to<char32_t>());
    ASSERT_EQ(static_cast<char32_t>(U'a'), static_cast<char32_t>(a));
}

TEST(AnyTypeConstructor, UnsignedChar) {
    AnyType a(static_cast<unsigned char>(5));
    ASSERT_EQ(static_cast<unsigned char>(5), a.to<unsigned char>());
    ASSERT_EQ(static_cast<unsigned char>(5), static_cast<unsigned char>(a));
}

TEST(AnyTypeConstructor, UnsignedShort) {
    AnyType a(static_cast<unsigned short>(5));
    ASSERT_EQ(static_cast<unsigned short>(5), a.to<unsigned short>());
    ASSERT_EQ(static_cast<unsigned short>(5), static_cast<unsigned short>(a));
}

TEST(AnyTypeConstructor, UnsignedInt) {
    AnyType a(static_cast<unsigned int>(5));
    ASSERT_EQ(static_cast<unsigned int>(5), a.to<unsigned int>());
    ASSERT_EQ(static_cast<unsigned int>(5), static_cast<unsigned int>(a));
}

TEST(AnyTypeConstructor, UnsignedLong) {
    AnyType a(static_cast<unsigned long>(5));
    ASSERT_EQ(static_cast<unsigned long>(5), a.to<unsigned long>());
    ASSERT_EQ(static_cast<unsigned long>(5), static_cast<unsigned long>(a));
}

TEST(AnyTypeConstructor, UnsignedLongLong) {
    AnyType a(static_cast<unsigned long long>(5));
    ASSERT_EQ(static_cast<unsigned long long>(5), a.to<unsigned long long>());
    ASSERT_EQ(static_cast<unsigned long long>(5), static_cast<unsigned long long>(a));
}

TEST(AnyTypeConstructor, LongLong) {
    AnyType a(static_cast<long long>(5));
    ASSERT_EQ(static_cast<long long>(5), a.to<long long>());
    ASSERT_EQ(static_cast<long long>(5), static_cast<long long>(a));
}

TEST(AnyTypeConstructor, Long) {
    AnyType a(static_cast<long>(5));
    ASSERT_EQ(static_cast<long>(5), a.to<long>());
    ASSERT_EQ(static_cast<long>(5), static_cast<long>(a));
}


TEST(AnyTypeEqualOperator, MultyType){
    AnyType a(5);
    AnyType b(5.0);
    AnyType c(true);
    AnyType d('a');
    AnyType f(5.0f);
    AnyType g(5.0L);
    AnyType h(L'a');
    AnyType i(u'a');
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

    a = 6;
    b = 6.0;
    c = false;
    d = 'b';
    f = 6.0f;
    g = 6.0L;
    h = L'b';
    i = u'b';
    m = static_cast<char16_t>(u'b');
    n = static_cast<char32_t>(U'b');
    o = static_cast<wchar_t>(L'b');
    p = static_cast<unsigned char>(6);
    q = static_cast<unsigned short>(6);
    r = static_cast<unsigned int>(6);
    s = static_cast<unsigned long>(6);
    t = static_cast<unsigned long long>(6);
    u = static_cast<long double>(6.0L);
    v = static_cast<long long>(6);
    w = static_cast<long>(6);
    x = static_cast<int>(6);
    y = static_cast<float>(6.0f);
    z = static_cast<double>(6.0);

    ASSERT_EQ(6, a.to<int>());
    ASSERT_EQ(6.0, b.to<double>());
    ASSERT_EQ(false, c.to<bool>());
    ASSERT_EQ('b', d.to<char>());
    ASSERT_EQ(6.0f, f.to<float>());
    ASSERT_EQ(6.0L, g.to<long double>());

    AnyType test = AnyType(10).to<int>() + AnyType(20.5).to<double>();

    ASSERT_EQ(30.5, test.to<double>());
}

TEST(BadAnyTypeExceptionTest, Basic)
{
    AnyType x = 10;
    ASSERT_THROW(static_cast<double>(x), BadAnyTypeException);

    x = 10.0;
    ASSERT_THROW(static_cast<int>(x), BadAnyTypeException);
}

TEST(SwapTest, Basic)
{
    AnyType x = 10;
    AnyType y = 'a';

    ASSERT_TRUE(x.get_type_id() == TypeID<int>::id());
    ASSERT_TRUE(y.get_type_id() == TypeID<char>::id());

    ASSERT_EQ(x.to<int>(), 10);
    ASSERT_EQ(y.to<char>(), 'a');

    AnyType::Swap(x,y);

    ASSERT_TRUE(y.get_type_id() == TypeID<int>::id());
    ASSERT_TRUE(x.get_type_id() == TypeID<char>::id());

    ASSERT_EQ(y.to<int>(), 10);
    ASSERT_EQ(x.to<char>(), 'a');
}
