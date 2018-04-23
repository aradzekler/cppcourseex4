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

    CircularInt(int smallest,int largest); //ready
    CircularInt& operator++(int); //ready
    CircularInt& operator--(int); //ready
    CircularInt& operator+=(int value); //ready
    CircularInt& operator-=(int value); //ready
    CircularInt& operator*=(int value); 
    CircularInt& operator/=(int value);
    const CircularInt& operator=(int value);
    bool operator==(const CircularInt other)const; 
    bool operator!=(const CircularInt other)const; 
    int& operator*();
    operator bool() ;
    ~CircularInt();

};
 ostream &operator<<(ostream& os, const CircularInt& dt);
