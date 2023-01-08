#include<iostream>
#include<stack>

using namespace std;

bool isValidPair(char openingBracket, char closingBracket)
{
    if (openingBracket == '(' && closingBracket == ')')
        return true;
    else if (openingBracket == '{' && closingBracket == '}')
        return true;
    else if (openingBracket == '[' && closingBracket == ']')
        return true;

    return false;
}

bool isValidParentheses(string str)
{
    stack<char>bracket;
    int len = str.length();
    for(int i=0;i<len;i++)
    {
        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (!bracket.empty())
            {
                char top = bracket.top();
                if (isValidPair(top, str[i]))
                    bracket.pop();
                else
                    return false;
            }
            else
                return false;
        }
        else
            bracket.push(str[i]);
    }

    return bracket.empty();

}

int main()
{
    string str = "[](){}";
    cout<<"is valid: "<<isValidParentheses(str)<<endl;
    return 0;
}
