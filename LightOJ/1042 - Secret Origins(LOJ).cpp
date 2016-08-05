#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, cnt, n, i, p, arr[40], x, y, ans, j, k;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        i = 0;
        while(n > 0)
        {
            arr[i++] = n % 2;
//            printf("%d++++\n", n % 2);
            n /= 2;
        }

        p = 0;

        n = i;
        k = 0;
        for(i = 1; i < n; ++i)
            if(arr[i - 1] == 1 && arr[i] == 0)
            {
                arr[i] = 1;
                arr[i - 1] = 0;
                p = 1;
                break;
            }

//        printf("%d_____\n", i);

        if(p == 0)
        {
            arr[i] = 1;
            arr[i - 1] = 0;
            n++;
        }

        k = 0;
        i -= 2;
        x = i / 2;
        for(j = i; j > x; --j)
        {
            if(arr[j] == 1 && arr[k] == 0)
            {
                arr[j] = 0;
                arr[k] = 1;
                ++k;
            }
            else
                break;
        }

        ans = 0;
        x = 1;
        for(j = 0; j < n; ++j)
        {
            ans += arr[j] * x;
//            printf("%d %d_____%d\n", arr[j], x, ans);
            x *= 2;
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
