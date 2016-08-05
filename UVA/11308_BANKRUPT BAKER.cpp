#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <map>
using namespace std;

map <string, int> mm;
string a;

int main()
{
    int t, m, n, b, k, c, x, sum, num[110], i, j, p, cnt, det, temp;
    char arr[200], str[110][200];
    scanf("%d", &t);
    getchar();
    for(cnt = 0; cnt < t; ++cnt)
    {
        det = 0;
        gets(arr);
        j = strlen(arr);
        for(i = 0; i < j; ++i)
            putchar(toupper(arr[i]));
        printf("\n");
        scanf("%d %d %d", &m, &n, &b);
        for(i = 0; i < m; ++i)
        {
            cin >> a >> c;
            mm[a] = c;
        }
        getchar();
        p = 0;
        for(i = 0; i < n; ++i)
        {
            sum = 0;
            gets(arr);
            scanf("%d", &k);
            for(j = 0; j < k; ++j)
            {
                cin >> a >> x;
                sum = sum + mm[a] * x;
            }
            getchar();
            if(sum <= b)
            {
                num[det] = sum;
                strcpy(str[det], arr);
                p = 1;
                ++det;
            }
        }
        if(p == 1)
        {
            for(i = 0; i < det; ++i)
            {
                for(j = i + 1; j < det; ++j)
                {
                    if(num[j] < num[i])
                    {
                        temp = num[i];
                        num[i] = num[j];
                        num[j] = temp;
                        strcpy(arr, str[i]);
                        strcpy(str[i], str[j]);
                        strcpy(str[j], arr);
                    }
                    else if(num[j] == num[i])
                    {
                        if(strcmp(str[i], str[j]) > 0)
                        {
                            strcpy(arr, str[i]);
                            strcpy(str[i], str[j]);
                            strcpy(str[j], arr);
                        }
                    }
                }
                printf("%s\n", str[i]);
            }
        }
        else
            printf("Too expensive!\n");
        printf("\n");
    }
    return 0;
}

