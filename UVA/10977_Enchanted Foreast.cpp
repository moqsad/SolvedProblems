#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

char arr[210][210];

queue <int> Qrow;
queue <int> Qcolumn;

bool visit[210][210];
int dist[210][210], p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1}, r, c;

void bfs(void)
{
//    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));

    Qrow.push(1);
    Qcolumn.push(1);
    arr[1][1] = '*';

//    visit[1][1] = 1;
    dist[1][1] = 0;

    int i, x, y, u, v;
    while(!Qrow.empty())
    {
        u = Qrow.front();
        v = Qcolumn.front();
        Qrow.pop();
        Qcolumn.pop();
        for(i = 0; i < 4; ++i)
        {
            x = u + p[i];
            y = v + q[i];
            if(x >= 1 && x <= r && y >= 1 && y <= c && arr[x][y] == '0')
            {
                Qcolumn.push(y);
                Qrow.push(x);
                arr[x][y] = '*';
                dist[x][y] = dist[u][v] + 1;
            }
        }
    }
}

int main()
{
    int i, j, k, jj, block, a, b, l, x[110], y[110], z[110];
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d", &r, &c) == 2)
    {
        if(r == 0 && c == 0)
            break;
        memset(arr, '0', sizeof(arr));
        scanf("%d", &block);
        for(i = 0; i < block; ++i)
        {
            scanf("%d %d", &a, &b);
            arr[a][b] = '*';
        }
        scanf("%d", &jj);
        for(i = 0; i < jj; ++i)
        {
            scanf("%d %d %d", &x[i], &y[i], &z[i]);
            arr[x[i]][y[i]] = '*';
        }
        for(i = 1; i <= r; ++i)
            for(j = 1; j <= c; ++j)
            {
                if(arr[i][j] == '0')
                    for(k = 0; k < jj; ++k)
                    {
                        a = x[k] - i;
                        b = y[k] - j;
                        if(a * a + b * b <= z[k] * z[k])
                        {
                            arr[i][j] = '*';
                            break;
                        }
                    }
            }
//        printf("\n\n");
//        for(i = 1; i <= r; ++i)
//        {
//            for(j = 1; j <= c; ++j)
//            {
//                printf("%c", arr[i][j]);
//            }
//            printf("\n");
//        }
        bfs();
        if(dist[r][c] >= 0)
            printf("%d\n", dist[r][c]);
        else
            printf("Impossible.\n");
    }
    return 0;
}
//freopen("H:\\C_Codes\\input.txt","r",stdin);
