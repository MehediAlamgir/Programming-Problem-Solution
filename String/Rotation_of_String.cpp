/*
Check if one string is rotation of another string
*/

#include<iostream>

using namespace std;

bool checkRotation(string mainString, string rotatedString)
{
    if (mainString.length() != rotatedString.length())
        return false;

    string concatedStr = mainString + mainString;

    if (concatedStr.find(rotatedString) != string::npos)
        return true;

    return false;
}

int main()
{
    // abcdabcd
    cout<<"isRotated: "<<checkRotation("abcd","cdab")<<endl; //true
    cout<<"isRotated: "<<checkRotation("abcd","dabc")<<endl; //true
    cout<<"isRotated: "<<checkRotation("abcd","bcab")<<endl; //false

    return 0;
}
