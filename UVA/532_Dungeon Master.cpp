#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

char arr[35][35][35];
int a[] = {0, 0, 0, 0, -1, 1}, b[] = {-1, 0, 0, 1, 0, 0}, c[] = {0, -1, 1, 0, 0, 0};
int srow, scolumn, slevel, erow, ecolumn, elevel, dist[35][35][35], L, R, C;
queue <int> Qlevel;
queue <int> Qrow;
queue <int> Qcolumn;
bool visit[35][35][35];

void BFS(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    while(!Qlevel.empty())
    {
        Qlevel.pop();
        Qrow.pop();
        Qcolumn.pop();
    }

    visit[slevel][srow][scolumn] = 1;
    dist[slevel][srow][scolumn] = 0;
    Qlevel.push(slevel);
    Qrow.push(srow);
    Qcolumn.push(scolumn);

    int k, x, y, z, r, s, t, p = 0;

    while(!Qlevel.empty())
    {
        x = Qlevel.front();
        y = Qrow.front();
        z = Qcolumn.front();

        Qlevel.pop();
        Qrow.pop();
        Qcolumn.pop();
        for(k = 0; k < 6; ++k)
        {
            r = x + a[k];
            s = y + b[k];
            t = z + c[k];
            if(r >= 0 && r < L && s >= 0 && s < R && t >= 0 && t < C)
            {
                if(visit[r][s][t] == 0 && (arr[r][s][t] == '.' || arr[r][s][t] == 'E'))
                {
                    dist[r][s][t] = dist[x][y][z] + 1;
                    if(r == elevel && s == erow && t == ecolumn)
                    {
                        p = 1;
                        break;
                    }
                visit[r][s][t] = 1;
                Qlevel.push(r);
                Qrow.push(s);
                Qcolumn.push(t);
                }
            }
        }
        if(p == 1)
            break;
    }
    return ;
}

int main()
{
    int cnt, i, j;
    while(scanf("%d %d %d", &L, &R, &C) == 3)
    {
        if(L == 0 && R == 0 && C == 0)
            break;
        for(cnt = 0; cnt < L; ++cnt)
        {
            for(i = 0; i < R; ++i)
            {
                scanf("%s", &arr[cnt][i]);
                for(j = 0; j < C; ++j)
                    if(arr[cnt][i][j] == 'S')
                    {
                        slevel = cnt;
                        srow = i;
                        scolumn = j;
                    }
                    else if(arr[cnt][i][j] == 'E')
                    {
                        elevel = cnt;
                        erow = i;
                        ecolumn = j;
                    }
            }
        }
        BFS();
        if(dist[elevel][erow][ecolumn] > -1)
            printf("Escaped in %d minute(s).\n", dist[elevel][erow][ecolumn]);
        else
            printf("Trapped!\n");
    }
    return 0;
}
