#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#define sz 65025

int pp[sz], qq[sz], index_[sz];

int binary_searc(int s, int e, int data)
{
    int mid;
    while(s <= e)
    {
        mid = (s + e) / 2;

        if(index_[mid] > data)
            e = mid - 1;
        else
            s = mid + 1;
    }
//    printf("%d___\n", s);
    if(index_[s - 1] == data)
        s -= 1;
    else
        index_[s] = data;

//    printf("%d %d+++++\n", data, s);

    return s;
}

int LIS(int s, int e)
{
    int max_ = 0, i;
    for(i = 0; i <= e; ++i)
        max_ = max(max_, binary_searc(0, max_, qq[i]));
    return max_;
}

int main()
{
    int t, n, p, q, i, a, cnt = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &p, &q);
        memset(pp, -1, sizeof(pp));
        for(i = 0; i <= p; ++i)
        {
            scanf("%d", &a);
            pp[a] = i;
        }

        for(i = 0; i <= q; ++i)
        {
            scanf("%d", &a);
            qq[i] = pp[a];
        }
        index_[0] = -1;
        printf("Case %d: %d\n", ++cnt, LIS(0, q));
    }
    return 0;
}
