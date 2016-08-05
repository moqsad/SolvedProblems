#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string a, b, x;
int f[2000010]; // pattern && text er sum onusare f arrer man bosbe.............

int main()
{
    int i, n, m, k, ans, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        cin >> a >> b;
        x = b + "#" + a;
//        cout << x << "\n";
        n = b.size();
        m = x.size();
        k = 0;
        ans = 0;
        for(i = 1; i < m; ++i)
        {
            while(k > 0 && x[i] != x[k])
            {
                k = f[k - 1];
            }

            if(x[i] == x[k])
                ++k;

            if(k == n)
                ++ans;
            f[i] = k;
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}


