#include <iostream>
#include <string>
#include "CircularInt.hpp"

using namespace std;

    CircularInt::CircularInt(int smallest, int largest) {
        this->smallestNumber = smallest;
        this->largestNumber = largest;
        this->current = smallest;
    }

    ostream& operator<<(ostream& os, const CircularInt& dt) {  
        os << dt.current;  
        return os;  
}  
    CircularInt& CircularInt::operator++() {       
        return *this;
    }


CircularInt& CircularInt::operator++(int value) { 
        return *this;
    }

   CircularInt& CircularInt::operator--(int) {
        return *this;
    }

    bool CircularInt::operator==(const CircularInt other) const {
    return this->current ==other.current;
    
    }

    bool CircularInt::operator!=(const CircularInt other) const {   
        return this->current !=other.current;
    }

    int& CircularInt::operator*() { 
    return this->current;
    }

   CircularInt::operator bool() {
    return (this->current)!=0;
    }

    CircularInt& CircularInt::operator+=(int value) {
    this->current += value;
    return *this;
    }

   CircularInt& CircularInt::operator-=(int value) {
    this->current -= value;
    return *this;
    }

   CircularInt& CircularInt::operator*=(int value) {
    this->current *= value;
    return *this;
    }

 CircularInt& CircularInt::operator/=(int value) {
    this->current /= value;       cout<<"";
    return *this;
    }
    const CircularInt& CircularInt::operator= (int value) {
        return *this;
    }


    CircularInt::~CircularInt() {

} 
