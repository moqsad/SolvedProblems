#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector <int> v[50];

map <char, int> mm;
map <int, int> nn;

int main()
{
    int n, m, i, j, k, l, x, y, p, q, num[50];
    char arr[10], two[10], ch;
    while(scanf("%d %d", &n, &m) == 2)
    {
        scanf("%s", arr);
        mm[arr[0]] = 1;
        mm[arr[1]] = 2;
        mm[arr[2]] = 3;
        nn[1] = 1;
        nn[2] = 1;
        nn[3] = 1;
        j = 3;
        for(i = 0; i < m; ++i)
        {
            scanf("%s", two);
            ch = two[0];
            if(mm.find(ch) == mm.end())
                mm[ch] = ++j;
            x = mm[ch];
            ch = two[1];
            if(mm.find(ch) == mm.end())
                mm[ch] = ++j;
            y = mm[ch];
            v[x].push_back(y);
            v[y].push_back(x);
        }

        k = 0;
        p = 1;
        q = 1;

        while(p == 1 && q == 1)
        {
            p = 0;
            q = 0;
            j = 0;
            for(i = 4; i <= n; ++i)
            {
                if(nn.find(i) == nn.end())
                {
                    p = 1;
                    x = v[i].size();
                    y = 0;
                    for(l = 0; l < x; ++l)
                    {
                        if(nn.find(v[i][l]) != nn.end())
                        {
                            ++y;
                            if(y == 3)
                            {
                                num[j++] = i;
                                q = 1;
                                break;
                            }
                        }
                    }
                }
            }
            ++k;
            for(l = 0; l < j; ++l)
            {
                nn[num[l]] = 1;
            }
        }

        p = 1;
        for(i = 1; i <= n; ++i)
        {
            if(nn.find(i) == nn.end())
                p = 0;
            v[i].clear();
        }
        if(p == 1)
            printf("WAKE UP IN, %d, YEARS\n", k - 1);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
        mm.clear();
        nn.clear();
    }
    return 0;
}
