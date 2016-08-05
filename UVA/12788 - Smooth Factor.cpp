#include <cstdio>
#include <iostream>
using namespace std;

int arr[100010];

int main()
{
    int t, b1, b2, i, n, max_, ind, x;
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        max_ = 0;
        b1 = n - 1;
        b2 = -1;
        for(i = n - 1; i > 0; --i)
            if(arr[i] < arr[i - 1])
            {
                if(b2 == -1)
                    b2 = i - 1;

                else
                {
                    max_ = max(max_, b1 - i + 1);
                    b1 = b2;
                    b2 = i - 1;
                }
            }

        max_ = max(max_, b1  + 1);
        printf("%d\n", max_);
    }
    return 0;
}
