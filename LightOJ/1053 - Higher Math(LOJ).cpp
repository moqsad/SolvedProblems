#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, arr[5];
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr + 3);
        if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
            printf("Case %d: yes\n", cnt);
        else
            printf("Case %d: no\n", cnt);
    }
    return 0;
}
