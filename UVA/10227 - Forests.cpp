#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector <int> v[110];
char arr[20], a[10], b[10];
map <int, int> mm;
map <int, int> nn;

int main()
{
    int t, cnt, x, y, z, i, j, k, p, n, ans;
    FILE *pt;
//    pt = freopen("F:\\input.txt", "r", stdin);
    scanf("%d\n", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        scanf("%d %d", &p, &t);
        getchar();

        mm.clear();
        nn.clear();
        ans = 0;
        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            sscanf(arr, "%s %s", a, b);
            x = atoi(a);
            y = atoi(b);
            z = 1000 * x + y;
            if(nn.find(z) == nn.end())
            {
                v[x].push_back(y);
                nn[z] = 1;
            }
        }
        for(i = 1; i <= p; ++i)
        {
            sort(v[i].begin(), v[i].end());
        }
        for(i = 1; i <= p; ++i)
        {
            if(mm.find(i) == mm.end())
            {
                ++ans;
                mm[i] = 1;
                for(j = i + 1; j <= p; ++j)
                {
                    if(mm.find(j) == mm.end())
                    {
                        x = v[i].size();
                        y = v[j].size();
                        if(x == y)
                        {
                            for(k = 0; k < x; ++k)
                            {
                                if(v[i][k] != v[j][k])
                                    break;
                            }
                            if(k == x)
                            {
                                mm[j] = 1;
                            }
                        }
                    }
                }
            }
            v[i].clear();
        }
        printf("%d\n", ans);
        if(cnt < n)
            printf("\n");
    }
//    fclose(FILE);
    return 0;
}
// freopen("H:\\C_Codes\\input.txt","r",stdin);
