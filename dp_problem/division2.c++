//https://vjudge.net/contest/404542#problem/A
//solution 2


bool tkn[80];
string res;
vector <int>arrr[80];
void call(int pos)
{
    if (pos == 10)
    {
        string den(res.begin(), res.begin() + 5);
        int a = stoi(den);
        string num(res.begin() + 5, res.end());
        int b = stoi(num);
        int z = b / a;
        if ((z * a) == b)
        {
            arrr[z].push_back(a);
        }
    }
    else {
      
        for (int i = 0; i < s.length(); i++)
        {
            if (tkn[i])continue;
            tkn[i] = 1; //to not go over a number twice in same loop to avoid such things (000000000 000000001 0000000002)
            res += s[i];
            call(pos + 1);
            res.pop_back();
            tkn[i] = 0;
        }
    }
}
 int n;
    call(0);
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
            cout << xx << " / " << yy << " = " << n << "\n";
        }
        if (cin >> n && n)
            cout << "\n";
        else
            break;
    }
