#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cstring>
#include <cstdio>
using namespace std;

long long ans[350], ans_2[350][350], num[5];
char arr[100];

void func(long long x)
{
    long long i, j, k;
    memset(ans_2, 0, sizeof(ans_2));
    ans_2[0][0] = 1;
    for(i = 1; i <= x; ++i)
    {
        ans_2[i][1] = 1;
        for(j = i + 1; j <= x; ++j)
        {
            for(k = 2; k <= x; ++k)
                ans_2[j][k] = ans_2[j][k] + ans_2[j - i][k - 1];
        }
    }
}

int main()
{
    long long i, j, total;

//    func(300);

    while(gets(arr))
    {
        stringstream sin (arr);
        i = 0;

        while(sin >> num[i++]);

        --i;

        if(i == 1)
        {
            memset(ans, 0, sizeof(ans));
            ans[0] = 1;
            for(i = 1; i <= num[0]; ++i)
                for(j = i; j <= num[0]; ++j)
                    ans[j] = ans[j] + ans[j - i];
            printf("%lld\n", ans[num[0]]);
        }

        else
        {
            func(num[0]);
            if(i == 2)
            {
                if(num[1] > num[0])
                    num[1] = num[0];
                total = 0;
                for(i = 0; i <= num[1]; ++i)
                    total += ans_2[num[0]][i];
                printf("%lld\n", total);
            }

            else
            {
                total = 0;
                if(num[1] <= num[0])
                {
                    if(num[2] > num[0])
                        num[2] = num[0];
                    for(i = num[1]; i <= num[2]; ++i)
                        total += ans_2[num[0]][i];
                }
                printf("%lld\n", total);
            }
        }
    }
    return 0;
}
