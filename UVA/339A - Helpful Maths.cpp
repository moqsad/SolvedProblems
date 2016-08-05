#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int num[110], i, j, x, y;
    char arr[210];
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        j = 0;
        for(i = 0; i < x; i += 2)
            num[j++] = arr[i] - 48;
        sort(num, num + j);
        printf("%d", num[0]);
        for(i = 1; i < j; ++i)
            printf("+%d", num[i]);
        printf("\n");
    }
    return 0;
}
