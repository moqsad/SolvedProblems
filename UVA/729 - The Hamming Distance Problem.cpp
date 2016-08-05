#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int h, n, taken[25], j;
string ans[13000];
char arr[20];

void backtrack(int x, int nea)
{
//    printf("+++++++++++++++%d\n", nea);
    int i;
    if(nea == h)
    {
        for(i = 1; i <= n; ++i)
        {
            arr[i - 1] = taken[i] + 48;
        }
        arr[i-1] = '\0';
        ans[j] = arr;
//        cout << ans[j] << "______\n";
        ++j;
        return ;
    }

    for(i = x; i > 0; --i)
    {
        taken[i] = 1;
        backtrack(i - 1, nea + 1);
        taken[i] = 0;
    }
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &h);
        j = 0;
        backtrack(n, 0);
        sort(ans, ans + j);
        for(i = 0; i < j; ++i)
        {
            cout << ans[i] << "\n";
        }
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
