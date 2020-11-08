//https://www.hackerrank.com/contests/rookierank-4/challenges/server-room-safety/problem

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string rack(int elem, vector<int>pos, vector<int>height)
{
    string res = "NONE";
    bool allfall = true;
    int n = 0;
    /*not left rack fall to the left meaning the right rack will cause the fall
    if the left rack will fall to the right that mean left rack will cause right to fall*/
    for (int i = 0; i < elem-1; i++)
    {
        n = max(n, pos[i] + height[i]);
        /*that mean if the current rack(the sum of its position and height) is less than the
        * next rack that mean it will not hit it if it fall ,other wise the allfal remian true*/
        if (n < pos[i+1]) allfall = false;
    }
    if (allfall) res = "LEFT";
    allfall = true;
    /*we calculate the diffrence between the position and the height to see how far it will 
  * fall to the left ,that mean if the current rack will fall after the preve rack position that
    mean  it will hit it so the diffrence will be smaller than the prev rack position ,if not 
    and the diffrence is greater that mean it will not hit it */
    int m = 1000;
    for (int i = elem - 1; i >= 0; i--)
    {
        m = min(m, pos[i]-height[i]);
        if (m > pos[i-1])allfall = false;
    }
    if (allfall) res = res == "LEFT" ? "BOTH" : "RIGHT";
    return res;
}
int main() {
 int num_racks;
    cin >> num_racks;
    vector<int>positions;
    vector<int>height;
    int pos;
    for (int i = 0; i < num_racks; i++)
    {
        cin >> pos;
        positions.push_back(pos);
        
    }
    int hei ;
    for (int i = 0; i < num_racks; i++)
    {
        cin >> hei;
        height.push_back(hei);

    }
    string res=rack(num_racks,positions,height);
    cout<<res<<endl;
   return 0;

}
