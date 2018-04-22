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

    CircularInt(int start_input,int end_input);
    CircularInt& operator++();
    CircularInt& operator++(int);
    CircularInt& operator--(int);
    CircularInt& operator--();
    CircularInt& operator+=(int value); 
    CircularInt& operator-=(int value);
    CircularInt& operator*=(int value); 
    CircularInt& operator/=(int value);
    CircularInt& operator=(int value);
    bool operator==(const CircularInt obj);
    bool operator!=(const CircularInt other);
    operator bool();
    CircularInt& operator/(int);
    CircularInt& operator-();
        
        ~CircularInt();


};
 ostream &operator<<(ostream& os, const CircularInt& dt);
