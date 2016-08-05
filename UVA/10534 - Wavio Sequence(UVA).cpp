#include <bits/stdc++.h>
using namespace std;

#define sz 10005
#define inf 1000000000

int arr[sz], index1_[sz], index2_[sz], L1[sz], L2[sz];

int binary_searc_dec(int s, int e, int d)
{
    int mid;

    while(s <= e)
    {
        mid = (s + e) / 2;

        if(index2_[mid] > d)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if(index2_[s - 1] == d)
        s -= 1;
    else
        index2_[s] = d;

    return s;
}

int binary_searc_inc(int s, int e, int d)
{
    int mid;

    while(s <= e)
    {
        mid = (s + e) / 2;

        if(index1_[mid] > d)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if(index1_[s - 1] == d)
        s -= 1;
    else
        index1_[s] = d;

    return s;
}

int LIS(int s, int e)
{
    int max_inc = 0, max_dec = 0, i, j = e, ans = 0;

    for(i = s; i <= e; ++i)
    {
        max_inc = max(max_inc, binary_searc_inc(0, max_inc, arr[i]));
        L1[i] = max_inc;
        max_dec = max(max_dec, binary_searc_dec(0, max_dec, arr[j]));
        L2[j--] = max_dec;
    }

    for(i = 1; i <= e; ++i)
    {
        ans = max(ans, min(L1[i], L2[i]) * 2 - 1);
//        printf("%d %d____\n", L1[i], L2[i]);
    }

    return ans;
}

int main()
{
    int n, i;
    while(scanf("%d", &n) == 1)
    {
        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        index1_[0] = -1;
        index2_[0] = -1;
        printf("%d\n", LIS(1, n));
    }
    return 0;
}
