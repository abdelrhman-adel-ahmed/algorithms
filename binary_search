int Bs(int arr[], int val,int size)
{
    int start = 0;
    int  end = size - 1;
    while (start <= end)
    {
        int mid = end / 2;
        if (mid < start) return -1;
        else if (arr[mid] == val)return arr[mid];
        else if (arr[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}
