/*
Check if string is palindrome or not
*/

#include<iostream>
using namespace std;

bool isPalindrome(string str)
{
    int len = str.length();
    for(int i=0;i<len/2;i++)
    {
        if (str[i] != str[len-i-1])
            return false;
    }

    return true;
}

int main()
{
    cout<<isPalindrome("abcba")<<endl;
    cout<<isPalindrome("abcdef")<<endl;

    return 0;

}
