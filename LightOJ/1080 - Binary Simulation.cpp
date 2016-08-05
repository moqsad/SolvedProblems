#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char type, arr[100010];
int x, y, prop[500010];

void update(int node, int s, int e)
{
    if(s >= x && e <= y)
    {
        if(prop[node] == 0)
            prop[node] = 1;
        else
            prop[node] = 0;

        return ;
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(mid + 1 > y)
        update(left, s, mid);

    else if(mid < x)
        update(right, mid + 1, e);

    else
    {
        update(left, s, mid);
        update(right, mid + 1, e);
    }
}

int query(int node, int s, int e)
{
    if(s == e)
        return prop[node];

    int  mid = (s + e) / 2, left = node * 2, right = 2 * node + 1;

    if(mid + 1 > x)
        return prop[node] + query(left, s, mid);

    return prop[node] + query(right, mid + 1, e);
}

int main()
{
    int t, cnt, i, ans, n, q;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        printf("Case %d:\n", cnt);

        memset(prop, 0, sizeof(prop));
        scanf("%s", arr);

        n = strlen(arr);

        scanf("%d", &q);

        for(i = 0; i < q; ++i)
        {
            scanf(" %c", &type);

            if(type == 'I')
            {
                scanf("%d %d", &x, &y);
                update(1, 1, n);
            }

            else
            {
                scanf("%d", &x);
                ans = query(1, 1, n);
                if(ans % 2 == 1)
                {
                    if(arr[x - 1] == '0')
                        printf("1\n");
                    else
                        printf("0\n");
                }

                else
                    printf("%c\n", arr[x - 1]);
            }
        }
    }
    return 0;
}
