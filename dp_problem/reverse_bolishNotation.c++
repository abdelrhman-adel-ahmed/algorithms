#include <iostream>
#include<queue>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


template<class T, size_t S>
class Stack
{

public:


	void push(const T& val)
	{
		arr[cont] = val;
		cont++;
	}
	void pop()
	{
		if (cont) { cont--; }
		//else { __debugbreak(); }
	}

	const bool full()const
	{
		return cont == S;
	}
	const bool empty()const
	{
		if (cont == 0) { return true; }
		else return false;
	}
	const T& top()const
	{
		if (!empty()) { return arr[cont - 1]; }
		//else { __debugbreak(); }
	}

	const int count()const
	{
		return cont;
	}

	void change(int pos, T val)
	{
		arr[pos] = val;
	}

	const T& peek(int pos)const
	{
		return arr[pos];
	}

	const void display()const
	{
		for (int i = cont - 1; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}


private:
	int cont = 0;
	T arr[S];

};

int order(char s)
{
	
	int priorty=0; 
	map<char, int>m;
	m = {
		{'^',4},
		{'*',3},
		{'/',3},
		{'+',2},
		{'-',2}
	};
	map<char, int>::iterator it;
	it = m.find(s);
	//cout << it->second<<endl;
	priorty = it->second;
	return priorty;
}

int main()
{
	int test;
	cin >> test;
	while (test)
	{
		Stack <char, 1000>s;
		string expr;
		cin >> expr;
		expr.length();
		string res;
		//enum m { bracket=1, mult=3, division=3, add=4, sub=4, expon=2 };
		int len = expr.length();
		bool flag = false;

		//a+b*(c-d)	
		for (int i = 0; i < len; i++)
		{
			if (isalpha(expr[i]))
			{
				res += expr[i];
			}
			else if (s.empty())
			{
				s.push(expr[i]);
			}
			else if (!(s.empty()))
			{
				char temp;
				temp = s.top();
				if (expr[i] == '(')
				{
					s.push(expr[i]);
					flag = true;
				}
				else if (flag)
				{
					s.push(expr[i]);
					flag = false;
				}

				else if (expr[i] == ')')
				{
					while (s.top() != '(')
					{
						res += s.top();
						s.pop();
					}
					s.pop();
				}
				else if (order(expr[i]) > order(temp))
				{
					s.push(expr[i]);
				}
				// a*c^d/r
				else if (order(expr[i]) < order(temp))
				{
					res += s.top();
					s.pop();
					temp = s.top();
					bool flag2 = true;
					while (flag2)
					{
						if (order(expr[i]) > order(temp) || s.empty())
						{
							s.push(expr[i]);
							flag2 = false;
						}
						else
						{
							res += s.top();
							s.pop();
						}
					}

				}

			}

		}
		while (!(s.empty()))
		{
			res += s.top();
			s.pop();
		}
		cout << res<<endl;
		test--;
	}
	
	return 0;	
}
