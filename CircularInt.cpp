#include <iostream>
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

int &CircularInt::operator*()
{

    return this->current;
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
    this->current *= value;
    return *this;
}

CircularInt &CircularInt::operator/=(int value)
{
    this->current /= value;
    cout << "";
    return *this;
}
const CircularInt &CircularInt::operator=(int value)
{
    return *this;
}

CircularInt::~CircularInt()
{
}
