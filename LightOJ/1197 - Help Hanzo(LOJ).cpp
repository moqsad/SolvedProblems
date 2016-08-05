#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

unsigned int prime[4795];
bool arr[100005];

int main()
{
    unsigned int i, j, k, t, cnt = 0, x, end_, start, a, b, ans;

    for(i = 3; i < 46350; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 46350; j += k)
                arr[j] = 1;
        }
    }

    scanf("%u", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        ans = 0;
        scanf("%u %u", &a, &b);
        end_ = b - a + 1;
        for(i = 0; i < end_; ++i)
            arr[i] = 0;
//        memset(arr, 0, sizeof(bool) * end_);
        x = sqrt(b) + 1;
        i = 0;
        while(prime[i] < x)
        {
            k = prime[i] + prime[i];

            if(a % prime[i] == 0)
            {
                if(a % 2 == 1)
                    start = 0;
                else
                    start = prime[i];
            }

            else
            {
                j = (a / prime[i]) * prime[i] + prime[i];

                if(j % 2 == 1)
                    start = j - a;
                else
                    start = j + prime[i] - a;
            }

            if(start + a == prime[i])
                start += k;

            for(j = start; j < end_; j += k)
                arr[j] = 1;

            ++i;
        }

        start = a % 2;

        for(j = start; j < end_; j += 2)
            arr[j] = 1;

        for(j = 0; j < end_; ++j)
            if(arr[j] == 0)
                ++ans;

        if(a <= 2 && b >= 2)
            ++ans;

        if(a == 1)
            --ans;

        printf("Case %u: %u\n", cnt, ans);
    }
    return 0;
}
