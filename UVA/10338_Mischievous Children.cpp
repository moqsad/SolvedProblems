#include <cstdio>
#include <cstring>

long long num[92], factorial[25];
char arr[25];

long long fact(long long a)
{
    if(factorial[a] > 0)
        return factorial[a];
    if(a == 1)
        return factorial[a] = 1;
    factorial[a] = a * fact(a - 1);
    return factorial[a];
}


int main()
{
    long long t, cnt, i, x, y;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(num, 0, sizeof(num));
        scanf("%s", arr);
        y = strlen(arr);
        x = fact(y);
        for(i = 0; i < y; ++i)
        ++num[arr[i]];
        for(i = 65; i < 91; ++i)
            if(num[i] > 1)
            x = x / fact(num[i]);
        printf("Data set %lld: %lld\n", cnt, x);
    }
    return 0;
}
