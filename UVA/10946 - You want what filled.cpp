#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, p[] = {0, 0, -1, 1}, q[] = {-1, 1, 0, 0}, total;
char ch, arr[60][60];

struct data
{
    char a;
    int b;
};

vector <data>  v;

bool comp(data x, data y)
{
    if(x.b == y.b)
        return (x.a <= y.a);
    return (x.b > y.b);
}

void dfs(int row, int column)
{
    int i, x, y;
    for(i = 0; i < 4; ++i)
    {
        x = row + p[i];
        y = column + q[i];
        if(x >= 0 && x < n && y >= 0 && y < m)
        {
            if(arr[x][y] == ch)
            {
                arr[x][y] = '.';
                ++total;
                dfs(x, y);
            }
        }
    }
    return ;
}

int main()
{
    int i, j, x, cnt = 0;
    data info;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(m == 0 && n == 0)
            break;
        v.clear();
        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                if(arr[i][j] != '.')
                {
                    ch = arr[i][j];
                    arr[i][j] = '.';
                    total = 1;
                    dfs(i, j);
                    info.a = ch;
                    info.b = total;
                    v.push_back(info);
                }
            }
        x = v.size();
        stable_sort(v.begin(), v.end(), comp);
        printf("Problem %d:\n", ++cnt);
        for(i = 0; i < x; ++i)
        {
            printf("%c %d\n", v[i].a, v[i].b);
        }
    }
    return 0;
}
