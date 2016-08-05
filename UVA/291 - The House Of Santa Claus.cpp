#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int edge[8][8], visit[8][8], ans[12];

void func(int start, int index)
{
    int i;
    if(index == 9)
    {
        for(i = 1; i < 10; ++i)
            printf("%d", ans[i]);
        printf("\n");
        return ;
    }

    for(i = 1; i <= 5; ++i)
    {
        if(edge[start][i] == 1 && visit[i][start] == 0)
        {
            visit[start][i] = 1;
            visit[i][start] = 1;
            ans[index + 1] = i;
            func(i, index + 1);
            visit[start][i] = 0;
            visit[i][start] = 0;
        }
    }
}

int main()
{
    edge[1][2] = 1;
    edge[2][1] = 1;
    edge[2][3] = 1;
    edge[3][2] = 1;
    edge[3][4] = 1;
    edge[4][3] = 1;
    edge[4][5] = 1;
    edge[5][4] = 1;
    edge[5][1] = 1;
    edge[1][5] = 1;
    edge[5][3] = 1;
    edge[3][5] = 1;
    edge[1][3] = 1;
    edge[3][1] = 1;
    edge[5][2] = 1;
    edge[2][5] = 1;
    ans[1] = 1;
    func(1, 1);
    return 0;
}
