#include <cstdio>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

long long prime[78510], value[1000010];
bool arr[1000010];

map <long long, long long> mm;

int main()
{
    long long cnt = 0, i, j, k, t, n, x, y, z, ans;
    prime[cnt++] = 2;
    value[2] = 2;
    for(i = 3; i < 1002; i+=2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            value[i] = 2;
            k = i +i;
            for(j = i * i; j < 1000010; j +=k)
                arr[j] = 1;
        }
    }
    for(i = i; i < 1000010; i+= 2)
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            value[i] = 2;
        }
//    printf("%lld+++++++++++%lld\n", prime[cnt-1], cnt);
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        if(n < 1000010 && value[n] > 0)
            ans = value[n];
        else
        {
            y = n;
            x = sqrt(y) + 1;
            ans = 1;
            i = 0;
            while(prime[i] < x)
            {
                if(y % prime[i] == 0)
                {
                    z = 1;
                    while(y % prime[i] == 0)
                    {
                        y /= prime[i];
                        ++z;
                    }
                    ans *= z;
                    if(y < 1000010)
                    {
                        if(value[y] > 0)
                        {
                            ans *= value[y];
                            y = 1;
                            break;
                        }
                    }
                    else if(mm.find(y) != mm.end())
                    {
                        ans *= mm[y];
                        y = 1;
                        break;
                    }
                    x = sqrt(y) + 1;
                }
                ++i;
            }
            if(y > 1)
                ans *= 2;
        }
        if(n < 1000010)
            value[n] = ans;
        else
            mm[n] = ans;
        printf("Case %lld: %lld\n", cnt, ans - 1);
    }
    return 0;
}

/*
16
16
1000000000000
*/
