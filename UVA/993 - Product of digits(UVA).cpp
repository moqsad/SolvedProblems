#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int prime[] = {2, 3, 5, 7};
int value[10], temp[10];

string s, ans;

char arr[50];

int main()
{
    int t, cnt, n, i, j, k, l, min_;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        if(n > 1)
        {
            ans = "999999999999999999999999999999999999999999999999999999999999";

            memset(value, 0, sizeof(value));
            memset(temp, 0, sizeof(temp));

            for(i = 0; i < 4; ++i)
            {
                while(n % prime[i] == 0)
                {
                    n /= prime[i];
                    ++value[prime[i]];
                }
            }

            if(n == 1)
            {
                min_ = min(value[2], value[3]);
//                printf("%d____________\n", min_);
                for(i = 0; i <= min_; ++i)
                {
                    for(j = 2; j < 10; ++j)
                        temp[j] = value[j];

                    temp[2] -= i;
                    temp[3] -= i;
                    temp[6] += i;

                    temp[8] = temp[2] / 3;
                    temp[2] %= 3;
                    temp[4] = temp[2] / 2;
                    temp[2] %= 2;

                    temp[9] = temp[3] / 2;
                    temp[3] %= 2;

                    l = 0;
                    for(j = 2; j < 10; ++j)
                    {
                        for(k = 1; k <= temp[j]; ++k)
                            arr[l++] = j + 48;
                    }

                    arr[l] = '\0';
                    s = arr;
                    if(s.size() < ans.size())
                        ans = s;
                    else if(s.size() == ans.size() && s < ans)
                        ans = s;
                }

                cout << ans << "\n";
            }

            else
                printf("-1\n");
        }

        else
            printf("%d\n", n);
    }
    return 0;
}
