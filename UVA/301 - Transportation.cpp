#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int start[30], finish[30], passen[30], present[30], train, pass, order, total, sum;

void backtrack(int i, int sum)
{
    int j, k, p;
    if(total < sum)
        total = sum;

    if(i == order)
        return ;

    for(j = i; j < order; ++j)
    {
        p = 1;
        for(k = start[j]; k < finish[j]; ++k)
        {
            present[k] += passen[j];
            if(present[k] > pass)
                p = 0;
        }

        if(p == 1)
            backtrack(j + 1, sum + (finish[j] - start[j]) * passen[j]);

        for(k = start[j]; k < finish[j]; ++k)
            present[k] -= passen[j];
    }
}

int main()
{
    int i;
    while(scanf("%d %d %d", &pass, &train, &order))
    {
        if(pass == 0 && train == 0 && order == 0)
            break;

        for(i = 0; i < order; ++i)
        {
            scanf("%d %d %d", &start[i], &finish[i], &passen[i]);
        }

        total = 0;
        backtrack(0, 0);
        printf("%d\n", total);
    }
    return 0;
}
