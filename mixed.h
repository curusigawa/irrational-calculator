#ifndef MIXED_H
#define MIXED_H
#include "fraction.h"

class mixed : public fraction
{
    public:
        mixed(int w = 0, int n = 0, int d = 1);
        ~mixed();
        mixed(const mixed &other);
        mixed& operator=(const mixed &other);
        mixed& operator=(const double &other);
        mixed& operator=(const int &other);
        mixed& operator=(const fraction &other);

        friend
        istream& operator>>(istream &in, mixed &number);

        friend
        ostream& operator<<(ostream &out, mixed number);

        friend
        mixed operator+=(const mixed &x, const mixed &y);

        friend
        mixed operator-=(const mixed &x, const mixed &y);

        friend
        mixed operator*=(const mixed &x, const mixed &y);

        friend
        mixed operator/=(const mixed &x, const mixed &y);

        friend
        mixed operator^=(const mixed &x, const mixed &y);

     private:
        void checkNeg(fraction f, fraction& g);
        void checkDiv(string s);
        void clearWS(istream &in);
        void outputSpace(ostream &out, int whole, fraction f);
        void outputWhole(ostream &out, int whole);
        void outputFraction(ostream &out, fraction f);
        void outputZero(ostream &out, fraction f);
        bool negative;
};

#endif // MIXED_H
