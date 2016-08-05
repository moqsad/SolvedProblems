#include "bits/stdc++.h"
using namespace std;

char n1[1000], n2[1000], sum1[1000], sum2[1000];
int sum[1000];

int main()
{
    int t, cnt, i, j, k, l, x, y;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s", n1);
        x = strlen(n1);
        i = x - 1;
        while(n1[i] == '0')
            --i;
        k = 0;
        for(j = i; j >= 0; --j)
        {
            sum1[k++] = n1[j];
        }


        scanf("%s", n2);
        x = strlen(n2);
        i = x - 1;
        while(n2[i] == '0')
            --i;
        l = 0;
        for(j = i; j >= 0; --j)
        {
            sum2[l++] = n2[j];
        }

        x = 0;
        j = 0;

        while(l > 0 && k > 0)
        {
            y = sum1[--k] + sum2[--l] - 96 + x;
            sum[j] = y % 10;
            x = y / 10;
            ++j;
        }

        if(k > 0)
            while(k > 0)
            {
                y = sum1[--k] - 48 + x;
                sum[j++] = y % 10;
                x = y / 10;
            }
        else
            while(l > 0)
            {
                y = sum2[--l] - 48 + x;
                sum[j++] = y % 10;
                x = y / 10;
            }

        if(x > 0)
        {
            sum[j] = x;
            ++j;
        }
        i = 0;
        while(sum[i] == 0)
            ++i;
        for(x = i; x < j; ++x)
            printf("%d", sum[x]);
        printf("\n");
    }
    return 0;
}
