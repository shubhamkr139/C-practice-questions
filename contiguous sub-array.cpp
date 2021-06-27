//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int x[], int size)
{
    int max = INT_MIN, maxEnding = 0;
    for (int i = 0; i < size; i++)
    {
        maxEnding = maxEnding + x[i];
        if (max < maxEnding)
            max = maxEnding;

        if (maxEnding < 0)
            maxEnding = 0;
    }
    return max;
}

int main()
{

    int x[] = {1,2,3,-2,5};
    int n = sizeof(x)/sizeof(x[0]);
    int maxSum = maxSubArraySum(x, n);
    cout << "The contiguous sub-array with maximum sum is: " << maxSum;

    return 0;
}

