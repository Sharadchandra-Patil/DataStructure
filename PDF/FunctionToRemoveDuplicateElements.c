int rmDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;

    int len = 0, i;

    for (i = 0; i < n-1; i++)
         if (arr[i] != arr[i+1])
             arr[len++] = arr[i];

    arr[len++] = arr[n-1];

    return len;
}
