#include "bits/stdc++.h"
using namespace std;

int visit[250], dist[250], num[250][250], i;
char arr[250][15], in[15], out[15], letter[30];

queue <int> Q;
map <string, int> mm;
string a;
int bfs(int x, int y);

int main()
{
    int j, x, y, k, t, cnt, l = 0, m;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        if(l > 0)
            printf("\n");
        memset(num, 0, sizeof(num));
        i = 0;
        mm.clear();
        while(scanf("%s", arr[i]) == 1)
        {
            if(arr[i][0] == '*')
                break;
            a = arr[i];
            mm[a] = i;
            for(j = 0; j < i; ++j)
            {
                x = strlen(arr[j]);
                if(x == strlen(arr[i]))
                {
                    k = 0;
                    for(y = 0; y < x; ++y)
                    {
                        if(arr[j][y] != arr[i][y])
                            ++k;
                    }
                    if(k == 1)
                    {
                        num[i][j] = 1;
                        num[j][i] = 1;
                    }
                }
            }
            ++i;
        }
        getchar();
        while(gets(letter))
        {
            if(letter[0] == '\0')
                break;
            sscanf(letter, "%s %s", in, out);
            a = in;
            x = mm[a];
            a = out;
            y = mm[a];
            m = bfs(x, y);
            printf("%s %s %d\n", in, out, m);
        }
        ++l;
    }
    return 0;
}

int bfs(int x, int y)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    while(!Q.empty())
        Q.pop();

    visit[x] = 1;
    dist[x] = 0;
    Q.push(x);

    int u, j;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        for(j = 0; j < i; j++)
        {
            if(num[u][j] == 1 && visit[j] == 0)
            {
                dist[j] = dist[u] + 1;
                if(j == y)
                {
                    return dist[j];
                }
                visit[j] = 1;
                Q.push(j);
            }
        }
    }
}
/*2
say
pay
*
pay say*/
