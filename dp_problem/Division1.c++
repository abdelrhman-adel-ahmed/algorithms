//https://vjudge.net/contest/404542#problem/A

//two solution 

#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;

string s = "0123456789";
vector <int>arrr[80];
void cal(string x, int left, int right)
{
    if (left == right)
    {
        string den(x.begin(), x.begin() + 5);
        int a = stoi(den);
        string num(x.begin() + 5, x.end());
        int b = stoi(num);
        int z = b / a;
        if ((z * a) == b)
        {

            arrr[z].push_back(a);
        }
    }
    else {
        for (int i = left; i <= right; i++)
        {
            swap(x[left], x[i]);
            cal(x, left + 1, right);
        }
    }
}
int main()
{
    cal(s, 0, s.length() - 1);
    int n;
    cin >> n;
    while (1) {
        if (arrr[n].empty())
            cout << "There are no solutions for " << n << ".\n";
        for (auto v : arrr[n]) {
            string xx = to_string(v);
            string yy = to_string(v * n);
            if (xx.size() < 5)
                xx = '0' + xx;
            if (yy.size() < 5)
                yy = '0' + yy;
            cout << yy << " / " << xx << " = " << n << "\n";
        }
        if (cin >> n && n)
            cout << "\n";
        else
            break;
    }
    return 0;
}
