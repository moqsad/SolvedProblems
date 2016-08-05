#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n, pd, pm, py, pc, d, m, y, c, i, ans, cnt;
    while(scanf("%d", &n) == 1 && n)
    {
        scanf("%d %d %d %d", &pd, &pm, &py, &pc);
        cnt = ans = 0;
        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d %d", &d, &m, &y, &c);

            if(d > 1)
            {
                if(d - pd == 1 && m == pm && y == py)
                    ans += c - pc, ++cnt;
            }

            else
            {
                if(m == 1)
                {
                    if(pd == 31 && pm == 12 && y == py + 1)
                        ans += c - pc, ++cnt;
                }


                else if(m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11)
                {
                    if(pd == 31 && m == pm + 1 && y == py)
                        ans += c - pc, ++cnt;
                }


                else if(m == 5 || m == 7 || m == 10 || m == 12)
                {
                    if(pd == 30 && m == pm + 1 && y == py)
                        ans += c - pc, ++cnt;
                }


                else if(m == pm + 1 && y == py)
                {
                    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                    {
                        if(pd == 29)
                            ans += c - pc, ++cnt;
                    }

                    else if(pd == 28)
                        ans += c - pc, ++cnt;
                }
            }

            pd = d, pm = m, py = y, pc = c;
        }
        printf("%d %d\n", cnt, ans);
    }
    return 0;
}

