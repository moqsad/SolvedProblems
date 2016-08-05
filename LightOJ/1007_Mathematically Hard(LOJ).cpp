#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

bool arr[5000010];
unsigned long long store[5000010], total = 1, ans, i, j, k, a, cnt, x, y, t, z, r, s, value[2000020];
int  power[2250][30];

int func(int a, int b)
{
    if(power[a][b] > 0)
        return power[a][b];
    if(b == 1)
        return power[a][b] = a;
    return power[a][b] = a * func(a, b - 1);
}

int prime[350];

int main()
{
    for(i = 4; i < 5000010; i+=2)
        arr[i] = 1;
    prime[cnt++] = 2;
    store[1] = 0;
    store[2] = 1;

    for(i = 3; i < 2245; ++i)
    {
        if(arr[i] == 0)
        {
            ans = i - 1;
            k = i + i;
            prime[cnt++] = i;
            for(j = i * i; j < 5000010; j += k)
                arr[j] = 1;
        }

        else
        {
            x = sqrt(i) + 1;
            y = i;
            ans = 1;
            a = 0;

            while(prime[a] < x)
            {
                if(y % prime[a] == 0)
                {
                    z = -1;
                    while(y % prime[a] == 0)
                    {
                        y /= prime[a];
                        ++z;
                    }
                    if(z > 0)
                        ans *= (prime[a] - 1) * func(prime[a], z);
                    else
                        ans *= (prime[a] - 1);
                    if(value[y] > 0)
                    {
                        ans *= value[y];
                        y = 1;
                        break;
                    }
                    x = sqrt(y) + 1;
                }
                ++a;
            }
            if(y > 1)
                ans *= (y - 1);
        }
        value[i] = ans;
        total += ans * ans;
        store[i] = total;
    }

    for(i = i; i < 5000002; ++i)
    {
        if(arr[i] == 0)
            ans = i - 1;

        else
        {
            x = sqrt(i) + 1;
            y = i;
            ans = 1;
            a = 0;

            while(prime[a] < x)
            {
                if(y % prime[a] == 0)
                {
                    z = -1;
                    while(y % prime[a] == 0)
                    {
                        y /= prime[a];
                        ++z;
                    }
                    if(z > 0)
                        ans *= (prime[a] - 1) * func(prime[a], z);
                    else
                        ans *= (prime[a] - 1);
                    if(y < 2000010 && value[y] > 0)
                    {
                        ans *= value[y];
                        y = 1;
                        break;
                    }
                    else if(arr[y] == 0)
                        break;
                    x = sqrt(y) + 1;
                }
                ++a;
            }
            if(y > 1)
                ans *= (y - 1);
        }
        if(i < 2000010)
        value[i] = ans;
        total += ans * ans;
        store[i] = total;
    }

    scanf("%llu", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%llu %llu", &x, &y);
        printf("Case %llu: %llu\n", cnt, store[y] - store[x - 1]);
    }
    return 0;
}
