#include <bits/stdc++.h>
using namespace std;

#define sz 1005
#define inf 1000000000

struct data
{
    int w, iq, ind, v;
} arr[sz], L[sz];

bool comp(data p, data q)
{
    if(p.w != q.w)
        return p.w < q.w;
    return p.iq < q.iq;
}

int n, index_[sz];

int binary_searc(int s, int e, int d)
{
    int mid;

    while(s <= e)
    {
        mid = (s + e) / 2;

        if(index_[mid] < d)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if(index_[s - 1] == d)
        s -=  1;
    else
        index_[s] =  d;

    return s;
}

int LIS(int s, int e)
{
    int max_ = 0, i, ret;
    for(i = 1; i <= e; ++i)
    {
        ret = binary_searc(0, max_, arr[i].iq);
        max_ = max(max_, ret);
        L[i] = arr[i];
        L[i].v = ret;
    }
    return max_;
}

void print(int max_, int shuru, int smaller, int pre)
{
    if(max_ == 0)
        return ;

    while(L[shuru].v != max_ || L[shuru].iq <= smaller || L[shuru].w == pre)
        --shuru;

    print(max_ - 1, shuru - 1, L[shuru].iq, L[shuru].w);
    printf("%d\n", L[shuru].ind);
}

int main()
{
    int i, j, max_;
    data info;
    while(scanf("%d %d", &info.w, &info.iq) == 2)
    {
        info.ind = ++n;
        arr[n] = info;
    }

    sort(arr + 1, arr + n + 1, comp);

    index_[0] = inf;
    max_ = LIS(1, n);
    printf("%d\n", max_);
    print(max_, n, -1, -1);
    return 0;
}
