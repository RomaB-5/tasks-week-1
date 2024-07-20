#include <algorithm>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <bit>
#include <format>

template <class C>
struct TypeIdentifier {
    constexpr static int _id{};
    constexpr static std::uint64_t id() {
        return reinterpret_cast<std::uint64_t>(&_id);
    }
};

class BadAnyTypeException: public std::exception
{
public:
    BadAnyTypeException() = default;

    std::string what()
    {
        return std::format("Bad AnyType cast. Type mismatch");
    }
};


class AnyType {
public:

    AnyType() = delete;
    ~AnyType() = default;

    AnyType(const AnyType& other) 
    {
    m_type_id = other.m_type_id;
    std::memcpy(m_data, other.m_data, MAX_SIZE);
    }
    
    template <class T>
    AnyType(const T& value) 
    {
        StaticTypeCheck<T>();

        m_type_id = TypeIdentifier<T>::id();
        std::memcpy(m_data, &value, sizeof(T));
    }

    template <class T>
    explicit operator T() const 
    {
        if (m_type_id != TypeIdentifier<T>::id()) {
            throw BadAnyTypeException();
        }
        return *reinterpret_cast<const T*>(m_data);
    }


    template <class T>
    AnyType& operator=(const T& value) 
    {
        StaticTypeCheck<T>();

        m_type_id = TypeIdentifier<T>::id();
        std::memcpy(m_data, &value, sizeof(T));
        return *this;
    }

    template <class T>
    T& to() 
    {
        if (m_type_id != TypeIdentifier<T>::id()) {
            throw BadAnyTypeException();

        }
        return *reinterpret_cast<T*>(m_data);
    }

    static void Swap(AnyType& a, AnyType& b) 
    {
        std::swap(a.m_data, b.m_data);
        std::swap(a.m_type_id, b.m_type_id);
    }

    std::uint64_t get_type_id()
    {
        return m_type_id;
    }

private:
    static int constexpr MAX_SIZE = std::max({sizeof(int), sizeof(float), sizeof(double), 
                                              sizeof(bool), sizeof(char), sizeof(unsigned char), 
                                              sizeof(short int), sizeof(unsigned short int), 
                                              sizeof(long int), sizeof(unsigned long int), 
                                              sizeof(long long int), sizeof(unsigned long long int), 
                                              sizeof(long double), sizeof(wchar_t), sizeof(char16_t), 
                                              sizeof(char32_t), sizeof(void*), sizeof(std::nullptr_t)});

    std::byte m_data[MAX_SIZE] = {};
    std::uint64_t m_type_id = TypeIdentifier<void>::id();

    template <class T>
    inline void StaticTypeCheck() 
    {
    static_assert(std::is_fundamental_v<T>, "Only fundamental types (except void and nullptr_t) are supported");
    static_assert(!std::is_same_v<T, void>, "void is not supported");
    static_assert(!std::is_same_v<T, std::nullptr_t>, "nullptr_t is not supported");
    }
};