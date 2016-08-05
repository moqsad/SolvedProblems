#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

char arr[20];
int num[4];
map <char, int> mm;

int main()
{
    int t, cnt, n, i;
    mm['B'] = 0;
    mm['W'] = 1;
    mm['A'] = 2;
    mm['T'] = 3;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        scanf("%s", arr);
        for(i = 0; i < n; ++i)
            ++num[mm[arr[i]]];
        if(num[0] > 0 && num[3] == 0 && num[1] == 0)
            printf("Case %d: BANGLAWASH\n", cnt);
        else if(num[1] > 0 && num[3] == 0 && num[0] == 0)
            printf("Case %d: WHITEWASH\n", cnt);
        else if(num[0] == 0 && num[1] == 0 && num[3] == 0)
            printf("Case %d: ABANDONED\n", cnt);
        else if(num[0] == num[1])
            printf("Case %d: DRAW %d %d\n", cnt, num[0], num[3]);
        else if(num[0] > num[1])
            printf("Case %d: BANGLADESH %d - %d\n", cnt, num[0], num[1]);
        else
            printf("Case %d: WWW %d - %d\n", cnt, num[1], num[0]);
        num[0] = num[1] = num[2] = num[3] = 0;
    }
    return 0;
}
