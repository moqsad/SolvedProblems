#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int arr[1000010];

int main()
{
    int i, n, x, y, z;
    double j;
    arr[0] = 1;
    for(i = 1; i <= 1000000; ++i)
    {
        j = i;
        x = j - sqrt(j);
        y = log(j);
        z = j * (sin(j) * sin(j));
        arr[i] = (arr[x] + arr[y] + arr[z]) % 1000000;
    }

    while(scanf("%d", &n) == 1)
    {
        if(n==-1)
            break;
        printf("%d\n", arr[n]);
    }
    return 0;
}
