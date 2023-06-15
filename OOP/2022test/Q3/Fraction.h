#pragma once
#include <iostream>

using std::ostream;
using std::cout;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

class Fraction
{
    private:
        long long numerator;
        long long denominator;
    public:
        Fraction(long long x,long long y = 1) : numerator(x), denominator(y) {}
        ~Fraction() = default;
        Fraction& operator * (const Fraction& x){
            long long numtmp = numerator * x.numerator;
            long long denotmp = denominator * x.denominator;
            long long _numerator = numtmp / gcd(numtmp,denotmp);
            long long _denominator = denotmp / gcd(numtmp,denotmp);
            auto a = new Fraction(_numerator,_denominator);
            return *a;
        }
        Fraction& operator / (const Fraction& x){
            long long numtmp = numerator * x.denominator;
            long long denotmp = denominator * x.numerator;
            long long _numerator = numtmp / gcd(numtmp,denotmp);
            long long _denominator = denotmp / gcd(numtmp,denotmp);
            auto a = new Fraction(_numerator,_denominator);
            return *a;
        }
        Fraction& operator + (const Fraction& x){
            long long numtmp = numerator * x.denominator + x.numerator * denominator;
            long long denotmp = denominator * x.denominator;
            long long _numerator = numtmp / gcd(numtmp,denotmp);
            long long _denominator = denotmp / gcd(numtmp,denotmp);
            auto a = new Fraction(_numerator,_denominator);
            return *a;
        }
        Fraction& operator - (const Fraction& x){
            long long numtmp = numerator * x.denominator - x.numerator * denominator;
            long long denotmp = denominator * x.denominator;
            long long _numerator = numtmp / gcd(numtmp,denotmp);
            long long _denominator = denotmp / gcd(numtmp,denotmp);
            auto a = new Fraction(_numerator,_denominator);
            return *a;
        }
        friend ostream& operator <<(ostream& cout,const Fraction& x);
};

ostream& operator <<(ostream& out,const Fraction& x)
{
    if(x.denominator != 1)
    {
        int count;
        long long numtmp,denotmp;
        if(x.denominator < 0)
        {
            count++;
            denotmp = -x.denominator;
        }
        else denotmp = x.denominator;
        if(x.numerator < 0)
        {
            count++;
            numtmp = -x.numerator;
        }
        else numtmp = x.numerator;
        if(count % 2) out << numtmp << '/' << denotmp;
        else out << '-' << numtmp << '/' << denotmp;
    }
    else out << x.numerator;
    return out;
}