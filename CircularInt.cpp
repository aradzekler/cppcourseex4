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

CircularInt::CircularInt(const CircularInt &other)
{
    this->largestNumber = other.largestNumber;
    this->smallestNumber = other.smallestNumber;
    this->range = other.range;
    this->current = other.current;
}

CircularInt &CircularInt::operator=(const int &value)
{
    this->current = Current(value);
    return *this;
}

CircularInt &CircularInt::operator+=(const int &value)
{
    int res = this->current + value;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator+=(const CircularInt &obj)
{
    int res = this->current + obj.current;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator-=(const int &value)
{
    int res = this->current - value;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator-=(const CircularInt &obj)
{
    int res = this->current - obj.current;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator++()
{
    int res = ++this->current;
    this->current = Current(res);
    return *this;
}

CircularInt CircularInt::operator++(int)
{
    CircularInt temp(*this);
    ++(*this);
    return temp;
}

CircularInt &CircularInt::operator--()
{
    int res = this->current - 1;
    this->current = Current(res);
    return *this;
}

CircularInt CircularInt::operator--(int)
{
    CircularInt temp(*this);
    --(*this);
    return temp;
}

CircularInt &CircularInt::operator*=(const int &value)
{
    this->current = Current(this->current * value);
    return *this;
}

CircularInt &CircularInt::operator*=(const CircularInt &obj)
{
    this->current = Current(this->current * obj.current);
    return *this;
}

CircularInt &CircularInt::operator/=(const int &value)
{
    if (this->current % value != 0)
    {
        throw string(string("No number in range"));
    }
    int res = this->current / value;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator/=(const CircularInt &obj)
{
    if (this->current % obj.current != 0)
    {
        throw string(string("No number in range"));
    }
    int res = this->current / obj.current;
    this->current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator%=(const int &value)
{
    this->current = Current(this->current % value);
    return *this;
}

CircularInt &CircularInt::operator%=(const CircularInt &obj)
{
    this->current = Current(this->current % obj.current);
    return *this;
}

bool CircularInt::operator==(const CircularInt &obj)
{
    return (this->largestNumber == obj.largestNumber) && (this->smallestNumber == obj.smallestNumber) && (this->current == obj.current);
}

bool CircularInt::operator!=(const CircularInt &obj)
{
    return (this->largestNumber != obj.largestNumber) || (this->smallestNumber != obj.smallestNumber) || (this->current != obj.current);
}

bool CircularInt::operator==(const int &value)
{
    return (this->current) == value;
}

bool CircularInt::operator!=(const int &value)
{
    return (this->current) != value;
}

bool CircularInt::operator>(const CircularInt &obj)
{
    return this->current < obj.current;
}

bool CircularInt::operator<(const CircularInt &obj)
{
    return this->current < obj.current;
}

bool CircularInt::operator>(const int &value)
{
    return this->current > value;
}

bool CircularInt::operator<(const int &value)
{
    return this->current < value;
}

bool CircularInt::operator>=(const CircularInt &obj)
{
    return this->current >= obj.current;
}

bool CircularInt::operator<=(const CircularInt &obj)
{
    return this->current <= obj.current;
}

bool CircularInt::operator>=(const int &value)
{
    return this->current >= value;
}

bool CircularInt::operator<=(const int &value)
{
    return this->current <= value;
}
bool operator==(int value, const CircularInt &obj)
{
    return value == obj.current;
}

bool operator!=(int value, const CircularInt &obj)
{
    return value != obj.current;
}

bool operator>(int value, const CircularInt &obj)
{
    return value > obj.current;
}

bool operator<(int value, const CircularInt &obj)
{
    return value < obj.current;
}

bool operator>=(int value, const CircularInt &obj)
{
    return value >= obj.current;
}

bool operator<=(int value, const CircularInt &obj)
{
    return value <= obj.current;
}

CircularInt operator-(int value, const CircularInt &obj)
{
    CircularInt res(obj);
    int result = value - obj.current;
    res.current = res.Current(result);
    return res;
}

CircularInt operator+(int value, const CircularInt &obj)
{
    CircularInt res(obj);
    int result = obj.current + value;
    res.current = res.Current(result);
    return res;
}

CircularInt operator/(const int &value, const CircularInt &obj)
{
    CircularInt res(obj);
    int result = value / obj.current;
    res.current = res.Current(result);
    return res;
}

CircularInt &CircularInt::operator+(const int &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current + value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator+(const CircularInt &obj)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current + obj.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-()
{
    CircularInt *res = new CircularInt(*this);
    int result = this->current * -1;
    res->current = Current(result);
    return *res;
}

CircularInt &CircularInt::operator-(const int &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current - value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-(const CircularInt &obj)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current - obj.current;
    temp->current = Current(res);
    return *temp;
}
CircularInt &CircularInt::operator*(const int &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current * value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator*(const CircularInt &obj)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current * obj.current;
    temp->current = Current(res);
    return *temp;
}
CircularInt &CircularInt::operator/(const int &value)
{
    CircularInt *temp = new CircularInt(*this);
    if (this->current % value != 0)
    {
        throw string(string("No number in range"));
    }
    int res = this->current / value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator/(const CircularInt &obj)
{
    if (this->current % obj.current != 0)
    {
        throw string(string("No number in range"));
    }
    CircularInt *temp = new CircularInt(*this);
    int res = this->current / obj.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator%(const int &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current % value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator%(const CircularInt &obj)
{
    CircularInt *temp = new CircularInt(*this);
    int res = this->current % obj.current;
    temp->current = Current(res);
    return *temp;
}
ostream &operator<<(ostream &output, const CircularInt &obj)
{
    output << obj.current;
    return output;
}
istream &operator>>(istream &input, CircularInt &obj)
{
    int n;
    input >> n;
    obj.current = obj.Current(n);
    return input;
}

CircularInt::~CircularInt()
{
}

int CircularInt::Current(int value)
{
    int current = ((value - this->smallestNumber) % (range) + range) % (range) + this->smallestNumber;
    return current;
}
