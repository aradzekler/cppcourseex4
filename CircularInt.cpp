#include <iostream>
#include <stdlib.h>
#include <string>
#include "CircularInt.hpp"

using namespace std;

CircularInt::CircularInt(int smallest, int largest)
{
    this->smallestNumber = smallest;
    this->largestNumber = largest;
    this->current = smallest;
}

ostream &operator<<(ostream &os, const CircularInt &dt)
{
    os << dt.current;
    return os;
}

// this works
CircularInt &CircularInt::operator++(int)
{
    if (this->current % this->largestNumber == 0)
    {
        this->current = this->smallestNumber;
    }
    else
    {
        this->current = this->current + 1;
    }
    return *this;
}

CircularInt &CircularInt::operator--(int)
{
    if (this->current == this->smallestNumber)
    {
        this->current = this->largestNumber;
    }
    else
    {
        this->current = this->current - 1;
    }
    return *this;
}

bool CircularInt::operator==(const CircularInt other) const
{
    return this->current == other.current;
}

bool CircularInt::operator!=(const CircularInt other) const
{
    return this->current != other.current;
}

CircularInt &CircularInt::operator*(const CircularInt obj)
{
    if ((this->current * obj.current) > this->largestNumber)
    {
        this->current = (this->current * obj.current) % this->largestNumber;
    }
    else
    {
        this->current = this->current * obj.current;
    }
    return *this;
}

CircularInt &CircularInt::operator/(const CircularInt obj)
{
}

CircularInt::operator bool()
{
    return (this->current) != 0;
}

CircularInt &CircularInt::operator+=(int value)
{
    if ((this->current + value) > this->largestNumber)
    {
        this->current = (this->current + value) % this->largestNumber;
    }
    else
    {
        this->current = this->current + value;
    }
    return *this;
}

CircularInt &CircularInt::operator-=(int value)
{
    if ((this->current - value) < this->smallestNumber)
    {
        this->current = (this->current - value) % this->smallestNumber;
    }
    else
    {
        this->current = this->current - value;
    }
    if (this->current < this->smallestNumber) // check if number is viable.
    {
        this->current = this->smallestNumber;
    }
    return *this;
}

CircularInt &CircularInt::operator*=(int value)
{
    if (this->current * value > this->largestNumber)
    {
        this->current = (this->current * value) % this->largestNumber;
    }
    else
    {
        this->current *= value;
    }
    return *this;
}

CircularInt &CircularInt::operator/=(int value)
{
    if ((this->current / value) < smallestNumber)
    {
        this->current = smallestNumber;
    }
    else
    {
        this->current = this->current / value;
    }
    return *this;
}

CircularInt &CircularInt::operator=(int value)
{
    if (value >= this->smallestNumber && value <= this->largestNumber)
    {
        this->current = value;
    }
    else if (value > this->largestNumber)
    {
        this->current = this->current % value;
    }
    else
    {
        this->current = this->smallestNumber; // need fixing
    }
    return *this;
}

CircularInt &CircularInt::operator+(const CircularInt obj)
{
    if ((this->current + obj.current) > this->largestNumber)
    {
        this->current = (this->current - obj.current) % this->smallestNumber;
    }
    else
    {
        this->current = this->current + obj.current;
    }
    return *this; // returning this object. another possible way is to create a new object with new current.
}

CircularInt &CircularInt::operator+()
{
    this->current += this->largestNumber;
    this->current %= this->largestNumber;
    return *this;
}

CircularInt &CircularInt::operator-(const CircularInt obj)
{
    if ((this->current - obj.current) < this->smallestNumber)
    {
        this->current = (this->current + obj.current) % this->largestNumber;
    }
    else
    {
        this->current = this->current - obj.current;
    }
    if (this->current < this->smallestNumber) // check if number is viable.
    {
        this->current = this->smallestNumber;
    }
    return *this;
}

CircularInt &CircularInt::operator-()
{
    this->current -= this->largestNumber;
    this->current -= this->current * 2;
    return *this;
}

CircularInt::~CircularInt()
{
}
