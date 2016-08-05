#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int arr[60], ans[60];

int main()
{
    int t, cnt, x, i, n;
    double y, z;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        ++n;
        x = 1;
        i = 1;
        while(i != n)
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
        }
        printf("%d\n", x - 2);
    }
    return 0;
}
