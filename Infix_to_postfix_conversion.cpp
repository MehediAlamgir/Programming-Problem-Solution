/*
Ref:
https://iq.opengenus.org/infix-to-postfix-expression-stack/
https://quescol.com/data-structure/infix-to-postfix
https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
*/

#include<iostream>
#include<stack>

using namespace std;

int operatorPrecedence(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '^')
		return 3;

	return -1;
}

void infixToPostfix(string infixExpression)
{
	string postfixExpression;
	stack<char>operatorStack;

	int sz = infixExpression.size();
	
	for (int i = 0; i < sz; i++)
	{
		char ch = infixExpression[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			postfixExpression += ch;
		else if (ch == '(')
			operatorStack.push(ch);
		else if (ch == ')')
		{
			while (operatorStack.top() != '(')
			{
				postfixExpression += operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.pop();
		}
		else
		{
			//ch is operator

			while (!operatorStack.empty() && operatorPrecedence(operatorStack.top()) >= operatorPrecedence(ch))
			{
				postfixExpression += operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.push(ch);

		}

	}

	while (!operatorStack.empty())
	{
		postfixExpression += operatorStack.top();
		operatorStack.pop();
	}

	cout << "Postfix: " << postfixExpression << endl;
}

bool isNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}

int calculate(char ch, int n1, int n2)
{
	int res = 0;
	if (ch == '+')
		res = n2 + n1;
	else if (ch == '-')
		res = n2 - n1;
	else if (ch == '*')
		res = n2 * n1;
	else if (ch == '/')
		res = n2 / n1;

	return res;
}

void calculatePostfixExpression(string postfixNotation)
{
	/*
		Note: 
		This postfix calculate function will work for single digit operands only. Ex: 231*+9-

		For multiple digit operands it will not work. Ex: 100 200 + 2 / 5 * 7 +
		Its needs to modify a bit for expression of  multiple digits by adding a separator-like space between all elements (operators and operands)
	 
	*/
	stack<int> st;
	int sz = postfixNotation.size();
	for (int i = 0; i < sz; i++)
	{
		char ch = postfixNotation[i];
		if (isNumber(ch))
		{
			st.push(ch-'0');
		}
		else
		{
			int n1 = st.top();
			st.pop();
			int n2 = st.top();
			st.pop();

			st.push(calculate(ch, n1, n2));
		}
	}

	cout << "postfix evaluation: " << st.top() << endl;
}

int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);

	string exp1 = "231*+9-";
	calculatePostfixExpression(exp1);
	

	return 0;
}