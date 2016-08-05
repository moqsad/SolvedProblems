#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

int mm[20000];
int p, n, m, k, arr[20], j;

bool binary_searc(int sum)
{
    int s = 0, end_ = j - 1, mid;
    while(s <= end_)
    {
        mid = (s + end_) / 2;

        if(mm[mid] < sum)
            s = mid + 1;
        else if(mm[mid] > sum)
            end_ = mid - 1;
        else
            return 1;
    }
    return 0;
}

void func(int index, int sum)
{
    if(index == n)
    {
        if(binary_searc(k - sum) || sum == k)
            p = 1;
        return ;
    }

    func(index + 1, sum + arr[index]);

    if(p == 1)
        return ;

    func(index + 1, sum);

    if(p == 1)
        return ;

    func(index + 1, sum + arr[index] + arr[index]);
    if(p == 1)
        return ;
}

void func2(int index, int sum)
{
    if(index == m)
    {
        mm[j++] = sum;
        return ;
    }

    func2(index + 1, sum + arr[index]);
    func2(index + 1, sum + arr[index] + arr[index]);
    func2(index + 1, sum);
}

int main()
{
    int t, cnt, i;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);

        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        p = 0;

        m = n / 2;
        j = 0;
        func2(0, 0);
        sort(mm, mm + j);

        func(m, 0);

        if(p == 1)
            printf("Case %d: Yes\n", cnt);
        else
            printf("Case %d: No\n", cnt);
    }

    return 0;
}
