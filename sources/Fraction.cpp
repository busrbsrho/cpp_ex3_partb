#include "Fraction.hpp"
#include <algorithm>
#include <cmath>
using namespace ariel;
using namespace std;


Fraction::Fraction(int nume, int denom) : numerator(nume), demonator(denom){ //main constructor
    if(denom == 0){
        throw invalid_argument("Fraction can't be divided by zero");
    }
    simsum();
}

float ariel::FractionToFloat(const Fraction& a) {
    return 0.0;
}

Fraction::Fraction(float num) {
        float abc =(int)(num * 1000) % 1000;
        this-> numerator =  abc * 1000;
        this->demonator = 1000;
        simsum();



}

int Fraction::getNumerator() const{
    return this->numerator;
}

int Fraction::getDemonator() const{
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
                denom=this->demonator;
                nume= this->numerator - other.numerator;    
            } 
            else
            {
            denom = this->demonator * other.demonator;
            nume= denom*this->numerator - denom*other.numerator;
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
    return Fraction(nume,demon);

}

Fraction ariel::operator* (float f1, const Fraction& f2){
    return Fraction(f1)*f2;
}

Fraction ariel::operator* (const Fraction& f2, float f1){
    return f2*f1;
}

/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////
Fraction Fraction::operator/ (const Fraction& other) const{
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
    return f2 > Fraction(f1);;

}




/////////////////////////////////////////////////////////

bool Fraction::operator<= (Fraction& other) const{
    return false;
}

bool ariel::operator<= (float f1, const Fraction& f2){
    return false;
}

bool ariel::operator<= (const Fraction& f2, float f1){
    return false;

}

/////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////





Fraction& Fraction::operator++(){
    numerator += demonator;
    return *this;
}

const Fraction Fraction::operator++(int){
    return *this;
}

Fraction& Fraction::operator--(){
    numerator -= demonator;
    return *this;
}

const Fraction Fraction::operator--(int){
    return *this;
}

bool ariel::operator== (const Fraction& f1, const Fraction& f2){
    return false;
}

std::ostream& ariel::operator<< (std::ostream& output, const Fraction& a){
    
    output << a.getNumerator() << "/" << a.getDemonator();
    return output;
}

std::istream& ariel::operator>> (std::istream& input, const Fraction& f){
   
    return input;
}


int gcd(int a , int b){

     if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }


void Fraction::simsum(){

    int great=gcd(this->demonator,this->numerator);
    this->demonator=this->demonator/great;
    this->numerator=this->numerator/great;




}






