#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int x, y;
char a[110], b[110], arr[5];
string dp[102][102], s;

string lcs(int a1, int b1)
{
    if(a1 == x || b1 == y)
        return "}";

    if(dp[a1][b1] != "*")
        return dp[a1][b1];

    string x, y, z;
    if(a[a1] == b[b1])
    {
        arr[0] = a[a1];
        arr[1] = '\0';
        z = arr;
        x = lcs(a1 + 1, b1 + 1);
        if(x != "}")
        {
            return dp[a1][b1] = z + x;
        }
        else
        {
            return dp[a1][b1] = z;
        }
    }
    else
    {
        x = lcs(a1, b1 + 1);
        y = lcs(a1 + 1, b1);
        if(x.size() > y.size())
            return dp[a1][b1] = x;
        else if(x.size() < y.size())
            return dp[a1][b1] = y;
        else
        {
            if(x < y)
                return dp[a1][b1] = x;
            else
                return dp[a1][b1] = y;
        }
    }
}

int main()
{
    int t, cnt, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %s", a, b);
        x = strlen(a);
        y = strlen(b);
        for(i = 0; i < x; ++i)
            for(j = 0; j < y; ++j)
                dp[i][j] = "*";
        s = lcs(0, 0);
        if(s != "}")
            cout << "Case " << cnt <<": " << s << "\n";
        else
            cout << "Case " << cnt <<": :(\n";
    }
    return 0;
}

/*
10
abcd
cdab
*/
