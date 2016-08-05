#include "bits/stdc++.h"
using namespace std;

void bfs(int x, int y);
char finish[35], arr[10050][35];
map <string, int> mm;
map <char, char> mc;
int visit[10050], dist[10050], j, num[10050][10050];
queue <int> Q;
string a, b;

int main()
{
    int i, cnt, t, m, n, k, x, y, r, s;
    char letter1[35], letter2[35];
    scanf("%d", &t);
    r = t - 1;
    for(cnt = 0; cnt < t; ++cnt)
    {
        memset(num, 0, sizeof(num));
        j = 0;
        mm.clear();
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", letter1, letter2);
            a = letter1;
            b = letter2;
            if(mm.find(a) == mm.end())
            {
                mm[a] = j;
                strcpy(arr[j], letter1);
                ++j;
            }
            if(mm.find(b) == mm.end())
            {
                mm[b] = j;
                strcpy(arr[j], letter2);
                ++j;
            }
            num[mm[a]][mm[b]] = 1;
            num[mm[b]][mm[a]] = 1;
        }
        s == n - 1;
        for(i = 0; i < n; ++i)
        {
            scanf("%s %s", letter1, letter2);
            bfs(mm[letter1], mm[letter2]);
            x = strlen(finish) - 1;
            for(y = x; y >= 0; --y)
                printf("%c", finish[y]);
            printf("\n");
        }
        if(cnt == r);
        else
            printf("\n");
    }
    return 0;
}

void bfs(int x, int y)
{
    memset(visit, 0, sizeof(visit));
    visit[x] = 1;
    while(!Q.empty())
        Q.pop();
    Q.push(x);

    int i, u, p = 0;
    char c;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i = 0; i < j; ++i)
        {
            if(num[u][i] == 1 && visit[i] == 0)
            {
                visit[i] = 1;
                Q.push(i);
                mc[arr[i][0]] = arr[u][0];
                if(arr[i][0] == arr[y][0])
                {
                    c = arr[y][0];
                    p = 1;
                    break;
                }
            }
        }
        if(p == 1)
            break;
    }
    p = 0;
    finish[p++] = c;
    while(c != arr[x][0])
    {
        c = mc[c];
        finish[p++] = c;
    }
    finish[p] = '\0';
    return ;
}
/*
10
3 2
hj jk
kl jk
kl hj
hj jk
*/
