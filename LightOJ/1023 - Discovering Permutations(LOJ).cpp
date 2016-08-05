#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int take[30], n, k, j, arr[30];

vector <int> result;

void backtrack(void)
{
    int i;
    if(result.size() == n)
    {
        for(i = 0; i < n; ++i)
            printf("%c", arr[result[i]]);
        printf("\n");
        ++j;
        return ;
    }

    for(i = 0; i < n; ++i)
    {
        if(take[i] == 0)
        {
            take[i] = 1;
            result.push_back(i);
            backtrack();
            take[i] = 0;
            result.pop_back();
            if(k == j)
                return ;
        }
    }
}

int main()
{
    int t, cnt, i;
        char ch = 'A';
    for(i = 0; i < 26; ++i)
        arr[i] = ch++;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d:\n", cnt);
        j = 0;
        backtrack();
    }
    return 0;
}
