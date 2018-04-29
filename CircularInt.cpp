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
    this->range = abs(this->largestNumber - this->smallestNumber) + 1;
}

ostream &operator<<(ostream &os, const CircularInt &dt)
{
    os << dt.current;
    return os;
}

istream &operator>>(istream &is, CircularInt &dt)
{
    is >> dt.current;
    return is;
}

CircularInt &CircularInt::operator++(int)
{
    int result = this->current++;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator++()
{
    int result = ++this->current;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator--(int)
{
    int result = this->current--;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator--()
{
    int result = --this->current;
    this->current = Current(result);
    return *this;
}

bool CircularInt::operator==(const CircularInt other) const
{
    return this->current == other.current;
}

bool operator==(const CircularInt obj, int value)
{
    if (obj.current == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(int value, const CircularInt obj)
{
    if (obj.current == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CircularInt::operator!=(const CircularInt other) const
{
    return this->current != other.current;
}

CircularInt &CircularInt::operator*(const CircularInt obj)
{
    while ((this->current * obj.current) > this->largestNumber)
    {
        this->current = (this->current * obj.current) % this->largestNumber;
        if (this->current <= this->largestNumber)
        {
            return *this;
        }
    }
    this->current = this->current * obj.current;
    return *this;
}

CircularInt &CircularInt::operator*(int value)
{
    while ((this->current * value) > this->largestNumber)
    {
        this->current = (this->current * value) % this->largestNumber;
        if (this->current <= this->largestNumber)
        {
            return *this;
        }
    }
    this->current = this->current * value;
    return *this;
}

CircularInt &CircularInt::operator/(const CircularInt obj)
{
    for (int i = this->smallestNumber; i <= this->largestNumber; i++)
    {
        if ((i * obj.current) == this->current)
        {
            this->current = i;
        }
    }
    return *this;
}

CircularInt &CircularInt::operator/(int value)
{
    for (int i = this->smallestNumber; i <= this->largestNumber; i++)
    {
        if ((i * value) == this->current)
        {
            this->current = i;
        }
    }
    return *this;
}

CircularInt::operator bool()
{
    return (this->current) != 0;
}

CircularInt &CircularInt::operator+=(int value)
{
    int result = this->current + value;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator+=(const CircularInt obj)
{
    int result = this->current + obj.current;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator-=(int value)
{
    int result = this->current - value;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator-=(const CircularInt obj)
{
    int result = this->current - obj.current;
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator*=(int value)
{
    if (this->current * value <= this->largestNumber)
    {
        this->current = this->current * value;
    }
    while ((this->current * value) > this->largestNumber)
    {
        this->current = (this->current * value) % this->largestNumber;
        if (this->current < this->largestNumber)
        {
            return *this;
        }
    }
    return *this;
}

CircularInt &CircularInt::operator/=(int value)
{
    if ((this->current / value) < this->smallestNumber)
    {
        this->current = this->smallestNumber;
    }
    else
    {
        this->current = this->current / value;
    }
    return *this;
}

CircularInt &CircularInt::operator^=(int value)
{
    while ((this->current ^ value) > this->largestNumber)
    {
        this->current = (this->current ^ value) % this->largestNumber;
        if (this->current < this->largestNumber)
        {
            return *this;
        }
    }
    this->current = this->current ^ value;
    return *this;
}

CircularInt &CircularInt::operator%=(int value)
{
    while ((this->current % value) > this->largestNumber)
    {
        this->current = this->current % value;
        if (this->current <= this->largestNumber)
        {
            return *this;
        }
    }
    this->current = this->current % value;
    return *this;
}

CircularInt &CircularInt::operator=(int value)
{
    this->current = Current(value);
    return *this;
}

CircularInt &CircularInt::operator=(const CircularInt obj)
{
    this->smallestNumber = obj.smallestNumber;
    this->largestNumber = obj.largestNumber;
    this->current = obj.current;
}

CircularInt &CircularInt::operator+(const CircularInt obj)
{
    if ((this->current + obj.current) <= this->largestNumber)
    {
        this->current = this->current + obj.current;
    }
    while ((this->current + obj.current) > this->largestNumber)
    {
        this->current = (this->current + obj.current) % this->largestNumber;
        if (this->current < this->largestNumber)
        {
            return *this;
        }
    }
    return *this;
}

CircularInt &CircularInt::operator+(int value)
{
    if ((this->current + value) <= this->largestNumber)
    {
        this->current = this->current + value;
    }
    while ((this->current + value) > this->largestNumber)
    {
        this->current = (this->current + value) % this->largestNumber;
        if (this->current < this->largestNumber)
        {
            return *this;
        }
    }
    return *this;
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
    while (this->current < this->smallestNumber)
    {
        if (this->current < 0)
        {
            this->current -= this->current * 2;
        }
        else
        {
            this->current %= this->largestNumber;
        }
    }
    return *this;
}

CircularInt &CircularInt::operator-(int value)
{
    if (this->current - value >= this->smallestNumber && this->current - value <= this->largestNumber)
    {
        this->current -= value;
        return *this;
    }

    return *this;
}

// need fixing
CircularInt &CircularInt::operator^(const CircularInt obj)
{
    if ((this->current ^ obj.current) > this->largestNumber)
    {
        this->current ^= obj.current;
        this->current %= this->largestNumber;
    }
    return *this;
}

bool CircularInt::operator<=(const CircularInt obj)
{
    if (this->current > obj.current)
    {
        return false;
    }
    return true;
}

bool CircularInt::operator>=(const CircularInt obj)
{
    if (this->current < obj.current)
    {
        return false;
    }
    return true;
}

bool CircularInt::operator>(const CircularInt obj)
{
    if (this->current < obj.current)
    {
        return false;
    }
    return true;
}

bool CircularInt::operator<(const CircularInt obj)
{
    if (this->current > obj.current)
    {
        return false;
    }
    return true;
}

CircularInt::~CircularInt()
{
}

int CircularInt::Current(int value)
{
    int current = ((value - this->smallestNumber) % (range) + range) % (range) + this->smallestNumber;
    return current;
}
