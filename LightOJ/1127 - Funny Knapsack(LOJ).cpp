#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

long long n, m, j, ans, save[32800], arr[32], w;

void func(long long index, long long sum)
{
    if(index == m)
    {
        if(sum <= w)
            save[j++] = sum;
        return ;
    }

    func(index + 1, sum + arr[index]);
    func(index + 1, sum);
}

long long binary_searc(long long data)
{
    long long s = 0, e = j, mid;
    while(s <= e)
    {
        mid = (s + e) / 2;

        if(save[mid] <= data)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}

void func2(long long index, long long sum)
{
    if(index == n)
    {
        if(sum <= w)
            ans += binary_searc(w - sum);
        return ;
    }

    func2(index + 1, sum + arr[index]);
    func2(index + 1, sum);
}

int main()
{
    long long t, cnt, i;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &w);
        for(i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);
        j = 0;
        m = n / 2;
        func(0, 0);
        sort(save, save + j);
        ans = 0;
        --j;
        func2(m, 0);
        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
