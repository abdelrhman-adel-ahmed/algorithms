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
  //go from right to left 
	for (int i =len-1; i >= 0; i--)
	{
		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if (exp[i] == ' ' || exp[i] == ',') continue;

		else if (isdigit(exp[i]))
		{
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
			int operand = 0;
			while (i < exp.length() && isdigit(exp[i])) {
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = (operand * 10) + (exp[i] - '0');
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;

			// Push operand on stack. 
			//cout << operand << endl;
			s.push(operand);
		}
		else
		{
			char oper = exp[i];
			//cout << oper << endl;
			int temp1 = s.top(); s.pop();
			int temp2 = s.top(); s.pop();
			int result = PerformOperation(oper, temp2, temp1);
			cout << result << endl;
			s.push(result);

		}
	}
	return s.top();

}
int main()
{
	string exp = "-+*2,3*,5,4,9";
	int result = evaluate(exp);
	cout << result;
}
