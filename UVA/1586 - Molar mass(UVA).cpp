#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, i, j;
    char arr[100], ch;
    double num[100], ans;
    num['C'] = 12.01, num['H'] = 1.008, num['O'] = 16.00, num['N'] = 14.01;

    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%s", arr);
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            ch = arr[i];
            j = 1;
            if(arr[i+1] >= '0' && arr[i+1] <= '9')
            {
                j = arr[i + 1] - 48;
                ++i;
                if(i + 1 < x && arr[i+1] >= '0' && arr[i+1] <= '9')
                {
                    j = j * 10 + arr[i + 1] - 48;
                    ++i;
                }
            }
//            printf("%d %d_____%c\n", i, j, ch);
            ans += num[ch] * j;
        }

        printf("%.3lf\n", ans);
    }
    return 0;
}
