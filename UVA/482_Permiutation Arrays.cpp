#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

char arr[100010], ans[10010][25], letter[25];
int num[10010];

int main()
{
    int t, i, j, k, cnt, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        getchar();
        getchar();
        gets(arr);
        x = strlen(arr);
        j = 0;
        k = 0;
        for(i = 0; i < x; ++i)
        {
            if(arr[i] == ' ')
            {
                letter[j] = '\0';
                num[k++] = atoi(letter);
                j = 0;
            }
            else
                letter[j++] = arr[i];
        }
        letter[j] = '\0';
        num[k++] = atoi(letter);
        for(i = 0; i < k; ++i)
        {
            scanf("%s", letter);
            strcpy(ans[num[i]], letter);
        }
        for(i = 1; i <= k; ++i)
            printf("%s\n", ans[i]);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
