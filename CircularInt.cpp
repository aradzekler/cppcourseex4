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

bool CircularInt::operator==(const CircularInt obj) const
{
    return (this->smallestNumber == obj.smallestNumber) && (this->largestNumber == obj.largestNumber) && (this->current == obj.current);
}

bool CircularInt::operator==(int value)
{
    return (this->current == value);
}

bool operator==(const CircularInt obj, int value)
{
    return obj.current == value;
    ;
}

bool CircularInt::operator!=(const CircularInt obj)
{
    return (this->smallestNumber != obj.smallestNumber) || (this->largestNumber != obj.largestNumber) || (this->current != obj.current);
}

bool CircularInt::operator!=(int value)
{
    return this->current != value;
}

bool operator!=(int value, const CircularInt &obj)
{
    return value != obj.current;
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
    this->current = Current(this->current * value);
    return *this;
}

CircularInt &CircularInt::operator*=(const CircularInt obj)
{
    this->current = Current(this->current * obj.current);
    return *this;
}

CircularInt &CircularInt::operator/=(int value)
{
    int result = this->current / value;
    if ((this->current % value) != 0)
    {
        throw string(string("No number in range"));
    }
    this->current = Current(result);
    return *this;
}

CircularInt &CircularInt::operator/=(const CircularInt obj)
{
    int result = this->current / obj.current;
    if ((this->current % obj.current) != 0)
    {
        throw string(string("No number in range"));
    }
    this->current = Current(result);
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
    this->current = Current(this->current % value);
    return *this;
}

CircularInt &CircularInt::operator%=(const CircularInt obj)
{
    this->current = Current(this->current % obj.current);
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
    CircularInt *temp = new CircularInt(*this);
    int res = this->current + obj.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator+(int value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current + value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-(const CircularInt obj)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current - obj.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-()
{
    CircularInt *temp = new CircularInt(*this);
    int result = current * -1;
    temp->current = Current(*temp);
    return *temp;
}

CircularInt &CircularInt::operator-(int value)
{
    CircularInt *result = new CircularInt(*this);
    int res = this->current - value;
    result->current = Current(res);
    return *result;
}

CircularInt operator-(const CircularInt obj, const int value)
{
    CircularInt res(obj);
    int result = value - obj.current;
    res.current = res.Current(result);
    return res;
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
    return this->current <= obj.current;
}

bool CircularInt::operator<=(int value)
{
    return this->current <= value;
}

bool operator<=(const CircularInt obj, int value)
{
    return value <= obj.current;
}

bool CircularInt::operator>=(const CircularInt obj)
{
    return this->current >= obj.current;
}

bool CircularInt::operator>=(int value)
{
    return this->current >= value;
}

bool operator>=(const CircularInt obj, int value)
{
    return value >= obj.current;
}

bool CircularInt::operator<(const CircularInt obj)
{
    return this->current < obj.current;
}

bool CircularInt::operator<(int value)
{
    return this->current < value;
}

bool operator<(int value, const CircularInt &obj)
{
    return value < obj.current;
}

bool CircularInt::operator>(const CircularInt obj)
{
    return this->current > obj.current;
}

bool CircularInt::operator>(int value)
{
    return this->current > value;
}

bool operator>(int value, const CircularInt &obj)
{
    return value > obj.current;
}

CircularInt::~CircularInt()
{
}

int CircularInt::Current(int value)
{
    int current = ((value - this->smallestNumber) % (range) + range) % (range) + this->smallestNumber;
    return current;
}
