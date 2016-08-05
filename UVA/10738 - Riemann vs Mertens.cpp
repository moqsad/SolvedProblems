#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int prime[180], arr[1000010], mu[1000010], M[1000010];

void func()
{
    int i, j, k, cnt = 0;
    prime[cnt++] = 2;
    for(i = 3; i < 1010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000005; j += k)
                arr[j] = 1;
        }
    }

    for(i = 4; i < 1000005; i += 2)
        arr[i] = 1;
    arr[1] = 1;
}

void mu__M()
{
    int i, j, x, y, z, k, p;
    mu[1] = M[1] = 1;
    for(i = 2; i < 1000002; ++i)
    {
        if(arr[i] == 0)
        {
            mu[i] = -1;
            M[i] = M[i - 1] - 1;
        }

        else
        {
            x = sqrt(i) + 2;
            y = i;
            j = 0;
            z = 0;
            p = 1;
            while(prime[j] < x)
            {
                if(y % prime[j] == 0)
                {
                    y /= prime[j];

                    if(y % prime[j] == 0)
                    {
                        p = 0;
                        break;
                    }

                    else
                    {
                        ++z;
                        if(arr[y] == 0)
                        {
                            ++z;
                            break;
                        }
                    }
                }
                ++j;
            }
            if(p == 0)
                M[i] = M[i - 1];
            else
            {
                if(z % 2 == 0)
                {
                    mu[i] = 1;
                    M[i] = M[i - 1] + 1;
                }

                else
                {
                    mu[i] = -1;
                    M[i] = M[i - 1] - 1;
                }
            }
        }
    }
}


int main()
{
    func();
    mu__M();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }
    return 0;
}
