#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

char arr[1010], temp[1010];

string s[4800];

int main()
{
    int i = 2, j, k, l, min_, x, y, n;

    s[1] = "1";
    s[2] = "1";
    while(s[i++].size() <= 1000)
    {
        min_ = s[i - 2].size();
        x = k = 0;
        l = s[i - 1].size() - 1;
        for(j = min_ - 1; j >= 0; --j)
        {
            y = s[i - 1][l--] - 48 + s[i - 2][j] - 48 + x;
            arr[k++] = y % 10 + 48;
            x = y / 10;
        }

        for(; l >= 0; --l)
        {
            y = s[i - 1][l] - 48 + x;
            arr[k++] = y % 10 + 48;
            x = y / 10;
        }

        if(x > 0)
            arr[k++] = x + 48;
        j = k - 1;
        for(l = 0; l < k; ++l)
            temp[l] = arr[j--];
        temp[l] = '\0';
        s[i] = temp;
    }

//    printf("%d----\n", i);
    while(scanf("%d", &n) == 1)
        cout << s[n] << "\n";

    return 0;
}
