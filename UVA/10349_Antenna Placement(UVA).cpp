#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

char arr[45][15];
int visit[45][15], match[45][15][3], even, odd, h, l, p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1};

bool bpm(int r, int c)
{
    int i, x, y;

    for(i = 0; i < 4; ++i)
    {
        x = p[i] + r;
        y = q[i] + c;
        if(x >= 0 && x < h && y >= 0 && y < l && arr[x][y] == '*')
        {
            if(!visit[x][y])
            {
                visit[x][y] = 1;
                if(match[x][y][0] == -1 || bpm(match[x][y][1], match[x][y][2]))
                {
                    match[x][y][0] = 1;
                    match[x][y][1] = r;
                    match[x][y][2] = c;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &h, &l);

        for(i = 0; i < h; ++i)
            scanf("%s", arr[i]);

        even = odd = 0;
        memset(match, - 1, sizeof(match));
        for(i = 0; i < h; ++i)
        {
            for(j = 0; j < l; ++j)
            {
                if(arr[i][j] == '*')
                {
                    memset(visit, 0, sizeof(visit));
                    if(bpm(i, j))
                        ++even;
                    else
                        ++odd;
                }
            }
        }

        printf("%d\n", even / 2 + odd, even, odd);
    }
    return 0;
}

