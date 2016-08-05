#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, day1, day2, year1, year2, x, y, z, ans;
    char first[15], second[15];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %d, %d", first, &day1, &year1);
        scanf("%s %d, %d", second, &day2, &year2);
        x = year1 - 1;
        y = (x / 4) - x / 100 + x / 400;
        z = (year2 / 4) - year2 / 100 + year2 / 400;
        ans = z - y;

        if((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)
        {
            if(strcmp("January", first) != 0 && strcmp("February", first) != 0)
                --ans;
        }

        if((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)
        {
            if(strcmp("January", second) == 0 || (strcmp("February", second) == 0 && day2 != 29))
                --ans;
        }

        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}

