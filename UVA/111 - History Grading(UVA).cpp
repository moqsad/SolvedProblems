#include <bits/stdc++.h>
using namespace std;

#define sz 25

int q[sz], in[sz], index_[sz];

int binary_searc(int s, int e, int d)
{
    int mid;

    while(s <= e)
    {
        mid = (s + e) / 2;

        if(index_[mid] > d)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if(index_[s - 1] == d)
        s -= 1;
    else
        index_[s] = d;

    return s;
}

int LIS(int s, int e)
{
    int i, max_ = 0;

    for(i = s; i <= e; ++i)
        max_ = max(max_, binary_searc(0, max_, q[i]));

    return max_;
}

int main()
{
    int n, i, a;

    scanf("%d", &n);

    for(i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        in[i] = a;
    }

    while(scanf("%d", &a) == 1)
    {
        q[a] = in[1];
        for(i = 2; i <= n; ++i)
        {
            scanf("%d", &a);
            q[a] = in[i];
        }
        index_[0] = -1;
        printf("%d\n", LIS(1, n));
    }
    return 0;
}
