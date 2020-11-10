vector <long long>rr;
//generate all the combination numbers that have 4,7 and store them in the vector
long long xx=10000000000;
void f(long long  num)
{
    if (num > xx)
        return;
    if (num)
        rr.push_back(num);
    f(num * 10 + 4);
    f(num * 10 + 7);
        

}
int main() 
{  
    f(0);
    int x = 74747;
    //sort them
    sort(rr.begin(), rr.end());
    for (int i = 0; i < rr.size(); i++)
    {
        if (rr[i] == x)
        {
            cout << i + 1;
            break;
        }
    }
