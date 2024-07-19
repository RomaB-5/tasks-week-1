#include "AnyType.h"

#include <cstddef>
#include <typeinfo>
#include <algorithm>
#include <stdexcept>

enum class FundamentalType: unsigned char
{
    BOOL,
    SIGNED_CHAR,
    UNSIGNED_CHAR,
    SHORT_INT,
    UNSIGNED_SHORT_INT,
    INT,
    UNSIGNED_INT,
    LONG_INT,
    UNSIGNED_LONG_INT,
    LONG_LONG_INT,
    UNSIGNED_LONG_LONG_INT,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE,
    WCHAR_T,
    CHAR16_T,
    cCHAR32_T,
    VOID,
    NULLPTR_T
};


    AnyType::AnyType(int i) : type(FundamentalType::INT) {
        *reinterpret_cast<int*>(value) = i;
    }

    AnyType::AnyType(float f) : type(FundamentalType::FLOAT) {
        *reinterpret_cast<float*>(value) = f;
    }

    AnyType::AnyType(double d) : type(FundamentalType::DOUBLE) {
        *reinterpret_cast<double*>(value) = d;
    }

    AnyType::AnyType(bool b) : type(FundamentalType::BOOL) {
        *reinterpret_cast<bool*>(value) = b;
    }

    AnyType::AnyType(char c) : type(FundamentalType::SIGNED_CHAR) {
        *reinterpret_cast<char*>(value) = c;
    }

    AnyType::AnyType(unsigned char uc) : type(FundamentalType::UNSIGNED_CHAR) {
        *reinterpret_cast<unsigned char*>(value) = uc;
    }

    AnyType::AnyType(short int si) : type(FundamentalType::SHORT_INT) {
        *reinterpret_cast<short int*>(value) = si;
    }

    AnyType::AnyType(unsigned short int usi) : type(FundamentalType::UNSIGNED_SHORT_INT) {
        *reinterpret_cast<unsigned short int*>(value) = usi;
    }

    AnyType::AnyType(long int li) : type(FundamentalType::LONG_INT) {
        *reinterpret_cast<long int*>(value) = li;
    }

    AnyType::AnyType(unsigned long int uli) : type(FundamentalType::UNSIGNED_LONG_INT) {
        *reinterpret_cast<unsigned long int*>(value) = uli;
    }

    AnyType::AnyType(long long int lli) : type(FundamentalType::LONG_LONG_INT) {
        *reinterpret_cast<long long int*>(value) = lli;
    }

    AnyType::AnyType(unsigned long long int ulli) : type(FundamentalType::UNSIGNED_LONG_LONG_INT) {
        *reinterpret_cast<unsigned long long int*>(value) = ulli;
    }

    AnyType::AnyType(long double ld) : type(FundamentalType::LONG_DOUBLE) {
        *reinterpret_cast<long double*>(value) = ld;
    }

    AnyType::AnyType(wchar_t wc) : type(FundamentalType::WCHAR_T) {
        *reinterpret_cast<wchar_t*>(value) = wc;
    }

    AnyType::AnyType(char16_t c16) : type(FundamentalType::CHAR16_T) {
        *reinterpret_cast<char16_t*>(value) = c16;
    }

    AnyType::AnyType(char32_t c32) : type(FundamentalType::cCHAR32_T) {
        *reinterpret_cast<char32_t*>(value) = c32;
    }
    
    AnyType::AnyType(AnyType const& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    AnyType::AnyType(AnyType&& other) : type(other.type) {
        std::copy(other.value, other.value + max_size, value);
    }

    AnyType::operator int() const {
        if (type != FundamentalType::INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<int const*>(value);
    }

    AnyType::operator float() const {
        if (type != FundamentalType::FLOAT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<float const*>(value);
    }

    AnyType::operator double() const {
        if (type != FundamentalType::DOUBLE) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<double const*>(value);
    }

    AnyType::operator bool() const {
        if (type != FundamentalType::BOOL) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<bool const*>(value);
    }

    AnyType::operator char() const {
        if (type != FundamentalType::SIGNED_CHAR) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char const*>(value);
    }

    AnyType::operator unsigned char() const {
        if (type != FundamentalType::UNSIGNED_CHAR) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned char const*>(value);
    }

    AnyType::operator short int() const {
        if (type != FundamentalType::SHORT_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<short int const*>(value);
    }

    AnyType::operator unsigned short int() const {
        if (type != FundamentalType::UNSIGNED_SHORT_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned short int const*>(value);
    }

    AnyType::operator long int() const {
        if (type != FundamentalType::LONG_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long int const*>(value);
    }

    AnyType::operator unsigned long int() const {
        if (type != FundamentalType::UNSIGNED_LONG_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long int const*>(value);
    }

    AnyType::operator long long int() const {
        if (type != FundamentalType::LONG_LONG_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long long int const*>(value);
    }

    AnyType::operator unsigned long long int() const {
        if (type != FundamentalType::UNSIGNED_LONG_LONG_INT) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<unsigned long long int const*>(value);
    }

    AnyType::operator long double() const {
        if (type != FundamentalType::LONG_DOUBLE) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<long double const*>(value);
    }

    AnyType::operator wchar_t() const {
        if (type != FundamentalType::WCHAR_T) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<wchar_t const*>(value);
    }

    AnyType::operator char16_t() const {
        if (type != FundamentalType::CHAR16_T) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char16_t const*>(value);
    }

    AnyType::operator char32_t() const {
        if (type != FundamentalType::cCHAR32_T) {
            throw std::runtime_error("Bad cast");
        }
        return *reinterpret_cast<char32_t const*>(value);
    }


    AnyType::operator FundamentalType() const {
        return type;
    }


    AnyType& AnyType::operator=(const AnyType& other) {
        type = other.type;
        std::copy(other.value, other.value + max_size, value);
        return *this;
    }

    AnyType& AnyType::operator=(AnyType&& other) {
        type = other.type;
        std::copy(other.value, other.value + max_size, value);
        return *this;
    }

    AnyType& AnyType::operator=(int i) {
        type = FundamentalType::INT;
        *reinterpret_cast<int*>(value) = i;
        return *this;
    }

    AnyType& AnyType::operator=(float f) {
        type = FundamentalType::FLOAT;
        *reinterpret_cast<float*>(value) = f;
        return *this;
    }

    AnyType& AnyType::operator=(double d) {
        type = FundamentalType::DOUBLE;
        *reinterpret_cast<double*>(value) = d;
        return *this;
    }

    AnyType& AnyType::operator=(bool b) {
        type = FundamentalType::BOOL;
        *reinterpret_cast<bool*>(value) = b;
        return *this;
    }

    AnyType& AnyType::operator=(char c) {
        type = FundamentalType::SIGNED_CHAR;
        *reinterpret_cast<char*>(value) = c;
        return *this;
    }

    AnyType& AnyType::operator=(unsigned char uc) {
        type = FundamentalType::UNSIGNED_CHAR;
        *reinterpret_cast<unsigned char*>(value) = uc;
        return *this;
    }

    AnyType& AnyType::operator=(short int si) {
        type = FundamentalType::SHORT_INT;
        *reinterpret_cast<short int*>(value) = si;
        return *this;
    }

    AnyType& AnyType::operator=(unsigned short int usi) {
        type = FundamentalType::UNSIGNED_SHORT_INT;
        *reinterpret_cast<unsigned short int*>(value) = usi;
        return *this;
    }

    AnyType& AnyType::operator=(long int li) {
        type = FundamentalType::LONG_INT;
        *reinterpret_cast<long int*>(value) = li;
        return *this;
    }

    AnyType& AnyType::operator=(unsigned long int uli) {
        type = FundamentalType::UNSIGNED_LONG_INT;
        *reinterpret_cast<unsigned long int*>(value) = uli;
        return *this;
    }

    AnyType& AnyType::operator=(long long int lli) {
        type = FundamentalType::LONG_LONG_INT;
        *reinterpret_cast<long long int*>(value) = lli;
        return *this;
    }

    AnyType& AnyType::operator=(unsigned long long int ulli) {
        type = FundamentalType::UNSIGNED_LONG_LONG_INT;
        *reinterpret_cast<unsigned long long int*>(value) = ulli;
        return *this;
    }

    AnyType& AnyType::operator=(long double ld) {
        type = FundamentalType::LONG_DOUBLE;
        *reinterpret_cast<long double*>(value) = ld;
        return *this;
    }

    AnyType& AnyType::operator=(wchar_t wc) {
        type = FundamentalType::WCHAR_T;
        *reinterpret_cast<wchar_t*>(value) = wc;
        return *this;
    }

    AnyType& AnyType::operator=(char16_t c16) {
        type = FundamentalType::CHAR16_T;
        *reinterpret_cast<char16_t*>(value) = c16;
        return *this;
    }

    AnyType& AnyType::operator=(char32_t c32) {
        type = FundamentalType::cCHAR32_T;
        *reinterpret_cast<char32_t*>(value) = c32;
        return *this;
    }


    void AnyType::Clear() {
        std::fill(value, value + max_size, std::byte{0});
        type = FundamentalType::VOID;
    }

