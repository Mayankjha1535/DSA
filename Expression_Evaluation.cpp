#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool IsOperator(char c)   //helper function to check if a char is an operator
{
	if (c== '+'|| c=='-'|| c=='*'||c=='/')
	{
		return true;
	}
	return false;
}

bool IsDigit(char c)  //helper function to check if a char is a digit 
{
	if(c >= '0' and c <= '9')
	{
		return true;
	}
	return false;
}

int PerformOperation(int operand1, int operand2, char operation) //helper function to perform a particular operation
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

int EvaluatePostfix(string exp)
{
	int len =exp.length();
	int val;
	stack<int> s;
	for(int i=0;i<len;i++) //scan from left to right
	{
		if(IsDigit(exp[i]))
		{
			val=exp[i] - 48; //convert char to int
			s.push(val);
		}
		else if (IsOperator(exp[i]))
		{
			int op2=s.top(); //order of popping is important
			s.pop();
			int op1=s.top();
			s.pop();
			int res=PerformOperation(op1, op2, exp[i]);
			s.push(res);
		}
	}
	return s.top();
}

int EvaluatePrefix(string exp)
{
	int len =exp.length();
	int val;
	stack<int> s;
	for(int i=len;i>=0;i--) //scan from right to left
	{
		if(IsDigit(exp[i]))
		{
			val=exp[i] - 48; //convert char to int
			s.push(val);
		}
		else if (IsOperator(exp[i]))
		{
			int op1=s.top(); //order of popping is important
			s.pop();
			int op2=s.top();
			s.pop();
			int res=PerformOperation(op1, op2, exp[i]);
			s.push(res);
		}
	}
	return s.top();
}

int main()
{
	string exp,exp1;
	cout<<"Enter Postfix expression"<<endl;
	getline(cin,exp);
	int res1=EvaluatePostfix(exp);
	cout<<"Postfix result is "<<res1<<endl;
	cout<<"Enter Prefix expression"<<endl;
	getline(cin,exp1);
	int res2=EvaluatePrefix(exp1);
	cout<<"Prefix result is "<<res2<<endl;		
	return 0;
}
