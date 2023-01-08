/*
Check if string is Panagram or not.

Panagrams are words or sentences containing every letter of the alphabet at least once
*/

#include<iostream>
#include<vector>

using namespace std;

bool isPanagram(string sentence)
{
    int len = sentence.length();
    if (len<26)
        return false;

    vector<bool>flag(26, false);
    for(int i=0; i<len; i++)
    {
        if (sentence[i]>='a' && sentence[i]<='z')
            flag[sentence[i]-'a'] = true;
        else if (sentence[i]>='A' && sentence[i]<='Z')
            flag[sentence[i]-'A'] = true;
    }

    for(auto ch : flag)
    {
        if (ch == false)
            return false;
    }

    return true;
}

int main()
{
    cout<<"is panagram: "<<isPanagram("abcdefghijklmnopqrstuvwxyz")<<endl;
    cout<<"is panagram: "<<isPanagram("abcdefghijklmnopqrstuvwxy")<<endl;

    return 0;
}
