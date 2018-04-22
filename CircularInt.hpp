#include <iostream>
#include <string>

using namespace std;

class CircularInt
{
    private:
    int smallestNumber;
    int largestNumber;


    public:
    int current;

    CircularInt(int smallest, int largest);
    CircularInt& operator/(int);
    CircularInt& operator++();
    CircularInt& operator-();
    CircularInt& operator-(int);
    CircularInt& operator+(const CircularInt& obj);
    CircularInt& operator++(int);
    CircularInt& operator--();
    CircularInt& operator--(int);
    CircularInt& operator+=(const int value); 
    CircularInt& operator-=(int value);
    CircularInt& operator*=(int value); 
    CircularInt& operator/=(int value);
    CircularInt& operator=(int value);
    bool operator==(const CircularInt& obj);
    ~CircularInt();

};
 ostream &operator<<(ostream& os, const CircularInt& dt);
