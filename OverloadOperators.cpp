#include <string>
#include <iostream>

class Complex
{
public:
    int a, b;
    void input(std::string s)
    {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+')
        {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            i++;
        }
        int v2 = 0;
        while (i < s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

// problem : https://www.hackerrank.com/challenges/overload-operators/problem
// soultion =================================================================
Complex operator +(Complex& A, Complex& B) {
    A.a += B.a;
    A.b += B.b;

    return A;
}

std::ostream& operator<< (std::ostream& os, Complex& A) {
    os << A.a << "+i" << A.b;
    return os;
}
// ==========================================================================
