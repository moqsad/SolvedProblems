#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int num[10], arr[] = {5, 10, 20, 50, 100, 200}, back_[300], ans[1000], temp[1000];

void func(void)
{
    int i, j, temp_;

    for(i = 5; i < 201; i += 5)
        back_[i] = 1000000000;

    for(i = 0; i < 6; ++i)
    {
        back_[arr[i]] = 1;
        for(j = arr[i] + 5; j < 201; j += 5)
        {
            temp_ = back_[j - arr[i]] + 1;
            if(temp_ < back_[j])
                back_[j] = temp_;
        }
    }
//    for(i = 0; i < 201; i += 5)
//        printf("__________%d\n", back_[i]);
}

int main()
{
    int i, j, k, x, y, z;
    char a[100];
    func();
    while(scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]) == 6)
    {
        if(num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0 && num[5] == 0)
            break;


        scanf("%s", &a);
        i = -1;
        x = 0;

        while(a[++i] != '.')
            x = x * 10 + (a[i] - 48);

        while(a[++i] != '\0')
            x = x * 10 + (a[i] - 48);

        y = x + 201;
//        printf("%d_________%d\n", x, y);
        for(i = 5; i < y; i += 5)
        {
            temp[i] = 1000000000;
            ans[i] = 1000000000;
        }

        for(i = 0; i < 6; ++i)
        {
            if(num[i] > 0)
            ans[arr[i]] = 1;
            for(j = 0; j < num[i]; ++j)
            {
                for(k = arr[i] + 5; k < y; k += 5)
                {
                    z = temp[k - arr[i]] + 1;
                    if(z < ans[k])
                        ans[k] = z;
                }

                for(k = 5; k < y; k += 5)
                    temp[k] = ans[k];
            }
        }
        z = 1000000000;
        for(i = x; i < y; i += 5)
        {
//            printf("%d_______%d\n", ans[i], back_[i - x]);
            if(ans[i] + back_[i - x] < z)
                z = ans[i] + back_[i - x];
        }
        printf("%3d\n", z);
    }
    return 0;
}
