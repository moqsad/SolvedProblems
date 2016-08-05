#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void func(int k, int arr[][200], int cnt);
int p, det, n;

int main()
{
    int a, b, l, i, j, k, x, cnt, arr[200][200];
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        memset(arr, 0, sizeof(arr));
        scanf("%d", &l);
        for(i = 0; i < l; ++i)
        {
            scanf("%d %d", &a, &b);
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        p = 0;
        x = n - 2;
        for(j = 0; j < x; ++j)
        {
            k = j;
            cnt = 0;
            det = j;
            func(k, arr, cnt);
            if(p == 1)
                break;
            for(i = 0; i < n; ++i)
                for(l = 0; l < n; ++l)
                    if(arr[i][l] == 2)
                    {
                        arr[i][l] = 1;
                        arr[l][i] = 1;
                    }
        }
        if(p == 0)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        p = 0;
    }
    return 0;
}

void func(int k, int arr[][200], int cnt)
{
    int i;
    for(i = 0; i < n; ++i)
    {
        if(p == 1)
            break;
        if(arr[k][i] == 1)
        {
            arr[k][i] = 2;
            arr[i][k] = 2;
            ++cnt;
            if((det == i || det == k) && cnt % 2 == 1 && cnt > 2)
            {
                p = 1;
                break;
            }
            k = i;
            func(k, arr, cnt);
        }
    }
    return;
}
