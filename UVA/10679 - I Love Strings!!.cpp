#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[100100], letter[1100];

int main()
{
    int t, cnt, i, j, x, y, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %d", arr, &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", letter);
            x = strlen(letter);
            for(j = 0; j < x; ++j)
                if(arr[j] != letter[j])
                    break;
            if(j == x)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
