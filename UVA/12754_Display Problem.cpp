#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cnt = 0, p = 1, i, d, t, case_, x;
    char arr[50];
    scanf("%d", &t);
    getchar();
    for(case_ = 1; case_ <= t; ++case_)
    {
        while(gets(arr))
        {
            x= strlen(arr);

            for(i = 0; i < x; ++i)
                if(arr[i] == '*')
                    break;

            if(i < x)
                break;

            if(cnt > 2 * d+ 2)
                p = 0;

            if(cnt == 0)
            {
                if(x > 1  && arr[0] == '.' && arr[x - 1] == '.')
                {
//                    printf("%s>>>>>>\n", arr);
                    for(i = 1; i < x - 1; ++i)
                        if(arr[i] != '-')
                        {
                            p = 0;
                            break;
                        }

                    if(p == 1)
                        d = x  - 2;
                }
                else
                    p = 0;
            }

            else if(p == 1)
            {
                if(cnt != d + 1 && cnt != 2 * d + 2)
                {
//                    printf("%s+++++\n", arr);
                    if(x == d + 2  && arr[0] == '|' && arr[x - 1] == '|')
                    {
                        for(i = 1; i < x - 1; ++i)
                            if(arr[i] != '.')
                            {
                                p = 0;
                                break;
                            }
                    }
                    else
                        p = 0;
                }

                else
                {
//                    printf("%s________\n", arr);
                    if(x == d + 2  && arr[0] == '.' && arr[x - 1] == '.')
                    {
                        for(i = 1; i < x - 1; ++i)
                            if(arr[i] != '-')
                            {
                                p = 0;
                                break;
                            }
                    }
                    else
                        p = 0;
                }
            }
            ++cnt;
        }

        if(cnt == 0 || cnt < 2 * d + 3)
            p = 0;

        if(p == 0)
            printf("Case %d: Bad\n", case_);
        else
            printf("Case %d: %d\n", case_, d);
        cnt = 0;
        p = 1;
    }
    return 0;
}
