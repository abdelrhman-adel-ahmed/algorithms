//https://vjudge.net/contest/404542#problem/B
using namespace std;
#include<iostream>
#include<vector>
typedef long long ll;
int n;
int A[20];
vector<int> ans;
 
void solve(int pos) {
    if (pos == n) {
        if (ans.size() == 6)
            for (int i = 0; i < 6; i++)
                cout << ans[i] << " \n"[i == 5];
    } else {
 
        ans.push_back(A[pos]);
        solve(pos + 1);
        ans.pop_back();
        solve(pos + 1);
    }
}
 
int main() {
    cin >> n;
    while (1) {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        solve(0);
        if (cin >> n, n)
            cout << endl;
        else break;
    }
 
    return 0;
}
