#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[10];

int main()
{
    int t, cnt, x, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %s", &n, arr);
        printf("Case %d: ", cnt);
        x = n % 3;
        if(strcmp(arr, "Alice") == 0)
        {
            if(x == 1)
                printf("Bob\n");
            else
                printf("Alice\n");
        }

        else
        {
            if(x == 0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;
}
