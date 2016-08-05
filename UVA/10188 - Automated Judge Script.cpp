#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

char in[125], out[125];

string a, b;
char c[12005], d[12005];

int main()
{
    int n, m, i, j, z, cnt  = 0;
    while(scanf("%d",&n) == 1)
    {
        if(n == 0)
            break;
//        scanf("\n");
        getchar();


        a = "";
        b = "";

        for(i = 1; i <= n; ++i)
        {
            gets(out);
            a = a + "#" + out;
        }

        scanf("%d", &m);
//        scanf("\n");
        getchar();

        for(i = 1; i <= m; ++i)
        {
            gets(in);
            b = b + "#" + in;
        }

        if(a == b)
            printf("Run #%d: Accepted\n", ++cnt);

        else
        {
            j = 0;
            for(i = 0; i < a.size(); ++i)
            {
                if(a[i] >= '0' && a[i] <= '9')
                    c[j++] = a[i];
            }
            c[j] = '\0';

            j = 0;
            for(i = 0; i < b.size(); ++i)
            {
                if(b[i] >= '0' && b[i] <= '9')
                    d[j++] = b[i];
            }
            d[j] = '\0';
//            cout << d << " " << strlen(d) << "\n";

            if(strcmp(c, d) == 0)
                printf("Run #%d: Presentation Error\n", ++cnt);
            else
                printf("Run #%d: Wrong Answer\n", ++cnt);
        }
//        printf("%d %d------\n", n, m);
    }
    return 0;
}
/*
2
123
456
2
12
3456
0
*/
