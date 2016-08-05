#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int x, n;
int prime[34], taken[20];

vector <int> result;

void call(void)
{
    int i, y;
    if(result.size() == n)
    {
        if(prime[1 + result[x]] == 1)
        {
            printf("1");
            for(i = 1; i < n; ++i)
                printf(" %d", result[i]);
            printf("\n");
        }
        return ;
    }

    for(i = 2; i <= n; ++i)
    {
        if(taken[i] == 0)
        {
//            printf("%d__________%d__________%d___________\n", i, result[result.size() - 1], result.size());
            if(prime[i + result[result.size() - 1]] == 1)
            {
                result.push_back(i);
//                printf("%d*****************\n", result.size());
                taken[i] = 1;
                call();
                taken[i] = 0;
                result.pop_back();
            }
        }
    }
}

int main()
{
    int cnt = 0, i;
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] =
                                         prime[19] = prime[23] = prime[29] = prime[31] = prime[37] = 1;
    result.push_back(1);
    while(scanf("%d", &n) == 1)
    {
        if(cnt > 0)
            printf("\n");
        printf("Case %d:\n", ++cnt);
        x = n - 1;
        call();
    }
    return 0;
}
