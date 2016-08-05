#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
void dfs(char arr[][25], int i, int cnt);
int main()
{
    int cnt, i, det, j = 0;
    while(scanf("%d", &n) == 1)
    {
        det = 0;
        char arr[n][25];
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%s", arr[cnt]);
        }
        for(i = 0; i < n; ++i)
            for(cnt = 0; cnt < n; ++cnt)
                if(arr[i][cnt] == '1')
                {
                    ++det;
                    dfs(arr, i, cnt);
                }
        ++j;
        printf("Image number %d contains %d war eagles.\n", j, det);
    }
    return 0;
}
void dfs(char arr[][25], int i, int cnt)
{
    if(i < n && cnt < n && i > - 1 && cnt > -1)
    {
        if(arr[i][cnt] == '1')
        {
            arr[i][cnt] = '0';
            dfs(arr, i, cnt + 1);
            dfs(arr, i, cnt - 1);
            dfs(arr, i + 1, cnt);
            dfs(arr, i + 1, cnt + 1);
            dfs(arr, i + 1, cnt - 1);
            dfs(arr, i - 1, cnt);
            dfs(arr, i - 1, cnt + 1);
            dfs(arr, i - 1, cnt - 1);
        }
    }
    return;
}
