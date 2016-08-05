#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[100010];
int f[100010];

int main()
{
    int t, cnt, i, x, y, k, z, n, ans, p;
    while(scanf("%s", arr) == 1)
    {
        n = k = strlen(arr);
        x = k - 2;
        y = k / 2;
        --k;
        z = k;
        f[z] = z;
        for(i = x; i >= y; --i)
        {
            while(k < z && arr[k] != arr[i])
                k = f[k + 1];
            if(arr[k] == arr[i])
                --k;
            f[i] = k;
        }

        k = z;
        for(i = 0; i <= z; ++i)
        {
            if(i == k)
            {
                p = 0;
                break;
            }
            while(k < z && arr[k] != arr[i])
                k = f[k + 1];
            if(arr[k] == arr[i])
                --k;
//            f[i] = k;
            if(i == k)
            {
                p = 1;
                break;
            }
        }


        if(p == 0)
        {
            ans = 2 * (z - k) + 1;
            ans = n - ans;
            printf("%s", arr);
            for(i = ans - 1; i >= 0; --i)
                printf("%c", arr[i]);
                printf("\n");
        }

        else
        {
            ans = 2 * (z - k);
            ans = n - ans;
            printf("%s", arr);
            for(i = ans - 1; i >= 0; --i)
                printf("%c", arr[i]);
                printf("\n");
        }
    }
    return 0;
}

