#include <algorithm>
enum class FundamentalType: unsigned char;

class AnyType {
public:

    AnyType(int i);
    AnyType(float f);
    AnyType(double d);
    AnyType(bool b);
    AnyType(char c);
    AnyType(unsigned char uc);
    AnyType(short int si);
    AnyType(unsigned short int usi);
    AnyType(long int li);
    AnyType(unsigned long int uli);
    AnyType(long long int lli);
    AnyType(unsigned long long int ulli);
    AnyType(long double ld);
    AnyType(wchar_t wc);
    AnyType(char16_t c16);
    AnyType(char32_t c32);
    AnyType(void* v) = delete;
    AnyType(std::nullptr_t n) = delete;
    AnyType(AnyType const& other);
    AnyType(AnyType&& other);
    ~AnyType() = default;

    explicit operator int() const;
    explicit operator float() const;
    explicit operator double() const;
    explicit operator bool() const;
    explicit operator char() const;
    explicit operator unsigned char() const;
    explicit operator short int() const;
    explicit operator unsigned short int() const;
    explicit operator long int() const;
    explicit operator unsigned long int() const;
    explicit operator long long int() const;
    explicit operator unsigned long long int() const;
    explicit operator long double() const;
    explicit operator wchar_t() const;
    explicit operator char16_t() const;
    explicit operator char32_t() const;
    explicit operator void*() const = delete;
    explicit operator std::nullptr_t() const = delete;

    explicit operator FundamentalType() const;


    AnyType& operator=(const AnyType& other);
    AnyType& operator=(AnyType&& other);
    AnyType& operator=(int i);
    AnyType& operator=(float f);
    AnyType& operator=(double d);
    AnyType& operator=(bool b);
    AnyType& operator=(char c);
    AnyType& operator=(unsigned char uc);
    AnyType& operator=(short int si);
    AnyType& operator=(unsigned short int usi);
    AnyType& operator=(long int li);
    AnyType& operator=(unsigned long int uli);
    AnyType& operator=(long long int lli);
    AnyType& operator=(unsigned long long int ulli);
    AnyType& operator=(long double ld);
    AnyType& operator=(wchar_t wc);
    AnyType& operator=(char16_t c16);
    AnyType& operator=(char32_t c32);
    AnyType& operator=(void* v) = delete;
    AnyType& operator=(std::nullptr_t n) = delete;

    void Clear();

    static void Swap(AnyType& a, AnyType& b) {
        std::swap(a, b);
    }

private:
    static int constexpr max_size = std::max({sizeof(int), sizeof(float), sizeof(double), sizeof(bool), sizeof(char), sizeof(unsigned char), sizeof(short int), sizeof(unsigned short int), sizeof(long int), sizeof(unsigned long int), sizeof(long long int), sizeof(unsigned long long int), sizeof(long double), sizeof(wchar_t), sizeof(char16_t), sizeof(char32_t), sizeof(void*), sizeof(std::nullptr_t)});
    FundamentalType type;
    std::byte value[max_size];
};