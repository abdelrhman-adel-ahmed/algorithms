#include <iostream>
#include <string>
#include <stack>
using namespace std;


// utility function to find value of and operand 
int value(char c) { return (c - '0'); }

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2)
{
	if (operation == '+')      return operand1 + operand2;
	else if (operation == '-') return operand1 - operand2;
	else if (operation == '*') return operand1 * operand2;
	
	else if (operation == '/') return operand1 / operand2;

	else cout << "Unexpected Error \n";
	return -1;
}
int evaluate(string exp)
{
	int len = exp.length();
	stack <int>s;
	for (int i = 0; i < len; i++)
	{
		if (isdigit(exp[i]))
		{
			int operand=exp[i]-'0';
			s.push(operand);
		}
		else	
		{
			char oper = exp[i];
			int temp1 = s.top(); s.pop();
			int temp2 = s.top(); s.pop();
			int result = PerformOperation(oper, temp2, temp1);
			s.push(result);

		}
	}
	return s.top();

}
int main()
{
	string exp = "23*54*+9-";
	int result=evaluate(exp);
	cout << result;
}
