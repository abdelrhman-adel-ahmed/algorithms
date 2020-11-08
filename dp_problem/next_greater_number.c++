
//https://vjudge.net/contest/400703#problem/A

/*1-traverse the number from right to left when we see a number(n) that greater than the next number (j) now stop 
  2-then if we can find a number to the right of(n) that less than (n) and grater than (j) we mark this as out number ,we do that tell we reach the end
  3-then swap that number (n) with the (j) and the sort the number from (n) to the end.
  
  e.x 159763
  go form right to left until we right 9->n that greater than the next number 5->(j) mark the position of 9 and 5 now we loop from the 9 next position and seee if we can 
  find smaller number that 9 and grater than 5 ,we first find 7 and then 6 and then 3 doesnot meet our condition so we stop and return position of 6 
  now swap the 6 with 5 , 169753 , then sort the number from the (n)place with is 9 place to the end of our number not we get (156379)
  wich is the next grater number
 */
#include <iostream>
#include <algorithm> 
using namespace std;


int main()
{

	
	int t;
	cin >> t;
	while (t)
	{
		char* x = new char[1000000];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		int i, j;
		for (i = n - 1; i > 0; i--)
		{
			if (x[i] > x[i - 1])
				break;
		}
		if (i == 0)
		{
			cout << -1 << endl;
		}

		int y = x[i - 1], smallest = i;
		for (j = i + 1; j < n; j++)
		{

			if (x[j] > y && x[j] < x[smallest])
			{
				smallest = j;
			}
		}
		swap(x[smallest], x[i - 1]);
		sort(x + i, x + n);
		cout << x<<endl;
		//delete[] x;
		--t;
	}
}
