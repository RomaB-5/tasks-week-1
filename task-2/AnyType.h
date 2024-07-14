#include <cstddef>
#include <typeinfo>
#include <algorithm>
#include <stdexcept>

enum class FundamentalType {
    bool_,
    signed_char,
    unsigned_char,
    short_int,
    unsigned_short_int,
    int_,
    unsigned_int,
    long_int,
    unsigned_long_int,
    long_long_int,
    unsigned_long_long_int,
    float_,
    double_,
    long_double,
    wchar_t_,
    char16_t_,
    char32_t_,
    void_,
    nullptr_t_
};

struct AnyType {
    static int constexpr max_size = std::max({sizeof(int), sizeof(float), sizeof(double), sizeof(bool), sizeof(char), sizeof(unsigned char), sizeof(short int), sizeof(unsigned short int), sizeof(long int), sizeof(unsigned long int), sizeof(long long int), sizeof(unsigned long long int), sizeof(long double), sizeof(wchar_t), sizeof(char16_t), sizeof(char32_t), sizeof(void*), sizeof(std::nullptr_t)});
    FundamentalType type;
    std::byte value[max_size];

    AnyType(int i) : type(FundamentalType::int_) {
        *reinterpret_cast<int*>(value) = i;
    }

    AnyType(float f) : type(FundamentalType::float_) {
        *reinterpret_cast<float*>(value) = f;
    }

    AnyType(double d) : type(FundamentalType::double_) {
        *reinterpret_cast<double*>(value) = d;
    }

    AnyType(bool b) : type(FundamentalType::bool_) {
        *reinterpret_cast<bool*>(value) = b;
    }

    AnyType(char c) : type(FundamentalType::signed_char) {
        *reinterpret_cast<char*>(value) = c;
    }

    AnyType(unsigned char uc) : type(FundamentalType::unsigned_char) {
        *reinterpret_cast<unsigned char*>(value) = uc;
    }

    AnyType(short int si) : type(FundamentalType::short_int) {
        *reinterpret_cast<short int*>(value) = si;
    }

    AnyType(unsigned short int usi) : type(FundamentalType::unsigned_short_int) {
        *reinterpret_cast<unsigned short int*>(value) = usi;
    }

    AnyType(long int li) : type(FundamentalType::long_int) {
        *reinterpret_cast<long int*>(value) = li;
    }

    AnyType(unsigned long int uli) : type(FundamentalType::unsigned_long_int) {
        *reinterpret_cast<unsigned long int*>(value) = uli;
    }

    AnyType(long long int lli) : type(FundamentalType::long_long_int) {
        *reinterpret_cast<long long int*>(value) = lli;
    }

    AnyType(unsigned long long int ulli) : type(FundamentalType::unsigned_long_long_int) {
        *reinterpret_cast<unsigned long long int*>(value) = ulli;
    }

    AnyType(long double ld) : type(FundamentalType::long_double) {
        *reinterpret_cast<long double*>(value) = ld;
    }

    AnyType(wchar_t wc) : type(FundamentalType::wchar_t_) {
        *reinterpret_cast<wchar_t*>(value) = wc;
    }

    AnyType(char16_t c16) : type(FundamentalType::char16_t_) {
        *reinterpret_cast<char16_t*>(value) = c16;
    }

    AnyType(char32_t c32) : type(FundamentalType::char32_t_) {
        *reinterpret_cast<char32_t*>(value) = c32;
    }
    
    AnyType(AnyType const& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    AnyType(AnyType&& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    ~AnyType() = default;

    explicit operator int() const {
        if (type != FundamentalType::int_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<int const*>(value);
    }

    explicit operator float() const {
        if (type != FundamentalType::float_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<float const*>(value);
    }

    explicit operator double() const {
        if (type != FundamentalType::double_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<double const*>(value);
    }

    explicit operator bool() const {
        if (type != FundamentalType::bool_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<bool const*>(value);
    }

    explicit operator char() const {
        if (type != FundamentalType::signed_char) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char const*>(value);
    }

    explicit operator unsigned char() const {
        if (type != FundamentalType::unsigned_char) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned char const*>(value);
    }

    explicit operator short int() const {
        if (type != FundamentalType::short_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<short int const*>(value);
    }

    explicit operator unsigned short int() const {
        if (type != FundamentalType::unsigned_short_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned short int const*>(value);
    }

    explicit operator long int() const {
        if (type != FundamentalType::long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long int const*>(value);
    }

    explicit operator unsigned long int() const {
        if (type != FundamentalType::unsigned_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long int const*>(value);
    }

    explicit operator long long int() const {
        if (type != FundamentalType::long_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long long int const*>(value);
    }

    explicit operator unsigned long long int() const {
        if (type != FundamentalType::unsigned_long_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long long int const*>(value);
    }

    explicit operator long double() const {
        if (type != FundamentalType::long_double) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long double const*>(value);
    }

    explicit operator wchar_t() const {
        if (type != FundamentalType::wchar_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<wchar_t const*>(value);
    }

    explicit operator char16_t() const {
        if (type != FundamentalType::char16_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char16_t const*>(value);
    }

    explicit operator char32_t() const {
        if (type != FundamentalType::char32_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char32_t const*>(value);
    }

    explicit operator void*() const = delete;

    explicit operator std::nullptr_t() const = delete;

    explicit operator FundamentalType() const {
        return type;
    }


    AnyType& operator=(const AnyType& other) {
        type = other.type;
        std::copy(other.value, other.value + max_size, value);
        return *this;
    }

    AnyType& operator=(AnyType&& other) {
        type = other.type;
        std::copy(other.value, other.value + max_size, value);
        return *this;
    }

    AnyType& operator=(int i) {
        type = FundamentalType::int_;
        *reinterpret_cast<int*>(value) = i;
        return *this;
    }

    AnyType& operator=(float f) {
        type = FundamentalType::float_;
        *reinterpret_cast<float*>(value) = f;
        return *this;
    }

    AnyType& operator=(double d) {
        type = FundamentalType::double_;
        *reinterpret_cast<double*>(value) = d;
        return *this;
    }

    AnyType& operator=(bool b) {
        type = FundamentalType::bool_;
        *reinterpret_cast<bool*>(value) = b;
        return *this;
    }

    AnyType& operator=(char c) {
        type = FundamentalType::signed_char;
        *reinterpret_cast<char*>(value) = c;
        return *this;
    }

    AnyType& operator=(unsigned char uc) {
        type = FundamentalType::unsigned_char;
        *reinterpret_cast<unsigned char*>(value) = uc;
        return *this;
    }

    AnyType& operator=(short int si) {
        type = FundamentalType::short_int;
        *reinterpret_cast<short int*>(value) = si;
        return *this;
    }

    AnyType& operator=(unsigned short int usi) {
        type = FundamentalType::unsigned_short_int;
        *reinterpret_cast<unsigned short int*>(value) = usi;
        return *this;
    }

    AnyType& operator=(long int li) {
        type = FundamentalType::long_int;
        *reinterpret_cast<long int*>(value) = li;
        return *this;
    }

    AnyType& operator=(unsigned long int uli) {
        type = FundamentalType::unsigned_long_int;
        *reinterpret_cast<unsigned long int*>(value) = uli;
        return *this;
    }

    AnyType& operator=(long long int lli) {
        type = FundamentalType::long_long_int;
        *reinterpret_cast<long long int*>(value) = lli;
        return *this;
    }

    AnyType& operator=(unsigned long long int ulli) {
        type = FundamentalType::unsigned_long_long_int;
        *reinterpret_cast<unsigned long long int*>(value) = ulli;
        return *this;
    }

    AnyType& operator=(long double ld) {
        type = FundamentalType::long_double;
        *reinterpret_cast<long double*>(value) = ld;
        return *this;
    }

    AnyType& operator=(wchar_t wc) {
        type = FundamentalType::wchar_t_;
        *reinterpret_cast<wchar_t*>(value) = wc;
        return *this;
    }

    AnyType& operator=(char16_t c16) {
        type = FundamentalType::char16_t_;
        *reinterpret_cast<char16_t*>(value) = c16;
        return *this;
    }

    AnyType& operator=(char32_t c32) {
        type = FundamentalType::char32_t_;
        *reinterpret_cast<char32_t*>(value) = c32;
        return *this;
    }

    AnyType& operator=(void* v) = delete;

    AnyType& operator=(std::nullptr_t n) = delete;

    void clear() {
        std::fill(value, value + max_size, std::byte{0});
        type = FundamentalType::void_; // ???
    }
};