#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
#include <climits>
using namespace ariel;
using namespace std;

int gcd(int a , int b){

     if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }



Fraction::Fraction(int nume, int denom) : numerator(nume), demonator(denom){ //main constructor
    if(denom == 0){
        throw invalid_argument("Fraction can't be divided by zero");
    }
    int common =abs(gcd(numerator,demonator));
     if ((numerator < 0 && demonator < 0) || (numerator > 0 && demonator < 0))
    {
        
        this->numerator = -numerator / common;
        this->demonator = -demonator / common;
    }
    else
    {
        this->demonator =demonator/common;
        this->numerator =numerator/common;
    }
    
    
}



Fraction::Fraction(float num) {
    int sign=1;
    int abc = num * 1000;
    int commoner = gcd(abc, 1000);
    if(num < 0 )
    {
        sign =-1;

    }
  
  
    this->numerator = abc/ commoner * sign;
    this->demonator = 1000 /commoner * sign;

    
    


}



int Fraction::getNumerator() const{
    return this->numerator;
}

int Fraction::getDenominator() const{
    return this->demonator;
}

void Fraction::setNumerator(int nume) {
    this->numerator = nume;
}

void Fraction::setDemonator(int denom) {
    this->demonator =denom;
}

/////////////////////////////////////////////////////////////////////////////
// Fraction Fraction::operator+ (Fraction& other) const{
//     int denom = this->demonator * other.demonator;
//     int nume= denom*this->numerator + denom*other.numerator;
//     return Fraction(nume,denom);
// }

// Fraction ariel::operator+ (float f1, const Fraction& f2){
//    return Fraction(f1) + f2; 
// }

Fraction ariel::operator+ (const Fraction& f2, float f1){
    return f1+f2;
}

////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
Fraction Fraction::operator- (const Fraction& other) const{
    int denom;
    int nume;
       if(this->demonator==other.demonator)
            {
                if (this->numerator>0 && other.numerator <0 && this->numerator - other.numerator <0)
                {
                   __throw_overflow_error("over flow ");
                    
                }
                else if (this->numerator<0 && other.numerator >0 && this->numerator - other.numerator >0)
                {
                   __throw_overflow_error("over flow ");
                    
                }
                
                
                denom=this->demonator;
                nume= this->numerator - other.numerator;    
            } 
            else
            { 
            denom = this->demonator * other.demonator;
            nume= other.demonator*this->numerator - this->demonator*other.numerator;
            }



            
        return Fraction(nume,denom);

        

}

Fraction ariel::operator- (float f1, const Fraction& f2){
    return Fraction(f1)-f2;
}

Fraction ariel::operator- (const Fraction& f2, float f1){

    return f2-Fraction(f1);
}

/////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////

Fraction Fraction::operator* (const Fraction& other) const{
     
    int demon=this->demonator * other.demonator;
    int nume=this->numerator * other.numerator;
    if (other.numerator!=0 && demon/other.demonator==this->demonator && nume/other.numerator==this->numerator)
    {
         return Fraction(nume,demon);
    }
    else if (other.numerator == 0 || this->numerator ==0 )
    {
         return Fraction(nume,demon);
    }
    
    else
        __throw_overflow_error("overflow");
    
    
   

}

Fraction ariel::operator* (float f1, const Fraction& f2){
    return Fraction(f1)*f2;
}

Fraction ariel::operator* (const Fraction& f2, float f1){
    return f1* f2;
}

/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////
Fraction Fraction::operator/ (const Fraction& other) const{
        if(other.numerator==0)
        {
            __throw_runtime_error("cant divide by 0 ");
        }
        else

            return *this * Fraction(other.demonator,other.numerator);
}


Fraction ariel::operator/ (float f1, const Fraction& f2){
    return Fraction(f1)/f2;
}


Fraction ariel::operator/ (const Fraction& f2, float f1){
    return f2/Fraction(f1);
}
//////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////
bool Fraction::operator> (const Fraction& other) const{
    return this->numerator*other.demonator > other.numerator * this->demonator;
}

bool ariel::operator> (float f1, const Fraction& f2){
    return Fraction(f1) > f2;
}

bool ariel::operator> (const Fraction& f2, float f1){
    return f2 > Fraction(f1);
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
bool Fraction::operator< (const Fraction& other) const{
    return this->numerator*other.demonator < other.numerator * this->demonator;
}

bool ariel::operator< (float f1, const Fraction& f2){
    return Fraction(f1) < f2;
}

bool ariel::operator< (const Fraction& f2, float f1){
     return f2 < Fraction(f1);
}
//////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
bool Fraction::operator>= (const Fraction& other) const{
    return this->numerator*other.demonator >= other.numerator * this->demonator;

}

bool ariel::operator>= (float f1, const Fraction& f2){
     return Fraction(f1) >= f2;
}


bool ariel::operator>= (const Fraction& f2, float f1){
    return f2 >= Fraction(f1);

}




/////////////////////////////////////////////////////////

bool Fraction::operator<= (const Fraction& other) const{
    if( this->numerator*other.demonator <= other.numerator * this->demonator)
        return true;
    else
        return false;    
        
}

bool ariel::operator<= (float f1, const Fraction& f2){
   return Fraction(f1) <= f2;
}


bool ariel::operator<= (const Fraction& f2, float f1){
    return f2 <= Fraction(f1);

}

/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////





Fraction& Fraction::operator++(){
    numerator += demonator;
    return *this;
}

const Fraction Fraction::operator++(int){
    Fraction temp(*this);
    numerator += demonator;
    return temp;

}

Fraction& Fraction::operator--(){
    numerator -= demonator;
    return *this;
}

const Fraction Fraction::operator--(int){ 
    Fraction temp(*this);
    numerator -= demonator;
    return temp;
}

bool ariel::operator== (const Fraction& f1, const Fraction& f2){
  if (f1.numerator==0 && f2.numerator==0)
  {
    return true;
  }
    
    return f1.demonator==f2.demonator && f1.numerator==f2.numerator;
}

std::ostream& ariel::operator<< (std::ostream& output, const Fraction& a){
    
    output << a.getNumerator() << "/" << a.getDenominator();
    return output;
}


istream& ariel::operator>>(istream& input, Fraction& f)
{
    int numerator = 0;
    int denominator = 1;
    char delimiter = '/';

    input >> numerator;

    // Check for delimiter character
    if (input.peek() == '/')
    {
        input.ignore();
    }
    else if (input.peek() == ',' || input.peek() == ' ')
    {
        delimiter = input.get();
    }
    else
    {
        throw runtime_error("Invalid delimiter");
    }

    input >> denominator;
    if (denominator == 0)
    {
        __throw_runtime_error("cant divide by 0 ");
    }
    

    // Create fraction object
    Fraction temp(numerator, denominator);
    f.numerator = temp.getNumerator();
    f.demonator = temp.getDenominator();

    return input;
}








void Fraction::simsum(){

    int great=gcd(this->demonator,this->numerator);
    this->demonator=this->demonator/great;
    this->numerator=this->numerator/great;




}






