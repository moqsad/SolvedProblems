#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char arr[10];

#include <deque>

deque <int> d;

int main()
{
    int t, cnt, i, n, m, a;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        printf("Case %d:\n", cnt);
        for(i = 0; i < m; ++i)
        {
            scanf("%s", arr);

            if(strcmp(arr, "pushLeft") == 0)
            {
                scanf("%d", &a);
                if(d.size() == n)
                    printf("The queue is full\n");
                else
                {
                    d.push_front(a);
                    printf("Pushed in left: %d\n", a);
                }
            }

            else if(strcmp(arr, "pushRight") == 0)
            {
                scanf("%d", &a);
                if(d.size() == n)
                    printf("The queue is full\n");
                else
                {
                    d.push_back(a);
                    printf("Pushed in right: %d\n", a);
                }
            }

            else if(strcmp(arr, "popLeft") == 0)
            {
                if(d.size() == 0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from left: %d\n", d.front());
                    d.pop_front();
                }
            }

            else
            {
                if(d.size() == 0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from right: %d\n", d.back());
                    d.pop_back();
                }
            }
        }
        while(!d.empty())
            d.pop_back();
    }
    return 0;
}
