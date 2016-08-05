#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> node;

int main()
{
    int n, q, t, cnt, i, x;
    char ch;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            node.push_back(x);
        }

        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf(" %c %d", &ch, &x);
            if(ch == 'c')
            {
                if(x <= node.size())
                {
                    printf("%d\n", node[x - 1]);
                    node.erase(node.begin() + x - 1);
                }
                else
                    printf("none\n");
            }

            else
                node.push_back(x);
        }
        node.clear();
    }
    return 0;
}
