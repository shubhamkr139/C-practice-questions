//Given a sorted array A of size N, delete all the duplicates elements from A.
#include <bits/stdc++.h>
using namespace std;
int remDup(int arr[], int x)
{
    if (x==0 || x==1)
    return x;
    int temp[x];
    int j = 0;
    for (int i=0; i<x-1; i++)
       if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
            temp[j++] = arr[x-1];
    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

int main()
{
    int arr[] = {2, 2, 2, 2, 2};
    int x = sizeof(arr) / sizeof(arr[0]);
    x = remDup(arr, x);
    for (int i=0; i<x; i++)
       cout << arr[i] << " ";


    return 0;
}

