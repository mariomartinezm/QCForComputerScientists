#ifndef QCCOMPLEX_H
#define QCCOMPLEX_H

#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

namespace qccomplex
{
    constexpr float PI = 3.1415926535F;

    template <typename T>
    struct ComplexNumber
    {
        T re;
        T im;
    };

    template <typename T, size_t N>
    using CVector = std::array<ComplexNumber<T>, N>;


    template <typename T, size_t M, size_t N>
    using CMatrix = std::array<std::array<ComplexNumber<T>, N>, M>;

    // Drill 1.1.1
    // Write a program that accepts two complex numbers and outputs their sum
    // and product.
    template <typename T>
    ComplexNumber<T> operator+(const ComplexNumber<T>& a, const ComplexNumber<T>& b)
    {
        ComplexNumber<T> result = { a.re + b.re, a.im + b.im };

        return result;
    }

    template <typename T>
    ComplexNumber<T> operator*(const ComplexNumber<T>& a, const ComplexNumber<T>& b)
    {
        ComplexNumber<T> result = { a.re * b.re - a.im * b.im,
                                    a.re * b.im + a.im * b.re };

        return result;
    }

    // Drill 1.2.1
    // Take the program that you wrote in the last programming drill and make
    // it also perform subtraction and division of complex numbers. In
    // addition, let the user enter a complex number and have the computer
    // return its modulus and conjugate.
    template <typename T>
    ComplexNumber<T> operator-(const ComplexNumber<T>& a, const ComplexNumber<T>& b)
    {
        ComplexNumber<T> result = { a.re - b.re, a.im - b.im };

        return result;
    }

    template <typename T>
    ComplexNumber<T> operator/(const ComplexNumber<T>& a, const ComplexNumber<T>& b)
    {
        ComplexNumber<T> result = { (a.re * a.im + b.re * b.im) / (a.im * a.im + b.im * b.im ),
                                    (a.im * b.re - a.re * b.im) / (a.im * a.im + b.im * b.im) };

        return result;
    }

    template<typename T>
    float modulus(const ComplexNumber<T>& c)
    {
        return sqrtf(c.re * c.re + c.im * c.im);
    }

    template<typename T>
    ComplexNumber<T> conjugate(const ComplexNumber<T>& c)
    {
        return ComplexNumber<T> { c.re, -c.im };
    }

    // Drill 1.3.1
    // Write a program that converts a complex number from its cartesian
    // representation to its polar representation and viceversa.
    template<typename T>
    float phase(const ComplexNumber<T>& c)
    {
        return std::atan2(c.im, c.re);
    }

    // Drill 2.1.1
    // Write the three functions that perform the addition, inverse, and scalar
    // multiplication operations for C^n, i.e., write a function that accepts
    // the appropriate input for each of the operations and outputs the vector.
    template<typename T, size_t N>
    CVector<T, N> operator+(const CVector<T, N>& a, const CVector<T, N>& b)
    {
        CVector<T, N> result;

        std::transform(a.begin(), a.end(), b.begin(), result.begin(), [] (auto& lhs, auto& rhs)
                       {
                       return lhs + rhs;
                       });

        return result;
    }

    template<typename T, size_t N>
    CVector<T, N> operator*(const ComplexNumber<T> c, const CVector<T, N>& a)
    {
        CVector<T, N> result;

        std::transform(a.begin(), a.end(), result.begin(), [c](auto& ai)
                       {
                       return c * ai;
                       });

        return result;
    }

    template<typename T, size_t N>
    CVector<T, N> inverse(const CVector<T, N>& a)
    {
        CVector<T, N> result;

        std::transform(a.begin(), a.end(), result.begin(), [ ](auto& ai)
                       {
                       return qccomplex::ComplexNumber<int>{-1, 0} * ai;
                       });

        return result;
    }

    // Drill 2.2.1
    // Convert your functions from the last programming drill so that instead
    // of accepting elements of C^n, they accepts elements of C^(m * n).
    template<typename T, size_t M, size_t N>
    CMatrix<T, M, N> operator+(const CMatrix<T, M, N>& a, const CMatrix<T, M, N>& b)
    {
        CMatrix<T, M, N> result;

        for(size_t row = 0; row < M; ++row)
        {
            for(size_t col = 0; col < N; ++col)
            {
                result[row][col] = a[row][col] + b[row][col];
            }
        }

        return result;
    }

    template<typename T, size_t M, size_t N>
    CMatrix<T, M, N> operator*(const ComplexNumber<T>& c, const CMatrix<T, M, N>& a)
    {
        CMatrix<T, M, N> result;

        for(size_t row = 0; row < M; ++row)
        {
            for(size_t col = 0; col < N; ++col)
            {
                result[row][col] = c * a[row][col];
            }
        }

        return result;
    }

    template<typename T, size_t M, size_t N>
    CMatrix<T, M, N> inverse(const CMatrix<T, M, N>& a)
    {
        CMatrix<T, M, N> result;

        for(size_t row = 0; row < M; ++row)
        {
            for(size_t col = 0; col < N; ++col)
            {
                result[row][col] = qccomplex::ComplexNumber<int>{-1, 0} * a[row][col];
            }
        }

        return result;
    }
}

#endif
