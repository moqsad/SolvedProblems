#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define mod 100000007

set <long long> myset;
set <long long> ::iterator it;

long long arr[103000], dp[1500];

void init(void)
{
    long long i, j;

    for(i = 2; i <= 100000; ++i)
    {
        j = i * i;
        while(j <= 10000000000)
        {
            myset.insert(j);
            j = j * i;
        }
    }

    i = 0;
    for(it = myset.begin(); it != myset.end(); it++)
        arr[i++] = *it;

    sort(arr, arr + i);
}

int lower_end(long long a)
{
    int mid, start = 0, end_ = 102229;

    while(start <= end_)
    {
        mid = (start + end_) / 2;

        if(arr[mid] < a)
            start = mid + 1;
        else
            end_ = mid - 1;
    }

    return end_;
}

int upper_end(long long b)
{
    int mid, start = 0, end_ = 102229;

    while(start <= end_)
    {
        mid = (start + end_) / 2;

        if(arr[mid] > b)
            end_ = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}

long long func(int range)
{
    if(range <= 1)
        return 1;

    if(dp[range] != -1)
        return dp[range];

    long long sum = 0;

    for(int i = 1; i <= range; ++i)
        sum = (sum + func(i - 1) * func(range - i)) % mod;

    return dp[range] = sum;
}

int main()
{
    long long t, a, b, cnt;
    int range;

    init();

    memset(dp, -1, sizeof(dp));

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &a, &b);
        range = upper_end(b) - lower_end(a) - 1;
        //printf("%d\n", range);
        if(range == 0)
            printf("Case %lld: 0\n", cnt);
        else
            printf("Case %lld: %lld\n", cnt, func(range));
    }

    return 0;
}
