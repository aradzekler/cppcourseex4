#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class CircularInt
{
private:
  int smallestNumber;
  int largestNumber;
  int Current(int value);
  int range;

public:
  int current;

  CircularInt(int smallest, int largest); //ready
  CircularInt &operator=(int value);      //ready
  CircularInt &operator=(const CircularInt obj);
  CircularInt &operator+=(int value);             //ready
  CircularInt &operator+=(const CircularInt obj); //ready
  CircularInt &operator++(int);                   //ready
  CircularInt &operator++();
  CircularInt &operator--(int); //ready
  CircularInt &operator--();
  CircularInt &operator+(int value);
  CircularInt &operator+(const CircularInt obj); //ready (returning same object)
  CircularInt &operator+();                      //unary plus. ready.
  CircularInt &operator-=(int value); //ready
  CircularInt &operator-=(const CircularInt obj);

  CircularInt &operator*=(int value); //ready
  CircularInt &operator/=(int value); //ready
  CircularInt &operator^=(int value); //ready
  CircularInt &operator%=(int value);

  CircularInt &operator-(const CircularInt obj); //ready (returning same object)
  CircularInt &operator-();                      //unary minus. ready
  CircularInt &operator-(int value);             // number minus object
  CircularInt &operator*(const CircularInt obj); //ready (returning same object)
  CircularInt &operator*(int value);             //ready (returning same object)
  CircularInt &operator/(const CircularInt obj); //ready (returning same object)
  CircularInt &operator/(int value);             //ready
  CircularInt &operator^(const CircularInt obj); // ready (returning same object)
  CircularInt &operator%(const CircularInt obj);
  bool operator==(const CircularInt obj) const;             //ready
  friend bool operator==(const CircularInt obj, int value); // ready +-
  friend bool operator==(int value, const CircularInt obj); //ready +-
  bool operator!=(const CircularInt obj) const;             //ready
  bool operator<=(const CircularInt obj);
  bool operator>=(const CircularInt obj);
  bool operator>(const CircularInt obj);
  bool operator<(const CircularInt obj);
  operator bool();
  ~CircularInt();
};
ostream &operator<<(ostream &os, const CircularInt &dt);
istream &operator>>(istream &is, const CircularInt &dt);
