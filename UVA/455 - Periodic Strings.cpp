#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int f[100];
char arr[100];

int main()
{
    int t, cnt, i, k, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        k = 0;
        for(i = 1; i < x; ++i)
        {
            while(k > 0 && arr[k] != arr[i])
                k = f[k - 1];

            if(arr[i] == arr[k])
                k++;

            f[i] = k;
        }

        if(k == 0 || k % (x - k) != 0)
            printf("%d\n", x);
        else
            printf("%d\n", x - k);

        if(cnt < t)
            printf("\n");
    }
    return 0;
}


