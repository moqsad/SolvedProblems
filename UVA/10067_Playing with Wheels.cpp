#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

bool oppose[90010], visit[90010];
int dist[90010], start, finish;

queue <int> Q;

void bfs(void)
{
    memset(dist, -1, sizeof(dist));
    memset(visit, 0, sizeof(visit));

    while(!Q.empty())
        Q.pop();

    Q.push(start);
    visit[start] = 1;
    dist[start] = 0;
    int i, u, x, y[2], temp;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = u / 1000;
        y[0] = u + 1000;
        y[1] = u - 1000;
        if(x == 0)
            y[1] = u + 9000;
        else if(x == 9)
            y[0] = u - 9000;
//            printf("%d %d____\n", y[0], y[1]);
        for(i = 0; i < 2; ++i)
            if(visit[y[i]] == 0 && oppose[y[i]] == 0)
            {
                Q.push(y[i]);
                visit[y[i]] = 1;
                dist[y[i]] = dist[u] + 1;
            }
        if(y[0] == finish || y[1] == finish)
            break;
        temp = u % 100;
        x = (u / 100) % 10;
        y[0] = (u / 100 + 1) * 100 + temp;
        y[1] = (u / 100 - 1) * 100 + temp;
        if(x == 0)
            y[1] = (u / 100 + 9) * 100 + temp;
        else if(x == 9)
            y[0] =(u / 100 - 9) * 100 + temp;
//            printf("%d %d____\n", y[0], y[1]);
        for(i = 0; i < 2; ++i)
            if(visit[y[i]] == 0 && oppose[y[i]] == 0)
            {
                Q.push(y[i]);
                visit[y[i]] = 1;
                dist[y[i]] = dist[u] + 1;
            }
        if(y[0] == finish || y[1] == finish)
            break;
        temp = u % 10;
        x = (u / 10) % 10;
        y[0] = (u / 10 + 1) * 10 + temp;
        y[1] = (u / 10 - 1) * 10 + temp;
        if(x == 0)
            y[1] = (u / 10 + 9) * 10 + temp;
        else if(x == 9)
            y[0] =(u / 10 - 9) * 10 + temp;
//            printf("%d %d____\n", y[0], y[1]);
        for(i = 0; i < 2; ++i)
            if(visit[y[i]] == 0 && oppose[y[i]] == 0)
            {
                Q.push(y[i]);
                visit[y[i]] = 1;
                dist[y[i]] = dist[u] + 1;
            }
        if(y[0] == finish || y[1] == finish)
            break;
        x = u % 10;
        y[0] = u + 1;
        y[1] = u - 1;
        if(x == 0)
            y[1] = u + 9;
        else if(x == 9)
            y[0] = u - 9;
//            printf("%d %d____\n", y[0], y[1]);
        for(i = 0; i < 2; ++i)
            if(visit[y[i]] == 0 && oppose[y[i]] == 0)
            {
                Q.push(y[i]);
                visit[y[i]] = 1;
                dist[y[i]] = dist[u] + 1;
            }
        if(y[0] == finish || y[1] == finish)
            break;
    }
    return;
}

int main()
{
    int t, n, i, cnt, x;
    char arr[15];
    scanf("%d", &t);
    getchar();
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(oppose, 0, sizeof(oppose));
        gets(arr);
        start = (((arr[0] - 48) * 10 + arr[2] - 48) * 10 + arr[4] - 48) * 10 + arr[6] - 48;
        gets(arr);
        finish = (((arr[0] - 48) * 10 + arr[2] - 48) * 10 + arr[4] - 48) * 10 + arr[6] - 48;
        scanf("%d", &n);
        getchar();
        for(i = 0; i < n; ++i)
        {
            gets(arr);
            x = (((arr[0] - 48) * 10 + arr[2] - 48) * 10 + arr[4] - 48) * 10 + arr[6] - 48;
            oppose[x] = 1;
        }
        if(cnt < t)
            getchar(); // most probably ei problemtate input gular maje blank line thakar kotha thakleo, blank line thik moto maintain kora hoi nai.
        bfs();
        if(dist[finish] >= 0)
            printf("%d\n", dist[finish]);
        else
            printf("-1\n");
    }
    return 0;
}
/*
34
2 3 0 7
0 4 0 9
3
4 7 0 4
3 4 4 1
0 0 4 1
*/
