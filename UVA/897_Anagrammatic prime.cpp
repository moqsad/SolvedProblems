#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}, p, n, i, j, k, l , x, y, ans[30], arr[10];
    char letter[10];

    ans[0] = 2;
    ans[1] = 3;
    j = 2;

    for(i = 5; i < 1000; ++i)
    {
        x = i;
        k = 0;
        while(x > 0)
        {
            arr[k++] = x % 10;
            x /= 10;
        }
        sort(arr, arr + k);
        for(l = 0; l < k; ++l)
            letter[l] = arr[l] + 48;
        letter[l] = '\0';
        do
        {
            x = atoi(letter);
            y = sqrt(x) + 2;
            k = 0;
            p = 1;
            while(prime[k] < y)
            {
                if(x % prime[k++] == 0)
                {
                    p = 0;
                    break;
                }
            }
            if(p == 0)
                break;
        }
        while(next_permutation(letter, letter + l));
        if(p == 1)
            ans[j++] = i;
    }

    while(scanf("%d", &n) == 1)
    {
        if(n==0)
            break;
        x = n;
        y = 1;
        while(x > 0)
        {
            x /= 10;
            y *= 10;
        }
        p = 0;
        for(i = 0; i < j; ++i)
            if(ans[i] > n && ans[i] < y)
            {
                p = 1;
                printf("%d\n", ans[i]);
                break;
            }
        if(p == 0)
            printf("0\n");
    }
    return 0;
}
