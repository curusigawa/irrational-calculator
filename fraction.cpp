#include "fraction.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>

fraction::fraction()
{
    num = 0;
    denom = 1;
    convert[0]=&fraction::frmFraction;
    convert[1]=&fraction::frmDecimal;
    convert[2]=&fraction::frmInt;
}

fraction::fraction(int n, int d)
{
    num = n;
    denom = d;
    reduce();
}

fraction::~fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(const fraction &other)
{
    if (!other.denom)
        throw NOT_FRAC;
    copy(other);

}

fraction::fraction(const double &other)
{
    *this = other;
}

fraction& fraction::operator=(const fraction& other)
{
   if(this != &other)
       copy(other);
   return *this;
}

fraction& fraction::operator=(const int& other)
{
    num = other;
    denom = 1;
    return *this;
}

void fraction::checkNeg(const double& other)
{
    if (other<0)
        num = -num;
}

fraction& fraction::operator=(const double& other)
{
    stringstream ss;
    char junk;
    int temp, whole = 0;
    ss<<other;
    ss>>whole>>junk>>temp;
    if (temp == 0)
        denom = 1;
    else
        denom = pow(10.0,int(log10(temp)+1));
    num = abs(whole*denom)+temp;
    checkNeg(other);
    reduce();
    return *this;
}

//Arithmetic assignment operators
fraction& fraction::operator-=(const fraction &other)
{
    num = num*other.denom - denom*other.num;
    denom = other.denom*denom;
    reduce();
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    num = (num*other.denom) + (denom*other.num);
    denom = other.denom*denom;
    reduce();
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    num *= other.num;
    denom *= other.denom;
    reduce();
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    num = num*other.denom ;
    denom *= other.num;
    reduce();
    return *this;
}

fraction& fraction::operator-=(const double &other)
{
    *this -= fraction(other);
    return *this;
}

fraction& fraction::operator+=(const double &other)
{
    *this += fraction(other);
    return *this;
}

fraction& fraction::operator*=(const double &other)
{
    *this *= fraction(other);
    return *this;
}

fraction& fraction::operator/=(const double &other)
{
    *this /= fraction(other);
    return *this;
}

fraction& fraction::operator-=(const int& other)
{
    *this -= fraction(other);
    return *this;
}

fraction& fraction::operator+=(const int& other)
{
    *this += fraction(other);
    return *this;
}

fraction& fraction::operator*=(const int& other)
{
    *this *= fraction(other);
    return *this;
}

fraction& fraction::operator/=(const int& other)
{
    *this /= fraction(other);
    return *this;
}


void fraction::copy(const fraction &other)
{
    num = other.num;
    denom = other.denom;
}

int& fraction::getNum()
{
    return num;
}

int& fraction::fraction::getDenom()
{
    return denom;
}

int fraction::getNum() const
{
    return num;
}

int fraction::fraction::getDenom() const
{
    return denom;
}

void fraction::reduce()
{
    int div;
    div = gcd(num, denom);
    num /= div;
    denom /= div;
    if (denom < 0)
    {
        denom = abs(denom);
        num = -num;
    }
}

int fraction::gcd(int p, int q)
{
    return !q?p:gcd(q,p%q);
}

void fraction::frmFraction(string input)
{
    int n,d; char junk; string r;
    stringstream ss;
    ss<<input;
    ss>>n;
    if (ss.eof())
        throw NOT_FRAC;
    ss>>junk>>d>>r ;
    (junk != '/') ? throw NOT_FRAC : 0;
    (r!="") ? throw NOT_FRAC : 0;
    num=n;
    denom=d;
}

void fraction::frmDecimal(string input)
{
    double n; string r;
    stringstream ss;
    ss<<input;
    ss>>n>>r;
    if(r!="")
        throw NOT_DEC;
    *this = n;
}

void fraction::frmInt(string input)
{
    int n; string r;
    stringstream ss;
    ss<<input;
    ss>>n>>r;
    if(r!="")
        throw NOT_INT;
    *this = n;
}

void fraction::checkValid()
{
    if (num < 0)
        throw NOT_FRAC;
}

//Here comes the friends!

ostream& operator<<(ostream& out, const fraction &f)
{
    if (f.denom == 1)
        out<<f.num;
    else
        out<<f.num<<"/"<<f.denom;
    return out;
}

istream& operator>>(istream& in, fraction &f)
{
    string input, numtype = "/.";
    in>>input;
    int pos=numtype.find(input[input.find_first_of("/.")]);
    f.processF(pos,input);
    return in;
}

void fraction::processF(size_t pos, string input)
{
    if (pos == string::npos)
        pos=2;
    (this->*convert[pos])(input);
    reduce();
}

/*
 *
 *
 *
 *
 *
 *
 *
 */
//Fraction with fraction arithmetic.

fraction operator+(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom + x.denom * y.num;
    z.denom = x.denom * y.denom;
    z.reduce();
    return z;
}

fraction operator-(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom - x.denom * y.num;
    z.denom = x.denom * y.denom;
    z.reduce();
    return z;
}

fraction operator*(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.num;
    z.denom = x.denom * y.denom;
    z.reduce();
    return z;
}

fraction operator/(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom;
    z.denom = x.denom * y.num;
    z.reduce();
    return z;
}

fraction operator^(const fraction &x, const fraction &y)
{
    fraction z;
    z.denom = 1;
    string line;
    double a, b;
    if ((x.num < 0 || x.denom < 0) && y.denom%2 == 0)
        throw NOT_FRAC;
    a=pow(x.num,(double)y.num/y.denom);
    b=pow(x.denom,(double)y.num/y.denom);
    double ans = a/b;
    cout<<a<<" "<<b<<endl;
    double dec = ans-(int)ans;
    stringstream ss;
    ss << dec;
    ss >> line;
    for (unsigned int i=0; i<line.length()-1; i++)
        z.denom*=10;
    z.num = ans*z.denom;
    z.reduce();
    return z;
}


//Fractions and doubles arithmetic

fraction operator+(const fraction &x, const double &y)
{
    fraction z;
    z = x + fraction(y);
    z.reduce();
    return z;
}

fraction operator-(const fraction &x, const double &y)
{
    fraction z;
    z = x - fraction(y);
    z.reduce();
    return z;
}

fraction operator*(const fraction &x, const double &y)
{
    fraction z;
    z = x * fraction(y);
    z.reduce();
    return z;
}

fraction operator/(const fraction &x, const double &y)
{
    fraction z;
    z = x / fraction(y);
    z.reduce();
    return z;
}

fraction operator^(const fraction &x, const double &y)
{
    fraction z;
    z = x ^ fraction(y);
    z.reduce();
    return z;
}

//Doubles and Fractions arithmetic

fraction operator+(const double &x, const fraction &y)
{
    fraction z;
    z = fraction(x) + y;
    z.reduce();
    return z;
}

fraction operator-(const double &x, const fraction &y)
{
    fraction z;
    z = fraction(x) - y;
    z.reduce();
    return z;
}

fraction operator*(const double &x, const fraction &y)
{
    fraction z;
    z = fraction(x) * y;
    z.reduce();
    return z;
}

fraction operator/(const double &x, const fraction &y)
{
    fraction z;
    z = fraction(x) / y;
    z.reduce();
    return z;
}

fraction operator^(const double &x, const fraction &y)
{
    fraction z;
    z = fraction(x) ^ y;
    z.reduce();
    return z;
}


//Fractions and integers arithmetic

fraction operator+(const fraction &x, const int &y)
{
    fraction z;
    z = x + fraction(y);
    z.reduce();
    return z;
}

fraction operator-(const fraction &x, const int &y)
{
    fraction z;
    z = x - fraction(y);
    z.reduce();
    return z;
}

fraction operator*(const fraction &x, const int &y)
{
    fraction z;
    z = x * fraction(y);
    z.reduce();
    return z;
}

fraction operator/(const fraction &x, const int &y)
{
    fraction z;
    z = x / fraction(y);
    z.reduce();
    return z;
}

fraction operator^(const fraction &x, const int &y)
{
    fraction z;
    z = x ^ fraction(y);
    return z;
}


//Integers and Fractions arithmetic

fraction operator+(const int &x, const fraction &y)
{
    fraction z;
    z = fraction(x) + y;
    z.reduce();
    return z;
}

fraction operator-(const int &x, const fraction &y)
{
    fraction z;
    z = fraction(x) - y;
    z.reduce();
    return z;
}


fraction operator*(const int &x, const fraction &y)
{
    fraction z;
    z = fraction(x) * y;
    z.reduce();
    return z;
}

fraction operator/(const int &x, const fraction &y)
{
    fraction z;
    z = fraction(x) / y;
    z.reduce();
    return z;
}

fraction operator^(const int &x, const fraction &y)
{
    fraction z;
    z = fraction(x) ^ y;
    z.reduce();
    return z;
}


//Comparison operators -- fraction to fraction

bool operator==(const fraction &x, const fraction &y)
{
   return x.num * y.denom == x.denom * y.num;
}

bool operator!=(const fraction &x, const fraction &y)
{
    return !(x == y);
}

bool operator>=(const fraction &x, const fraction &y)
{
    return x == y || x > y;
}

bool operator<=(const fraction &x, const fraction &y)
{
    return x == y || x < y;
}

bool operator<(const fraction &x, const fraction &y)
{
   return x.num * y.denom < x.denom * y.num;
}

bool operator>(const fraction &x, const fraction &y)
{
   return x.num * y.denom > x.denom * y.num;
}


//Comparison operators -- fraction to double

bool operator==(const fraction &x, const double &y)
{
    return x == fraction(y);
}

bool operator!=(const fraction &x, const double &y)
{
    return !(x == fraction(y));
}

bool operator>=(const fraction &x, const double &y)
{
    return x >= fraction(y);
}

bool operator<=(const fraction &x, const double &y)
{
    return x <= fraction(y);
}

bool operator<(const fraction &x, const double &y)
{
    return x < fraction(y);
}

bool operator>(const fraction &x, const double &y)
{
    return x > fraction(y);
}

//Comparison operators -- double to fraction

bool operator==(const double &x, const fraction &y)
{
    return fraction(x) == y;
}

bool operator!=(const double &x, const fraction &y)
{
    return !(fraction(x) == y);
}

bool operator>=(const double &x, const fraction &y)
{
    return fraction(x) >= y;
}

bool operator<=(const double &x, const fraction &y)
{
    return fraction(x) <= y;
}

bool operator<(const double &x, const fraction &y)
{
    return fraction(x) < y;
}

bool operator>(const double &x, const fraction &y)
{
    return fraction(x) > y;
}


//Comparison operators -- fraction to integer

bool operator==(const fraction &x, const int &y)
{
    return x == fraction(y);
}

bool operator!=(const fraction &x, const int &y)
{
    return !(x == fraction(y));
}

bool operator>=(const fraction &x, const int &y)
{
    return x >= fraction(y);
}

bool operator<=(const fraction &x, const int &y)
{
    return x <= fraction(y);
}

bool operator<(const fraction &x, const int &y)
{
    return x < fraction(y);
}

bool operator>(const fraction &x, const int &y)
{
    return x > fraction(y);
}


//Comparison operators -- int to fraction

bool operator==(const int &x, const fraction &y)
{
    return fraction(x) == y;
}

bool operator!=(const int &x, const fraction &y)
{
    return !(fraction(x) == y);
}

bool operator>=(const int &x, const fraction &y)
{
    return fraction(x) >= y;
}

bool operator<=(const int &x, const fraction &y)
{
    return fraction(x) <= y;
}

bool operator<(const int &x, const fraction &y)
{
    return fraction(x) < y;
}

bool operator>(const int &x, const fraction &y)
{
    return fraction(x) > y;
}
