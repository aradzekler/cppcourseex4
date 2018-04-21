#include <iostream>

using namespace std;

class CircularInt
{
    private:
    int smallestNumber;
    int largestNumber;
    int current;

    public:
    CircularInt(int smallest, int largest);
    CircularInt& operator++();
    CircularInt& operator++(int value);
    CircularInt& operator--();
    CircularInt& operator--(int value);
    CircularInt& operator+=(int value); 
    CircularInt& operator-=(int value);
    CircularInt& operator*=(int value); 
    CircularInt& operator/=(int value);
    CircularInt& operator=(int value);
        
    ~CircularInt();

};
 
