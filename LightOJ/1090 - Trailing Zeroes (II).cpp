#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int func(int data, int d)
{
    int sum = 0;
    while(data / d > 0)
    {
        sum += data /d;
        data /= d;
    }
    return sum;
}

int main()
{
    int t, cnt, n, r, p, q, two, five, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        two = five = 0;
        scanf("%d %d %d %d", &n, &r, &p, &q);

        while(p % 2 == 0)
        {
            ++two;
            p /= 2;
        }
        two *= q;

        while(p % 5 == 0)
        {
            ++five;
            p /= 5;
        }
        five *= q;

//        printf("%d %d_________\n", two, five);

        two += func(n, 2);
        two -= func(r, 2);
        two -= func(n - r, 2);

        five += func(n, 5);
        five -= func(r, 5);
        five -= func(n - r, 5);

        printf("Case %d: %d\n", cnt, min(two, five));
    }
    return 0;
}
