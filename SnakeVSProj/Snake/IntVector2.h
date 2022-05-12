#ifndef INT_VECTOR_2_H
#define INT_VECTOR_2_H

#include <math.h>

struct IntVector2
{
    // Static constants
    static const IntVector2 ZERO;

    IntVector2() {}

    IntVector2(int inX, int inY)
        : x(inX)
        , y(inY)
    {
    }

    IntVector2(const IntVector2& intVector2);

    void Set(int inX, int inY);

    float GetLength() const;
    float GetLengthSqrd() const;

    bool operator==(const IntVector2& right) const;
    bool operator!=(const IntVector2& right) const;

    IntVector2& operator=(const IntVector2& right);

    int& operator [] (unsigned int i);
    const int& operator [] (unsigned int i) const;

    IntVector2& operator += (const IntVector2& v);
    IntVector2& operator -= (const IntVector2& v);
    IntVector2& operator *= (int i);

    int x;
    int y;
};

//Global operators
IntVector2              operator - (const IntVector2& a);
IntVector2              operator + (const IntVector2& a, const IntVector2& b);
IntVector2              operator - (const IntVector2& a, const IntVector2& b);
IntVector2              operator * (const IntVector2& a, int i);
IntVector2              operator * (int i, const IntVector2& a);
IntVector2              operator / (const IntVector2& a, int i);

//Inline functions
inline void IntVector2::Set(int inX, int inY)
{
    x = inX;
    y = inY;
}

inline bool IntVector2::operator==(const IntVector2& right) const
{
    return x == right.x && y == right.y;
}

inline bool IntVector2::operator!=(const IntVector2& right) const
{
    return x != right.x || y != right.y;
}

inline IntVector2& IntVector2::operator=(const IntVector2& other)
{
    x = other.x;
    y = other.y;
    return *this;
}

inline int& IntVector2::operator [] (unsigned int i)
{
    return *(&x + i);
}

inline const int& IntVector2::operator [] (unsigned int i) const
{
    return *(&x + i);
}

inline IntVector2& IntVector2::operator += (const IntVector2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

inline IntVector2& IntVector2::operator -= (const IntVector2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

inline IntVector2& IntVector2::operator *= (int i)
{
    x *= i;
    y *= i;
    return *this;
}

//External helper operators
inline IntVector2 operator - (const IntVector2& a)
{
    return IntVector2(-a.x, -a.y);
}

inline IntVector2 operator + (const IntVector2& a, const IntVector2& b)
{
    IntVector2 ret(a);
    ret += b;
    return ret;
}

inline IntVector2 operator - (const IntVector2& a, const IntVector2& b)
{
    IntVector2 ret(a);
    ret -= b;
    return ret;
}

inline IntVector2  operator * (const IntVector2& a, int i)
{
    return IntVector2(a.x * i, a.y * i);
}

inline IntVector2 operator * (int i, const IntVector2& a)
{
    return IntVector2(a.x * i, a.y * i);
}

inline IntVector2  operator / (const IntVector2& a, int i)
{
    return IntVector2(a.x / i, a.y / i);
}

inline float IntVector2::GetLength() const
{
    return sqrtf(GetLengthSqrd());
}

inline float IntVector2::GetLengthSqrd() const
{
    return static_cast<float>(x * x + y * y);
}

#endif //VECTOR_2_H

