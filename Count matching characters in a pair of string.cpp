/*
    Count the number of matching characters in a pair of strings
    Considers only one occurrence of each character even if it exists multiple times
*/

#include<iostream>
#include<string>
#include<unordered_set>
#include <unordered_map>

using namespace std;

int count_matching_characters(string str1, string str2)
{
    int count=0;
    unordered_set<char>charMatchSet;
    int len = str1.length();

    for(int i=0; i<len; i++)
    {
        if (str2.find(str1[i]) != string::npos && charMatchSet.find(str1[i]) == charMatchSet.end())
        {
            count++;
            charMatchSet.insert(str1[i]);
        }
    }

    return count;
}


string find_non_matching_chars(string str1, string str2) {
    unordered_map<char, int> char_counts;
    for (char c : str1) {
        char_counts[c]++;
    }
    for (char c : str2) {
        char_counts[c]++;
    }
    string result;
    for (const auto& pair : char_counts) {
        if (pair.second == 1) {
            result += pair.first;
        }
    }
    return result;
}

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    cout << count_matching_characters(str1, str2) << endl; // Output: 2

    return 0;
}
