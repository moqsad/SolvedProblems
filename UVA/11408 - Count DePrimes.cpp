#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int arr[5000010], prime[900], store[5000010], ans[5000010];

int main()
{
    int i, j, cnt = 1, k, a, b, x, y, z;
    prime[cnt++] = 2;
    for(i = 3; i < 2245; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 5000001; j += k)
                arr[j] = 1;
        }
//        printf("%d %d\n", cnt, prime[cnt-1]);
    }

    for(i = 4; i < 5000001; i += 2)
        arr[i] = 1;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 2;
    ans[4] = 3;
    store[4] = store[2] = 2;
    store[3] = 3;
    z = 3;
    for(i = 5; i < 5000001; ++i)
    {
        if(arr[i] == 0)
        {
            ++z;
            store[i] = i;
//            if(i < 25)
//                printf("%d %d______________&&&&&&\n", i, store[i]);
        }
        else
        {
//            x = sqrt(i) + 1;
            j = 1;
            while(1)
            {
                if(i % prime[j] == 0)
                {
                    x = i / prime[j];
                    y = store[x];
//                    if(i < 25)
//                    printf("%d|||||||||______\n", y);
                    if(x % prime[j] != 0)
                        y += prime[j];
//                    if(i < 25)
//                    printf("%d|||||||||______222\n", y);
                    store[i] = y;
                    if(arr[y] == 0)
                        ++z;
//                    if(i < 25)
//                        printf("%d %d______________###\n", i, store[i]);
                    break;
                }
                ++j;
            }
        }
        ans[i] = z;
//        if(i < 25)
//            printf("%d %d+++++++++++++++\n", i, z);
    }
//    printf("%d____________\n", cnt);
    while(scanf("%d", &a) == 1)
    {
        if(a == 0)
            break;
        scanf("%d", &b);
        x = ans[b] - ans[a];
//        printf("%d__________________\n", x);
        if(ans[a] > ans[a - 1])
            ++x;
        printf("%d\n", x);
    }
    return 0;
}
