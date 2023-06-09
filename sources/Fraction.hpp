#pragma once

#include <iostream>

namespace ariel{
    class Fraction{

        private:
        int demonator;
        int numerator;

        public:
        // initializer constructor
        Fraction(int mone, int mechane);


       Fraction() : demonator(1), numerator(0) {}

        // Constructor for convert float to fraction
        Fraction(float num);

        /* getters and setters to the members */
        int getDenominator() const;
        int getNumerator() const;
        void setDemonator(int) ;
        void setNumerator(int) ;
        void simsum();

        
       
       
        


        
        Fraction operator+ (const Fraction& other) const
        {
                
            int den = this->demonator * other.demonator;
            int num = this->numerator * other.demonator + other.numerator * this->demonator;

            if(this->numerator >0 && other.numerator>0)
                {
                    if (this->numerator * other.demonator + other.numerator * this->demonator <0)
                    {
                        std::__throw_overflow_error("overflow");
                    }
                    
                }
            if (this->numerator <0 && other.numerator<0)
                {
                    if (this->numerator * other.demonator + other.numerator * this->demonator >0)
                    {
                        std::__throw_overflow_error("overflow");
                    }
                }
                
            return Fraction(num, den);
        }


        friend Fraction operator+ (float frac1, const Fraction& frac2)
        {
            return frac2 + Fraction(frac1);
        }

        
        friend Fraction operator+ (const Fraction& frac2, float frac1);
        Fraction operator- (const Fraction& other) const;
        friend Fraction operator- (float frac1, const Fraction& frac2);
        friend Fraction operator- (const Fraction& frac2, float frac1);
        Fraction operator* (const Fraction& other) const;
        friend Fraction operator* (float frac1, const Fraction& frac2);
        friend Fraction operator* (const Fraction& frac2, float frac1);
        Fraction operator/ (const Fraction& other) const;
        friend Fraction operator/ (float frac1, const Fraction& frac2);
        friend Fraction operator/ (const Fraction& frac2, float frac1);
        
        
        
        
        
        bool operator> (const Fraction& other) const;
        friend bool operator> (float frac1, const Fraction& frac2);
        friend bool operator> (const Fraction& frac2, float frac1);
        bool operator< (const Fraction& other) const;
        friend bool operator< (float frac1, const Fraction& frac2);
        friend bool operator< (const Fraction& frac2, float frac1);
        bool operator>= (const Fraction& other) const;
        friend bool operator>= (float frac1, const Fraction& frac2);
        friend bool operator>= (const Fraction& frac2, float frac1);
        bool operator<= (const Fraction& other) const;
        friend bool operator<= (float frac1, const Fraction& frac2);
        friend bool operator<= (const Fraction& frac2, float frac1);
        
        
        
        Fraction& operator++();
        const Fraction operator++(int);
        Fraction& operator--();
        const Fraction operator--(int);
        friend bool operator== (const Fraction& frac1, const Fraction& frac2);

        
           
        
        
        // IO operators
        friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
        friend std::istream& operator>> (std::istream& input, Fraction& frac);
        // end of Fraction class




       

    }; 
}
