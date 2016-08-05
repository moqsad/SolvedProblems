#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int total, limit, ans[30], taken[30], n, m, arr[30], p;

vector <int> result;

void call(int j)
{
    int i, x, sum;
    x = result.size();
    sum = 0;
    for(i = 0; i < x; ++i)
        sum += result[i];
    if(sum <= n && n - sum < total)
    {
        total = n - sum;
        for(i = 0; i < x; ++i)
            ans[i] = result[i];
        limit = x;
    }

    for(i = j + 1; i < m; ++i)
    {
        result.push_back(arr[i]);

        call(i);

        result.pop_back();
    }
}


int main()
{
    int i, sum;
    while(scanf("%d", &n) == 1)
    {
        scanf("%d", &m);
        for(i = 0; i < m; ++i)
            scanf("%d", &arr[i]);
        total = 1000000;
        p = m - 1;
        call(-1);
        sum = 0;
        for(i = 0; i < limit; ++i)
        {
            printf("%d ", ans[i]);
            sum += ans[i];
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}

/*
200 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
