#include<iostream>
#include<unordered_map>
#include <vector>

using namespace std;

// find longest palindrome in a given string

string longestPalindrome(string str)
{
    int len = str.length();
    string longestPalindrome = "";

    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            string subStr = str.substr(i,j-i+1);

            bool isPalindrome = true;
            int subStrLen = subStr.length();
            for(int k=0;k<subStrLen/2;k++) //substring palindrome check
            {
                if (subStr[k] != subStr[subStrLen-k-1])
                {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome && subStrLen > longestPalindrome.size())
            {
                longestPalindrome = subStr;
            }
        }
    }

    return longestPalindrome;
}

//Find the first non repeated character of a given String?
char firstNonRepeatedChar(string str) {
    unordered_map<char, int> freqMap;
    int n = str.length();

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freqMap[str[i]]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < n; i++) {
        if (freqMap[str[i]] == 1) {
            return str[i];
        }
    }

    // No non-repeated characters found
    return '\0';
}


//Find all pairs in an array of integers whose sum is equal to the given number. TWO SUM Problem
vector<pair<int, int>> findPairsWithSum(int arr[], int n, int target) {
    vector<pair<int, int>> result;
    unordered_map<int, int> counts;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (counts.find(complement) != counts.end()) {
            result.push_back({complement, arr[i]});
        }
        counts[arr[i]]++;
        //counts[arr[i]] = i;
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 1, 0, 5};
    int target = 6;

    vector<pair<int, int>> pairs = findPairsWithSum(arr1, 5, target);

    for (auto p : pairs) {
        cout << p.first << " + " << p.second << " = " << target << endl;
    }

    return 0;
}
