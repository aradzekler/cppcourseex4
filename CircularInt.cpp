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

    CircularInt& operator/(const CircularInt& left, int num) {
        if (left.current <= num) {

        }
    }

    CircularInt& operator/(int num, const CircularInt& right) {
    return (right / num); // call the first one
}

    CircularInt& CircularInt::operator++() {       
       // if (this->current % this->largestNumber == 0) {
         //   this->current = this->smallestNumber; 
        //}
        //else {
        //    this->current = this->current + 1;
        //}
        return *this;
    }

    CircularInt& CircularInt::operator++(int) {       
       // if (this->current % this->largestNumber == 0) {
         //   this->current = this->smallestNumber; 
       // }
        //else {
          //  this->current = this->current + 1;
        //}
        return *this;
    }

   CircularInt& CircularInt::operator--() {
       // if (this->current % this->smallestNumber == 0) {
         //   this->current = this->largestNumber;
        //}
       // else {
         //   this->current = this->current - 1;
       // }
        return *this;
    }

   CircularInt& CircularInt::operator--(int) {
        //if (this->current % this->smallestNumber == 0) {
         //   this->current = this->largestNumber;
       // }
        //else {
         //   this->current = this->current - 1;
       // }
        return *this;
    }


    CircularInt& CircularInt::operator+=(int value) {
    this->current += value;
    return *this;
}

   CircularInt& CircularInt::operator-=(int value) {
    this->current -= value;
    return *this;
}

   CircularInt& CircularInt::operator*=(int value)  {
    this->current *= value;
    return *this;
}

 CircularInt& CircularInt::operator/=(int value)  {
    this->current /= value;
    return *this;

}

    CircularInt& CircularInt::operator=(int value) {
        return *this;
    } 

    bool CircularInt::operator==(const CircularInt& obj) {
        if (this->current == obj.current) {
            return true;
        }
        else {
            return false;
        }
    }

    CircularInt::~CircularInt()
    {
       cout<<"";
    }
