#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long shuru[8], shesh[8];
char arr[][10] = {"shata", "hajar", "lakh", "kuti"};

int main()
{
    long long n, m, i, cnt = 0, p;
    while(scanf("%lld", &n) == 1)
    {
        m = n;
        p = 0;
        for(i = 0; i < 5; ++i)
        {
            shuru[i] = shesh[i] = 0;
            if(i != 1)
            {
                shuru[i] = n % 100;
                n /= 100;
            }

            else
            {
                shuru[i] = n % 10;
                n /= 10;
            }
        }

        for(i = 1; i < 5; ++i)
        {
            if(i != 1)
            {
                shesh[i] = n % 100;
                n /= 100;
            }

            else
            {
                shesh[i] = n % 10;
                n /= 10;
            }
        }

        printf("%4lld.", ++cnt);
        for(i = 4; i > 0; --i)
        {
            if(shesh[i] > 0)
            {
                printf(" %lld %s", shesh[i], arr[i - 1]);
                p = 1;
            }
        }

        for(i = 4; i > 0; --i)
        {
            if(shuru[i] > 0)
                printf(" %lld %s", shuru[i], arr[i - 1]);
            else if(i == 4 && p == 1)
            printf(" %s", arr[i - 1]);

        }
        if(shuru[i] > 0 || !m)
            printf(" %lld", shuru[i]);

        printf("\n");
    }
    return 0;
}
