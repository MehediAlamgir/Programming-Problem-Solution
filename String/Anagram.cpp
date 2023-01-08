/*
Check if two string is  anagram
*/

#include<iostream>
#include<unordered_map>

using namespace std;

bool isAnagram(string first_string, string second_string)
{
    int first_string_len = first_string.length();
    int second_string_len = second_string.length();

    if (first_string_len != second_string_len)
        return false;

    unordered_map<char, int>first_string_count;

    for(int i=0;i<first_string_len;i++)
        first_string_count[first_string[i]]++;

    for(int i=0;i<second_string_len;i++)
    {
        if (first_string_count.find(second_string[i]) != first_string_count.end())
             first_string_count[second_string[i]]--;
        else
            return false;
    }

    for(auto it : first_string_count)
    {
        if (it.second != 0)
            return false;
    }

    return true;
}

int main()
{
    cout<<"is aabcd and dacab anagram: "<<isAnagram("aabcd", "dacab")<<endl;
    cout<<"is abcd and xcab anagram: "<<isAnagram("abcd", "xcab")<<endl;
    cout<<"is abcd and cab anagram: "<<isAnagram("abcd", "cab")<<endl;

    return 0;
}
