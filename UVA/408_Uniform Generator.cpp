#include <cstring>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    int r;
    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int x, a, b;
    while(scanf("%d %d", &a, &b) == 2)
    {
        x = gcd(a, b);
        if(x == 1)
            printf("%10d%10d    Good Choice\n\n", a, b);
        else
            printf("%10d%10d    Bad Choice\n\n", a, b);
    }
    return 0;
}
