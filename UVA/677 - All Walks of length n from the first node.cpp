#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int n, arr[20][20], taken[20], p;

vector <int> result, edge[20];

void backtrack(int i)
{
    int j, x;
    if(result.size() == n)
    {
        p = 1;
        printf("(1");
        x = result.size();
        for(j = 0; j < x; ++j)
            printf(",%d", result[j]);
        printf(")\n");
        return ;
    }

    x = edge[i].size();
    for(j = 0; j < x; ++j)
    {
        if(taken[edge[i][j]] == 0)
        {
            taken[edge[i][j]] = 1;
            result.push_back(edge[i][j]);
            backtrack(edge[i][j]);
            taken[edge[i][j]] = 0;
            result.pop_back();
        }
    }
}

int main()
{
    int cnt = 0, i, j, x;
    while(scanf("%d", &x) == 1)
    {
//        printf("%d__\n", x);
        if(x == -9999)
            scanf("%d %d", &x, &n);
        else
            scanf("%d", &n);

        if(cnt > 0)
            printf("\n");
        ++cnt;
        for(i = 1; i <= x; ++i)
            for(j = 1; j <= x; ++j)
            {
                scanf("%d", &arr[i][j]);
                if(arr[i][j] == 1)
                    edge[i].push_back(j);
            }
            p = 0;
            taken[1] = 1;
            backtrack(1);
            if(p == 0)
                printf("no walk of length %d\n", n);
            for(i = 1; i <= x; ++i)
                edge[i].clear();
    }
    return 0;
}
