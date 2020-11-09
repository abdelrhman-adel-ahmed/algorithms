//https://vjudge.net/contest/404542#problem/E

int arr[20];
vector<int> res;
int current ;
int sum = 0;
vector<int>t;
void fun(int n, int weight)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                if (arr[i] < weight && sum <= weight)
                {
                    sum += arr[i];
                    res.push_back(arr[i]);
                    if (sum > current && sum <= weight)
                    {
                        current = sum;
                        t = res;
                    }
                }
            }
        }
        res.clear();
    }
}

fun(n, weight);
