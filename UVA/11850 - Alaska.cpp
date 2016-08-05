#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[1500];

int main()
{
    int n, x, i, p;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        p = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        x = n - 1;
        for(i = 0; i < x; ++i)
            if(arr[i + 1] - arr[i] > 200)
            {
                p = 1;
                break;
            }
        if((1422 - arr[x]) * 2 > 200)
            p = 1;
        if(p == 0)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
