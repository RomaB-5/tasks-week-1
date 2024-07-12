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

    AnyType(AnyType const& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    AnyType(AnyType&& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    operator int() const {
        if (type != FundamentalType::int_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<int const*>(value);
    }

    operator float() const {
        if (type != FundamentalType::float_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<float const*>(value);
    }

    operator double() const {
        if (type != FundamentalType::double_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<double const*>(value);
    }

    operator bool() const {
        if (type != FundamentalType::bool_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<bool const*>(value);
    }

    operator char() const {
        if (type != FundamentalType::signed_char) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char const*>(value);
    }

    operator unsigned char() const {
        if (type != FundamentalType::unsigned_char) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned char const*>(value);
    }

    operator short int() const {
        if (type != FundamentalType::short_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<short int const*>(value);
    }

    operator unsigned short int() const {
        if (type != FundamentalType::unsigned_short_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned short int const*>(value);
    }

    operator long int() const {
        if (type != FundamentalType::long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long int const*>(value);
    }

    operator unsigned long int() const {
        if (type != FundamentalType::unsigned_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long int const*>(value);
    }

    operator long long int() const {
        if (type != FundamentalType::long_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long long int const*>(value);
    }

    operator unsigned long long int() const {
        if (type != FundamentalType::unsigned_long_long_int) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long long int const*>(value);
    }

    operator long double() const {
        if (type != FundamentalType::long_double) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long double const*>(value);
    }

    operator wchar_t() const {
        if (type != FundamentalType::wchar_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<wchar_t const*>(value);
    }

    operator char16_t() const {
        if (type != FundamentalType::char16_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char16_t const*>(value);
    }

    operator char32_t() const {
        if (type != FundamentalType::char32_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char32_t const*>(value);
    }

    operator void*() const {
        if (type != FundamentalType::void_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<void* const*>(value);
    }

    operator std::nullptr_t() const {
        if (type != FundamentalType::nullptr_t_) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<std::nullptr_t const*>(value);
    }

    operator FundamentalType() const {
        return type;
    }

};