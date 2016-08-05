#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int m, n;

void dfs(char arr[][102], int i, int cnt, int m, int n);
int main()
{
    int cnt, i, det;
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m == 0)
            break;
        det = 0;
        char arr[m][102];
        for(cnt = 0; cnt < m; ++cnt)
        {
            scanf("%s", arr[cnt]);
        }
        for(i = 0; i < m; ++i)
            for(cnt = 0; cnt < n; ++cnt)
                if(arr[i][cnt] == '@')
                {
                    ++det;
                    dfs(arr, i, cnt, m, n);
                }
        cout<<det<<endl;
    }
    return 0;
}
void dfs(char arr[][102], int i, int cnt, int m, int n)
{
    int p, u, v;
    if(i < m && cnt < n && i > -1 && cnt > -1)
    {
        if(arr[i][cnt] == '@')
        {
            arr[i][cnt] = '*';
            for(p = 0; p < 8; ++p)
            {
                u = i + x[p];
                v = cnt + y[p];
                dfs(arr, u, v, m, n);
            }
        }
    }
    return;
}
