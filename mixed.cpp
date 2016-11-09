#include "mixed.h"

mixed::mixed(int w, int n, int d)
{
    this->getNum() = n+(w*d);
    this->getDenom() = d;
    negative = false;
}

mixed::~mixed()
{
    this->getNum() = 0;
    this->getDenom() = 0;
}

mixed::mixed(const mixed &other):fraction(other)
{
    if(this != &other)
        *this = other;
}

mixed& mixed::operator=(const mixed &other)
{
    this->getNum()=other.getNum();
    this->getDenom()=other.getDenom();
    return *this;
}

mixed& mixed::operator=(const double &other)
{
    *this = fraction(other);
    return *this;
}

mixed& mixed::operator=(const int &other)
{
    this->getNum() = other;
    this->getDenom() = 1;
    return *this;
}

mixed& mixed::operator=(const fraction &other)
{
    this->getNum()=other.getNum();
    this->getDenom()=other.getDenom();
    return *this;
}

void checkDiv(string s)
{
    if (!s.find("/"))
        throw NOT_FRAC;
}

void outputZero(ostream &out, fraction f)
{
    if (f.getNum() == 0 && f.getDenom() == 1)
        out<<0;
}

void checkNeg(fraction f, fraction& g)
{
    if (f<0)
        g = g*-1;
}

void clearWS(istream &in)
{
    char junk;
    if(in.peek()==32)
        in.get(junk);
    cout<<"space was cleared"<<endl;
}

void outputWhole(ostream &out, int whole)
{
    if (whole != 0)
        out<<whole;
}

void outputSpace(ostream &out, int whole, fraction f)
{
    if (whole != 0 &&(abs(whole) - f.getNum()) != 0)
        out<<" ";
}

void outputFraction(ostream &out, fraction f)
{
    if (f != 0)
        out<<f;
}

istream& operator>>(istream &in, mixed &number)
{
    number = 0;
    cout<<"peek="<<char(in.peek())<<endl;
    fraction fx1, fx2;
    if (in.peek() == '-')
        number.negative = true;
    in>>fx1;
    clearWS(in);
    //in.peek() == '-' ? throw NOT_FRAC : 0;
    if (number.getDenom()==1 && in.peek()>47 && in.peek()<58)
    {
        string input;
        in>>input;
        fx2.processF(0, input);
        fx2.checkValid(); //checks if there is a negative in the second fraction such as 1 1/-2
    }
    cout<<"fx1="<<fx1<<"fx2="<<fx2<<endl;
    checkNeg(fx1,fx2);
    number=fx1+fx2;
    if (number.getNum() > 0 && number.negative)
        number.getNum() = -number.getNum();
    cout<<"mixed number="<<number<<endl;
    return in;
}

ostream& operator<<(ostream &out, mixed number)
{
    if (number<0)
    {
        out<<"-";
        number=number*-1;
    }
    int whole = number.getNum()/number.getDenom();
    outputWhole(out, whole);
    outputSpace(out, whole, number);
    outputFraction(out,number-whole);
    outputZero(out, number);
    return out;
}

mixed operator+=(const mixed &x, const mixed &y)
{
    mixed z;
    z=x+y;
    return z;
}

mixed operator-=(const mixed &x, const mixed &y)
{
    mixed z;
    z=x-y;
    return z;
}

mixed operator*=(const mixed &x, const mixed &y)
{
    mixed z;
    z=x*y;
    return z;
}

mixed operator/=(const mixed &x, const mixed &y)
{
    mixed z;
    z=x/y;
    return z;
}

mixed operator^=(const mixed &x, const mixed &y)
{
    mixed z;
    z=x^y;
    return z;
}
