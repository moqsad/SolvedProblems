#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int arr[60], ans[60];

int main()
{
    int t, cnt, x, i, j, n;
    double y, z;
    x = 1;
    i = 1;
    j = 2;
    while(i != 51)
    {
        i = 1;
        y = x + arr[i];
        z = sqrt(y);
        y = (int)z;
        while(arr[i] != 0 && y != z)
        {
            ++i;
            y = x + arr[i];
            z = sqrt(y);
            y = (int)z;
        }
        arr[i] = x;
        ++x;
        if(i == j)
        {
            ans[j - 1] = x - 2;
            ++j;
        }
    }
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}

