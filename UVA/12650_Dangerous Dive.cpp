#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int num[10010], arr[10010];

int main()
{
    int n, r, i;
    while(scanf("%d %d", &n, &r) == 2)
    {
        for(i = 0; i < r; ++i)
            scanf("%d", &arr[i]);
        if(n == r)
            printf("*\n");
        else
        {
            memset(num, 0, sizeof(num));
            for(i = 0; i < r; ++i)
                num[arr[i]] = 1;
            for(i = 1; i <= n; ++i)
                if(num[i] == 0)
                    printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}
