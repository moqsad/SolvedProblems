#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

/*TLE*/

map <string, int> mm;

char arr[105], line[10010];

int main()
{
    int t, cnt, i, n, x, m, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr);
            x = strlen(arr);
            if(x > 2)
                sort(arr + 1, arr + x - 1);
            if(mm.find(arr) == mm.end())
                mm[arr] = 1;
            else
                ++mm[arr];
        }

        scanf("%d", &m);
        printf("Case %d:\n", cnt);
        getchar();
        for(i = 0; i < m; ++i)
        {
            ans = 1;
            gets(line);
            stringstream sin (line);
//            cout << line << "\n";
            while(sin >> arr)
            {
                x = strlen(arr);
                if(x > 2)
                    sort(arr + 1, arr + x - 1);
                if(mm.find(arr) != mm.end())
                    ans *= mm[arr];
                else
                {
                    ans = 0;
                    break;
                }
            }
            if(strlen(line) == 0)
                ans = 1;
            printf("%d\n", ans);
        }

        mm.clear();
    }
    return 0;
}

/*
1
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
*/
