#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class CircularInt
{
  private:
    int smallestNumber;
    int largestNumber;

  public:
    int current;

    CircularInt(int smallest, int largest); //ready
    CircularInt &operator++(int);           //ready
    CircularInt &operator--(int);           //ready
    CircularInt &operator+=(int value);     //ready
    CircularInt &operator-=(int value);     //ready
    CircularInt &operator*=(int value);     //ready
    CircularInt &operator/=(int value);     //ready
    CircularInt &operator^=(int value);     //ready
    CircularInt &operator%=(int value);
    CircularInt &operator=(int value); //ready
    CircularInt &operator=(const CircularInt obj);
    CircularInt &operator+(const CircularInt obj); //ready (returning same object)
    CircularInt &operator+();                      //unary plus. ready.
    CircularInt &operator-(const CircularInt obj); //ready (returning same object)
    CircularInt &operator-();                      //unary minus. ready
    CircularInt &operator*(const CircularInt obj); //ready (returning same object)
    CircularInt &operator/(const CircularInt obj); //ready (returning same object)
    CircularInt &operator/(int value); //ready
    CircularInt &operator^(const CircularInt obj); // ready (returning same object)
    CircularInt &operator%(const CircularInt obj);
    bool operator==(const CircularInt obj) const; //ready
    bool operator!=(const CircularInt obj) const; //ready
    operator bool();
    ~CircularInt();
};
int &operator-(int value, const CircularInt obj); // number minus object
ostream &operator<<(ostream &os, const CircularInt &dt);
