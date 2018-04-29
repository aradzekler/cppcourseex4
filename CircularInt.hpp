#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class CircularInt
{
private:
  int smallestNumber;
  int largestNumber;
  int range;

public:
  int current;
  int Current(int value);

  CircularInt(int smallest, int largest); //ready1
  CircularInt(const CircularInt &other); //ready1
  CircularInt &operator=(const int &value);
  CircularInt &operator+=(int const &value);
  CircularInt &operator+=(CircularInt const &value);
  CircularInt &operator++();
  CircularInt operator++(int);
  CircularInt &operator+(int const &value);
  CircularInt &operator+(CircularInt const &value);
  CircularInt &operator-=(int const &value);
  CircularInt &operator-=(CircularInt const &value);
  CircularInt &operator--();
  CircularInt operator--(int);
  CircularInt &operator-();
  CircularInt &operator-(int const &value);
  CircularInt &operator-(CircularInt const &value);
  CircularInt &operator*(int const &value);
  CircularInt &operator*(CircularInt const &value);
  CircularInt &operator*=(int const &value);
  CircularInt &operator*=(CircularInt const &value);
  CircularInt &operator/(int const &value);
  CircularInt &operator/(CircularInt const &value);
  CircularInt &operator/=(int const &value);
  CircularInt &operator/=(CircularInt const &value);
  CircularInt &operator%(int const &value);
  CircularInt &operator%(CircularInt const &value);
  CircularInt &operator%=(int const &value);
  CircularInt &operator%=(CircularInt const &value);

  bool operator==(CircularInt const &c);
  bool operator!=(CircularInt const &c);
  bool operator==(int const &c);
  bool operator!=(int const &c);
  bool operator>(CircularInt const &c);
  bool operator<(CircularInt const &c);
  bool operator>(int const &c);
  bool operator<(int const &c);
  bool operator>=(CircularInt const &c);
  bool operator<=(CircularInt const &c);
  bool operator>=(int const &c);
  bool operator<=(int const &c);

  friend bool operator==(int value, const CircularInt obj);
  friend bool operator!=(int value, const CircularInt obj);
  friend bool operator>(int value, const CircularInt obj);
  friend bool operator<(int value, const CircularInt obj);
  friend bool operator>=(int value, const CircularInt obj);
  friend bool operator<=(int value, const CircularInt obj);

  friend CircularInt operator-(int value, const CircularInt obj);
  friend CircularInt operator+(int value, const CircularInt obj);
  friend CircularInt operator/(int value, const CircularInt obj);
  friend ostream &operator<<(ostream &output, const CircularInt &o);
  friend istream &operator>>(istream &input, CircularInt &o);
  friend ostream &operator<<(ostream &os, const CircularInt &dt);
  friend istream &operator>>(istream &is, const CircularInt &dt);
  ~CircularInt();
};
