#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char m[110], n[110];
    int num[15][10], length[15], i, j, x, y, p;
    for(i = 1; i < 10; ++i)
    {
        num[i][1] =i;
        length[i] = 1;
        j = 1;
        x = i;
        x = (x * i) % 10;
        while(x != num[i][1])
        {
            num[i][++j] = x;
            ++length[i];
            x = (x * i) % 10;
        }
    }
    while(scanf("%s %s", m, n) == 2)
    {
        if(m[0] == '0' && n[0] == '0')
            break;
        x = m[strlen(m) - 1] - 48;
        y = n[strlen(n) - 1] - 48;
        if(strlen(n) > 1)
        {
            y += (n[strlen(n) - 2] - 48) * 10;
            if(y == 0 && strlen(n) > 2)
            y = 4;
        }
        if(x == 0)
            printf("0\n");
        else if(y == 0)
            printf("1\n");
        else
        {
            p = y % length[x];
            if(p == 0)
                p = length[x];
            printf("%d\n", num[x][p]);
        }
    }
    return 0;
}
