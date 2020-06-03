#include<iostream>
#include<stack>
using namespace std;
stack<char> S;

bool IsParentheses(string exp)
{
	int n= exp.length();
	for(int i=0;i<n;i++)
	{
		if(exp[i]=='[' or exp[i] == '(' or exp[i]=='{')
		{
			S.push(exp[i]);
		}
		if(!S.empty())
		{
			if(exp[i]==']')
			{
				if(S.top()=='[')
				{
					S.pop();
					continue;
				}
				else
				{
					break;
				}
				
			}
			
			if(exp[i]==')')
			{
				if(S.top()=='(')
				{
					S.pop();
					continue;
				}
				else
				{
					break;
				}
				
			}
			if(exp[i]=='}')
			{
				if(S.top()=='{')
				{
					S.pop();
					continue;
				}
				else
				{
					break;
				}
				
			}
		}
	}
	return S.empty();
}

int main()
{
	string str1 = "(()";
	string str2 = "[()(]";
	if(IsParentheses(str1))
	{
		cout<<"Balanced expression" <<endl;
	}
	else
	{
		cout<<"Not balanced "<<endl;
	}
	return 0;
}
