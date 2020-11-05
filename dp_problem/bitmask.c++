int arr[] = { 1 ,2, 3 ,4, 5, 6 ,7 };
int main()
{
    int size=sizeof(arr)/sizeof(arr[0]);
    int num_of_combinations = 1 << size; // 1*2^size
    for (int mask = 0; mask < num_of_combinations; mask++) // get all possible subsets including empty set
    {
        cout << "{";
        for (int pos = 0; pos < size; pos++)
        {
            if ((mask & 1<< pos) !=0) // bitwise and to check if the current item be taken or not
            {
                cout << arr[pos]<<" ";
            }
        }
        cout << "}";
        cout << endl;
    }
}
