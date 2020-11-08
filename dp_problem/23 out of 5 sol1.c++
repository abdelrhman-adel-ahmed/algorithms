    #include <time.h>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <queue>
    #include <algorithm>

    using namespace std;

int our = 23;
int number[5];
bool vis[20];
bool found=0;
void wla(int pos, int res,int first)
{
    if (found)
        return;
    if (pos == 5)   
    {
        if (our == res)
            found = 1;
    }
    else
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (vis[i])continue;
            vis[i] = 1;
            if (first)
            {
                wla(pos + 1, res + number[i],1);
                wla(pos + 1, res - number[i], 1);
                wla(pos + 1, res * number[i], 1);
            }
            else { wla(pos + 1, number[i], 1); }
            vis[i] = 0;
        }
    }
}

int main() {
    while (true) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            cin >> number[i];
            cnt += number[i];
        }
       // for (int i = 0; i < 5; i++)
       // {
       //     vis[i] = 1;
        
            wla(0, 0,0);
       //     vis[i] = 0;
       // }
        if (!cnt)break;
        if (!found)puts("Impossible");
        else puts("Possible");
        found = false;

    }
}
