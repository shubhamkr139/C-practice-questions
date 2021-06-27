//Given a string S, remove consecutive duplicates from it recursively.

#include <bits/stdc++.h>

using namespace std;

void remDup(char* x)
{
    if (x[0] == '\0')
    return;

    if (x[0] == x[1]) {
      int i = 0;
        while (x[i] != '\0') {
            x[i] = x[i + 1];
            i++;
        }

        remDup(x);
    }

    remDup(x + 1);
}

int main()
{
    char x1[] = "aabccba";
    remDup(x1);
    cout << x1 << endl;

    return 0;
}


