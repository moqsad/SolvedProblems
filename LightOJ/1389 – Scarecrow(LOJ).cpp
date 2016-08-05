#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char arr[105];

int main()
{
    int t, cnt, x, i, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &x);
        scanf("%s", arr);
        ans = 0;
        for(i = 0; i < x; ++i)
        {
            if(arr[i] == '.')
            {
                ++ans;
                i += 2;
            }
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
