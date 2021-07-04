#include <bits/stdc++.h>
using namespace std;
bool Subset(int arr1[], int arr2[],
              int a, int b)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if (arr2[i] == arr1[j])
                break;
        }

        if (j == b)
            return 0;
    }
    return 1;
}
int main() {
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int a = sizeof(arr2) / sizeof(arr2[0]);
    int b = sizeof(arr1) / sizeof(arr1[0]);
    if (Subset(arr1, arr2, b, a))
        printf("arr2[] is the subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");

	return 0;
}
