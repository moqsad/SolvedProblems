#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int arr[1130], prime[300], cnt, ans[1130][20], temp[1130][20];

void prime_(void)
{
    int i, j, k;
    prime[cnt++] = 2;
    for(i = 3; i < 1130; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1130; j += k)
                arr[j] = 1;
        }
    }

//    printf("%d__________\n", cnt);
}

void func(void)
{
    int i, j, k;
    for(i = 0; i < cnt; ++i)
    {
        ans[prime[i]][1] = 1;
        for(j = prime[i] + 1; j < 1121; ++j)
            for(k = 2; k < 15; ++k)
                ans[j][k] = ans[j][k] + temp[j - prime[i]][k - 1];

        temp[prime[i]][1] = 1;
        for(j = prime[i] + 1; j < 1121; ++j)
            for(k = 2; k < 15; ++k)
                temp[j][k] = ans[j][k];
    }
}

int main()
{
    int n, k;
    prime_();
    func();
    while(scanf("%d %d", &n, &k) == 2)
    {
        if(n == 0 && k == 0)
            break;
        printf("%d\n", ans[n][k]);
    }
    return 0;
}
