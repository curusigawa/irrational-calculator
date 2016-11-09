#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
#include <cmath>

enum FRACTION_ERRS {NOT_FRAC, NOT_DEC, NOT_INT};

using namespace std;

class fraction
{
    public:
        fraction(); //Constructor: What to do when the object is created
        fraction(int n, int d = 1); //Two argument constructor
        ~fraction();//Destructor: What to do when the object "dies"
        fraction(const fraction &other); // Copy constructor
        fraction(const double &other); // Copy constructor

        fraction& operator=(const fraction& other);
        fraction& operator=(const int& other); //Overloaded assignment for int to fraction
        fraction& operator=(const double& other); //Overloaded assignment for a double to a fraction

        //Arithmetic assignment operators
        fraction& operator-=(const int &other);
        fraction& operator+=(const int &other);
        fraction& operator*=(const int &other);
        fraction& operator/=(const int &other);

        fraction& operator-=(const double &other);
        fraction& operator+=(const double &other);
        fraction& operator*=(const double &other);
        fraction& operator/=(const double &other);

        fraction& operator-=(const fraction& other);
        fraction& operator+=(const fraction& other);
        fraction& operator*=(const fraction& other);
        fraction& operator/=(const fraction& other);

        int& getNum();
        int& getDenom();
        int getNum() const;
        int getDenom() const;

        typedef void(fraction::*fptr)(string);
        fptr convert[3];

        //Input and output
        friend
        ostream& operator<<(ostream& out, const fraction &f);

        friend
        istream& operator>>(istream& in, fraction &f);

        //Fraction with fraction arithmetic.
        friend
        fraction operator+(const fraction &x, const fraction &y);

        friend
        fraction operator-(const fraction &x, const fraction &y);

        friend
        fraction operator*(const fraction &x, const fraction &y);

        friend
        fraction operator/(const fraction &x, const fraction &y);

        friend
        fraction operator^(const fraction &x, const fraction &y);

        //Fractions and doubles arithmetic
        friend
        fraction operator+(const fraction &x, const double &y);

        friend
        fraction operator-(const fraction &x, const double &y);

        friend
        fraction operator*(const fraction &x, const double &y);

        friend
        fraction operator/(const fraction &x, const double &y);

        friend
        fraction operator^(const fraction &x, const double &y);

        //Doubles and Fractions arithmetic
        friend
        fraction operator+(const double &x, const fraction &y);

        friend
        fraction operator-(const double &x, const fraction &y);

        friend
        fraction operator*(const double &x, const fraction &y);

        friend
        fraction operator/(const double &x, const fraction &y);

        friend
        fraction operator^(const double &x, const fraction &y);

        //Fractions and integers arithmetic
        friend
        fraction operator+(const fraction &x, const int &y);

        friend
        fraction operator-(const fraction &x, const int &y);

        friend
        fraction operator*(const fraction &x, const int &y);

        friend
        fraction operator/(const fraction &x, const int &y);

        friend
        fraction operator^(const fraction &x, const int &y);

        //Integers and Fractions arithmetic
        friend
        fraction operator+(const int &x, const fraction &y);

        friend
        fraction operator-(const int &x, const fraction &y);

        friend
        fraction operator*(const int &x, const fraction &y);

        friend
        fraction operator/(const int &x, const fraction &y);

        friend
        fraction operator^(const int &x, const fraction &y);

        //Comparison operators -- fraction to fraction
        friend
        bool operator==(const fraction &x, const fraction &y);

        friend
        bool operator!=(const fraction &x, const fraction &y);

        friend
        bool operator>=(const fraction &x, const fraction &y);

        friend
        bool operator<=(const fraction &x, const fraction &y);

        friend
        bool operator<(const fraction &x, const fraction &y);

        friend
        bool operator>(const fraction &x, const fraction &y);


        //Comparison operators -- fraction to double
        friend
        bool operator==(const fraction &x, const double &y);

        friend
        bool operator!=(const fraction &x, const double &y);

        friend
        bool operator>=(const fraction &x, const double &y);

        friend
        bool operator<=(const fraction &x, const double &y);

        friend
        bool operator<(const fraction &x, const double &y);

        friend
        bool operator>(const fraction &x, const double &y);

        //Comparison operators -- double to fraction
        friend
        bool operator==(const double &x, const fraction &y);

        friend
        bool operator!=(const double &x, const fraction &y);

        friend
        bool operator>=(const double &x, const fraction &y);

        friend
        bool operator<=(const double &x, const fraction &y);

        friend
        bool operator<(const double &x, const fraction &y);

        friend
        bool operator>(const double &x, const fraction &y);


        //Comparison operators -- fraction to integer
        friend
        bool operator==(const fraction &x, const int &y);

        friend
        bool operator!=(const fraction &x, const int &y);

        friend
        bool operator>=(const fraction &x, const int &y);

        friend
        bool operator<=(const fraction &x, const int &y);

        friend
        bool operator<(const fraction &x, const int &y);

        friend
        bool operator>(const fraction &x, const int &y);

        //Comparison operators -- int to fraction
        friend
        bool operator==(const int &x, const fraction &y);

        friend
        bool operator!=(const int &x, const fraction &y);

        friend
        bool operator>=(const int &x, const fraction &y);

        friend
        bool operator<=(const int &x, const fraction &y);

        friend
        bool operator<(const int &x, const fraction &y);

        friend
        bool operator>(const int &x, const fraction &y);

        void processF(size_t pos, string input);

        void checkValid();

    private:
        int num, denom;
        void copy(const fraction& other);
        void reduce();
        int gcd(int p, int q);
        void checkNeg(const double& other);
        void frmFraction(string input);
        void frmDecimal(string input);
        void frmInt(string input);

};

#endif // FRACTION_H
