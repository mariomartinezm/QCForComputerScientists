#include <gtest/gtest.h>

#include "qccomplex.h"

TEST(TestAdd, BasicAssertions)
{
    qccomplex::ComplexNumber<int> a = { 2, 3 };
    qccomplex::ComplexNumber<int> b = { 2, 3 };

    EXPECT_EQ((a+b).re, 4);
    EXPECT_EQ((a+b).im, 6);

    qccomplex::ComplexNumber<float> c = { -2.3,  3.4 };
    qccomplex::ComplexNumber<float> d = {  2.3, -3.4 };

    EXPECT_NEAR((c+d).re, 0.0, 1e-6);
    EXPECT_NEAR((c+d).im, 0.0, 1e-6);
}

TEST(TestSubtraction, BasicAssertions)
{
    qccomplex::ComplexNumber<int> a = { 2, 3 };
    qccomplex::ComplexNumber<int> b = { 2, 3 };

    EXPECT_EQ((a-b).re, 0);
    EXPECT_EQ((a-b).im, 0);

    qccomplex::ComplexNumber<float> c = { -2.3,  3.4 };
    qccomplex::ComplexNumber<float> d = {  2.3, -3.4 };

    EXPECT_NEAR((c-d).re, -4.6, 1e-6);
    EXPECT_NEAR((c-d).im,  6.8, 1e-6);
}

TEST(TestMultiplication, BasicAssertions)
{
    qccomplex::ComplexNumber<int> a = { 0, 1 };
    qccomplex::ComplexNumber<int> b = { 0, 1 };

    EXPECT_EQ((a * b).re, -1);
    EXPECT_EQ((a * b).im,  0);
}

TEST(TestDivision, BasicAssertions)
{
    qccomplex::ComplexNumber<int> a = { -2, 1 };
    qccomplex::ComplexNumber<int> b = {  1, 2 };

    EXPECT_EQ((a / b).re, 0);
    EXPECT_EQ((a / b).im, 1);
}

TEST(Modulus, BasicAssertions)
{
    qccomplex::ComplexNumber<int> a = { 1, -1 };

    EXPECT_NEAR(qccomplex::modulus(a), sqrtf(2), 1e-6);
}

TEST(Conjugate, BasicAssertions)
{
    qccomplex::ComplexNumber<int> c     = { 1, -1 };
    auto cprime = qccomplex::conjugate(c);

    EXPECT_EQ(cprime.re,  c.re);
    EXPECT_EQ(cprime.im, -c.im);
}

TEST(Phase, BasicAssertions)
{
    qccomplex::ComplexNumber<int> c = { 1, 1 };

    EXPECT_NEAR(qccomplex::phase(c), qccomplex::PI / 4.0, 1e-6);
}

TEST(ComplexVector, BasicAssertions)
{
    qccomplex::CVector<int, 3> cv = {qccomplex::ComplexNumber<int>{ 2,  3},
                                     qccomplex::ComplexNumber<int>{ 1, -1},
                                     qccomplex::ComplexNumber<int>{-1,  0}};

    EXPECT_EQ(cv[0].re, 2);
    EXPECT_EQ(cv[0].im, 3);

    EXPECT_EQ(cv[1].re, 1);
    EXPECT_EQ(cv[1].im, -1);

    EXPECT_EQ(cv[2].re, -1);
    EXPECT_EQ(cv[2].im, 0);
}

TEST(CVectorAddition, BasicAssertions)
{
    qccomplex::CVector<int, 2> a = {qccomplex::ComplexNumber<int>{ 2,-3},
                                    qccomplex::ComplexNumber<int>{-5, 3}};
    qccomplex::CVector<int, 2> b = {qccomplex::ComplexNumber<int>{-2, 3},
                                    qccomplex::ComplexNumber<int>{ 5,-3}};

    auto res = a + b;

    EXPECT_EQ(res[0].re, 0);
    EXPECT_EQ(res[0].im, 0);

    EXPECT_EQ(res[1].re, 0);
    EXPECT_EQ(res[1].im, 0);
}

TEST(ScalarCVectorMult, BasicAssertions)
{
    qccomplex::ComplexNumber<int> c{3, 2};
    qccomplex::CVector<int, 4> a = {qccomplex::ComplexNumber<int>{6, 3},
                                    qccomplex::ComplexNumber<int>{0, 0},
                                    qccomplex::ComplexNumber<int>{5, 1},
                                    qccomplex::ComplexNumber<int>{4, 0}};

    auto res = c * a;

    EXPECT_EQ(res[0].re, 12);
    EXPECT_EQ(res[0].im, 21);

    EXPECT_EQ(res[1].re, 0);
    EXPECT_EQ(res[1].im, 0);

    EXPECT_EQ(res[2].re, 13);
    EXPECT_EQ(res[2].im, 13);

    EXPECT_EQ(res[3].re, 12);
    EXPECT_EQ(res[3].im, 8);
}

TEST(CVectorInverse, BasicAssertions)
{
    qccomplex::CVector<int, 4> a = {qccomplex::ComplexNumber<int>{6, 3},
                                    qccomplex::ComplexNumber<int>{0, 0},
                                    qccomplex::ComplexNumber<int>{5, 1},
                                    qccomplex::ComplexNumber<int>{4, 0}};

    auto res = qccomplex::inverse(a);

    EXPECT_EQ(res[0].re, -a[0].re);
    EXPECT_EQ(res[0].im, -a[0].im);

    EXPECT_EQ(res[1].re, -a[1].re);
    EXPECT_EQ(res[1].im, -a[1].im);

    EXPECT_EQ(res[2].re, -a[2].re);
    EXPECT_EQ(res[2].im, -a[2].im);

    EXPECT_EQ(res[3].re, -a[3].re);
    EXPECT_EQ(res[3].im, -a[3].im);
}

TEST(CMatrixAddition, BasicAssertions)
{
    // An extra brack is needed for the initialization of an aggregate type
    qccomplex::CMatrix<int, 2, 2> a =
    {
        {{qccomplex::ComplexNumber<int>{0, 1}, qccomplex::ComplexNumber<int>{2, 3}},
         {qccomplex::ComplexNumber<int>{4, 5}, qccomplex::ComplexNumber<int>{6, 7}}}
    };

    qccomplex::CMatrix<int, 2, 2> b =
    {
        {{qccomplex::ComplexNumber<int>{ 0, -1}, qccomplex::ComplexNumber<int>{-2, -3}},
         {qccomplex::ComplexNumber<int>{-4, -5}, qccomplex::ComplexNumber<int>{-6, -7}}}
    };

    auto res = a + b;

    EXPECT_EQ(res[0][0].re, 0);
    EXPECT_EQ(res[0][0].im, 0);

    EXPECT_EQ(res[0][1].re, 0);
    EXPECT_EQ(res[0][1].im, 0);

    EXPECT_EQ(res[1][0].re, 0);
    EXPECT_EQ(res[1][0].im, 0);

    EXPECT_EQ(res[1][1].re, 0);
    EXPECT_EQ(res[1][1].im, 0);
}

TEST(CMatrixScaling, BasicAssertions)
{
    qccomplex::ComplexNumber<int> c = { 2, -5 };

    // An extra brack is needed for the initialization of an aggregate type
    qccomplex::CMatrix<int, 2, 2> a =
    {
        {{qccomplex::ComplexNumber<int>{0, 1}, qccomplex::ComplexNumber<int>{-2, 3}},
         {qccomplex::ComplexNumber<int>{4, -5}, qccomplex::ComplexNumber<int>{6, -7}}}
    };

    auto res = c * a;

    auto res00 = c * a[0][0];
    auto res01 = c * a[0][1];
    auto res10 = c * a[1][0];
    auto res11 = c * a[1][1];

    EXPECT_EQ(res[0][0].re, res00.re);
    EXPECT_EQ(res[0][0].im, res00.im);

    EXPECT_EQ(res[0][1].re, res01.re);
    EXPECT_EQ(res[0][1].im, res01.im);

    EXPECT_EQ(res[1][0].re, res10.re);
    EXPECT_EQ(res[1][0].im, res10.im);

    EXPECT_EQ(res[1][1].re, res11.re);
    EXPECT_EQ(res[1][1].im, res11.im);
}

TEST(CMatrixInverse, BasicAssertions)
{
    // An extra brack is needed for the initialization of an aggregate type
    qccomplex::CMatrix<int, 2, 2> a =
    {
        {{qccomplex::ComplexNumber<int>{0, 1}, qccomplex::ComplexNumber<int>{-2, 3}},
         {qccomplex::ComplexNumber<int>{4, -5}, qccomplex::ComplexNumber<int>{6, -7}}}
    };

    auto res00 = qccomplex::ComplexNumber<int>{-1, 0} * a[0][0];
    auto res01 = qccomplex::ComplexNumber<int>{-1, 0} * a[0][1];
    auto res10 = qccomplex::ComplexNumber<int>{-1, 0} * a[1][0];
    auto res11 = qccomplex::ComplexNumber<int>{-1, 0} * a[1][1];

    auto res = qccomplex::inverse(a);

    EXPECT_EQ(res[0][0].re, res00.re);
    EXPECT_EQ(res[0][0].im, res00.im);

    EXPECT_EQ(res[0][1].re, res01.re);
    EXPECT_EQ(res[0][1].im, res01.im);

    EXPECT_EQ(res[1][0].re, res10.re);
    EXPECT_EQ(res[1][0].im, res10.im);

    EXPECT_EQ(res[1][1].re, res11.re);
    EXPECT_EQ(res[1][1].im, res11.im);
}
