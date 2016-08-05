#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

char arr[2000];
int num[20];

int main()
{
    int t, cnt, x, k, j, i, sum, n;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s", arr);
        scanf("%d", &n);
        for(i = 0; i <  n; ++i)
            scanf("%d", &num[i]);

        x = strlen(arr);
        for(i = 0; i < n; ++i)
        {
            sum = 0;
            for(j = 0; j < x; ++j)
                sum = (sum * 10 + arr[j]  - 48) % num[i];
            if(sum > 0)
                break;
        }
        if(sum == 0)
            printf("%s - Wonderful.\n", arr);
        else
            printf("%s - Simple.\n", arr);
    }
    return 0;
}
