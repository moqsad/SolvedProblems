#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int arr[10010];

void func(void)
{
    int cnt = 0, i, j, k;
    for(i = 3; i < 10010; i += 2)
    {
        if(arr[i] == 0)
        {
            k = i + i;
            for(j = i * i; j < 10010; j += k)
                arr[j] = 1;
        }
    }

    for(i = 50; i < 10010; i += 2)
        arr[i] = 1;
}

int main()
{
    int t, cnt, n, x, i, j;
    func();
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = n / 2 + 1; i < n; ++i)
            if(arr[i] == 0)
                break;
        printf("%d\n", i);
    }
    return 0;
}
