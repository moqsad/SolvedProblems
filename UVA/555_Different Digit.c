#include <stdio.h>
int main()
{
    int a, b, count, i, arr[5], j, ans, k, l, p;
    while(scanf("%d %d", &a, &b) == 2)
    {
        ans = 0;
        for(count = a; count <= b; ++count)
        {
            j = count;
            i = 0;
            while(j != 0)
            {
                arr[i] = j % 10;
                j /= 10;
                ++i;
            }
            k = i;
            for(j = 0; j < k; ++j)
            {
                p = 0;
                for(l = j + 1; l < k; ++l)
                    if(arr[j] == arr[l])
                    {
                        p = 1;
                        break;
                    }
                if(p == 1)
                    break;
            }
            if(p == 0)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
