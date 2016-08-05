#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[1000010];
int f[1000010];

int main()
{
    int x, y, k, i;
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        if(arr[0] == '.' && x == 1)
            break;
        f[0] = k = 0;
        for(i = 1; i < x; ++i)
        {
            while(k > 0 && arr[k] != arr[i])
                k = f[k-1];
            if(arr[i] == arr[k])
                ++k;
            f[i] = k;
        }
//        printf("%d__________\n", k);
        y = x - k;
        if(k % y == 0)
            printf("%d\n", k / y + 1);
        else
            printf("%d\n", x);
    }
    return 0;
}
