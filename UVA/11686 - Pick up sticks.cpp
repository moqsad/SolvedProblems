#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define M 1001000
vector<int> depends[M];
int taken[M], visited[M], cycle, ans[M], k;
//vector<int> edge[M];

//depends[i] contains all the items that item i is depending on
//when taken[i] = 1, that means it's already taken

void visit(int p)
{
    int i, x;
    if(visited[p] == 2 || cycle)
        return;
    // we won't process anything if we already have found a cycle
    if(visited[p] == 1)
    {
        cycle = 1; // found cycle
        return;
    }
    x = depends[p].size();
    visited[p] = 1;
    for(int i=0; i<x; i++)
    {
        visit(depends[p][i]);
    }
    visited[p] = 2;
}

void take(int p)
{
    int x, i;
    if(!taken[p])
    {
        // i am taking all the items that i should take before p
        x = depends[p].size();
        for(int i=0; i<x; i++)
            take(depends[p][i]);
        ans[k++] = p; // now i can take it
        taken[p] = 1;
    }
}

int main()
{
    // input routine
    // .....
    int i, n, m, a, b;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(m == 0 && n == 0)
            break;
        memset(taken, 0, sizeof(taken));
        memset(visited, 0, sizeof(visited));
        cycle = 0;
        k = 0;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            depends[b].push_back(a);
        }
        for(int i=1; i<=n; i++)
        {
            visit(i);
            if(cycle == 1)
                break;
            //printf("++++++++++++++\n");
            take(i);
            //depends[i].clear();
        }
        //printf("%d__________\n", i);
        if(cycle == 0)
            for(i = 0; i < n; ++i)
            {
                printf("%d\n", ans[i]);
            }
        else
        {
            printf("IMPOSSIBLE\n");
        }
        for(i = 1; i <= n; ++i)
        {
            depends[i].clear();
        }
    }
    return 0;
}

/*
2 2
1 2
2 1
3 2
1 2
2 3
*/
