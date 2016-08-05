#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector <int> vec[1000010];

int main()
{
    int n, m, i, a, k, v;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            vec[a].push_back(i);
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &k, &v);
            if(vec[v].size() >= k)
                printf("%d\n", vec[v][k - 1]);
            else
                printf("0\n");
        }

        for(i = 1; i <= n; ++i)
            vec[i].clear();
    }
    return 0;
}

