//https://vjudge.net/contest/404542#problem/E

int arr[20];
vector<int> res,t;
int current ;
int sum = 0;
void fun(int n, int weight)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum+=arr[i];
                res.push_back(arr[i]);
                 if (sum <= weight && current<sum)
                {
                    t = res;
                    current = sum;
                }
            }
        }
        res.clear();
    }
}

fun(n, weight);
