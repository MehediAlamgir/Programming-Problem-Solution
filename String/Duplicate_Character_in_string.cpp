#include<iostream>
#include<unordered_map>

using namespace std;

void findDuplicate(string str)
{
    unordered_map<char,int>char_count;
    int len = str.length();

    for(int i=0;i<len;i++)
        char_count[str[i]]++;

    for(auto it: char_count)
    {
        if (it.second > 1)
            cout<<it.first<<": "<<it.second<<endl;
    }
}

int main()
{
    findDuplicate("ababcdcaf");

    return 0;
}
