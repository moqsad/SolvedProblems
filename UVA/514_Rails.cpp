#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int arr[1010];

int main()
{
    int i = 0, j, n, cnt, p;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        cnt = 0;
        while(scanf("%d", &arr[++cnt]) == 1)
        {
            if(arr[cnt] == 0)
                break;
            if(cnt == n)
            {
                stack <int> S;
                j = n;
                while(cnt > 0)
                {
                    S.push(arr[cnt--]);
                    if(S.top() == j)
                    {
                        S.pop();
                        --j;
                        while(!S.empty() && S.top() == j)
                        {
                            S.pop();
                            --j;
                        }
                    }
                }
                p = 1;
                while(!S.empty())
                {
                    if(S.top() != j)
                    {
                        p = 0;
                        break;
                    }
                    else
                    {
                        S.pop();
                        --j;
                    }
                }
                if(p == 1)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}
//3 2 1 6 5 4
