#include<iostream>
using namespace std;

int reverseNumber(int num)
{
    int rev=0, reminder;
    while(num>0)
    {
        reminder = num%10;
        rev = rev*10 + reminder;

        num = num/10;
    }

    return rev;
}

int main()
{
    int num = 123;
    cout<<"Reversed of "<<num<<" is: "<<reverseNumber(num)<<endl;

    return 0;
}
