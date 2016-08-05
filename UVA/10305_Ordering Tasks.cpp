#include <cstring>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int indegree[110], store[110], store2[110];
vector <int> v[110];

int main()
{
    int n, m, i, j, k, l, a, b, x, y, cnt;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(m == 0 && n == 0)
            break;
        cnt = 0;
        memset(indegree, 0, sizeof(indegree));
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            ++indegree[b];
        }
        j = 0;
        for(i = 1; i <= n; ++i)
            if(indegree[i] == 0)
            {
                store[j++] = i;
                ++cnt;
                if(cnt < n)
                    printf("%d ", i);
                else
                    printf("%d\n", i);
            }
        while(cnt < n)
        {
            l = 0;
            for(i = 0; i < j; ++i)
            {
                x = v[store[i]].size();
                for(k = 0; k < x; ++k)
                {
                    y = v[store[i]][k];
                    --indegree[y];
                    if(indegree[y] == 0)
                    {
                        store2[l++] = y;
                        ++cnt;
                        if(cnt < n)
                            printf("%d ", y);
                        else
                        {
                            printf("%d\n", y);
                            break;
                        }
                    }
                }
                if(cnt == n)
                    break;
            }
            for(j = 0; j < l; ++j)
            store[j] = store2[j];
        }
        for(i = 1; i <= n; ++i)
            v[i].clear();
    }
    return 0;
}
