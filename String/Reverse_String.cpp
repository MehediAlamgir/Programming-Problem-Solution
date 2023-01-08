#include<iostream>
using namespace std;

string reverseString(string str)
{
    int len = str.length();
    for(int i=0;i<len/2;i++)
    {
        swap(str[i], str[len-i-1]);
    }

    return str;
}

int main()
{
    string str = "abcde";
    cout<<"Reversed of "<<str<<" is: "<<reverseString(str)<<endl;

    return 0;
}
