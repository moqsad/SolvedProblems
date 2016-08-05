#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string a;
map <string, int> mm;
map <int, string> nn;
vector <int> take[110];
char arr[110], letter[110];
int ans[110], indegree[110];

int main()
{
    int i, j, k, m, n, cnt = 0, x, y;
    while(scanf("%d", &n) == 1)
    {
        memset(indegree, 0, sizeof(indegree));
        mm.clear();
        nn.clear();
        for(i = 1; i <= n; ++i)
        {
            scanf("%s", arr);
            a = arr;
            mm[a] = i;
            nn[i] = a;
        }
        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", arr, letter);
            take[mm[arr]].push_back(mm[letter]);
            ++indegree[mm[letter]];
        }
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
            {
                if( !indegree[j])
                {
                    --indegree[j];
                    ans[i] = j;
                    x = take[j].size();
                    for(k = 0; k < x; ++k)
                        --indegree[take[j][k]];
                    take[j].clear();
                    break;
                }
            }
        printf("Case #%d: Dilbert should drink beverages in this order:", ++cnt);
        for(j = 1; j <= n; ++j)
            cout << " " << nn[ans[j]];
        printf(".\n\n");
    }
    return 0;
}
