#include <cstdio>
long long arr[1000000];
long long ans[1000000], one[1000000];

int main()
{
    long long a, b, i, j, k, cnt = 1, t, x;
    arr[2] = 5;
    ans[2] = 1;
    one[2] = 1;
    for(i = 3; i < 1000000; ++i)
    {
        if(i % 2 == 1 && arr[i] == 0)
        {
            if(i < 1000)
//            printf("%d____\n", i);
            arr[i] = 5;
            j = 0;
            x = i;
            while(x > 0)
            {
                j += x % 10;
                x /= 10;
            }
            if(arr[j] == 5)
            {
                one[i] = 1;
                ++cnt;
            }
            k = i + i;
            for(j = i * i; j < 1000000; j += k)
            {
                arr[j] = 1;
            }
        }
        ans[i] = cnt;
    }

    scanf("%lld", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld %lld", &a, &b);
        x = ans[b] - ans[a];
        if(one[a] == 1)
            ++x;
        printf("%lld\n", x);
    }
    return 0;
}
