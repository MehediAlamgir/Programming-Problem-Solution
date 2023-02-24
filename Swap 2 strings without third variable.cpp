#include<iostream>

using namespace std;

void swap_strings(string &str1, string &str2)
{
    str1 = str1+';'+str2;
    int pos = str1.find(';');

    str2 = str1.substr(0, pos); // substr(0, n) means substring of n numbers of character form position 0
    str1 = str1.substr(pos+1); // substr(n) means starts form n positions till string length
}

int main()
{
    string str1 = "hello";
    string str2 = "world";

    cout<<"Before  swap: " <<str1<<" "<<str2<<endl;
    swap_strings(str1, str2);
    cout<<"After  swap: " <<str1<<" "<<str2<<endl;


    return 0;
}
