#include <bits/stdc++.h>
using namespace std;
bool Triplet(int N[], int arr_size, int sum)
{

    for (int i = 0;i < arr_size - 2;i++)
    {

        for (int j = i + 1;j < arr_size - 1;j++)
        {

            for (int k = j + 1;k < arr_size;k++)
            {
                if (N[i] + N[j] + N[k] == sum)
                {
                cout << "The Triplet is " << N[i] << ", " << N[j] << ", " << N[k];
                return true;
                }
            }
        }
    }
    return false;
}
int main() {
	int N[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 13;
    int arr_size = sizeof(N)/sizeof(N[0]);
    Triplet(N, arr_size, sum);
	return 0;
}
