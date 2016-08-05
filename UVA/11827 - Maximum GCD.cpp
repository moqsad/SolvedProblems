#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

int arr[110];
char letter[1000000], ch[20];

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
    int i, j, k, n, x, cnt, total;
    scanf("%d\n", &n);
    for(cnt = 0; cnt < n; ++cnt)
    {
        total = 1;
        gets(letter);
        x = strlen(letter);
        k = 0;
        j = 0;
        for(i = 0; i < x; ++i)
        {
            if(isdigit(letter[i]))
            {
                while(isdigit(letter[i]))
                ch[j++] = letter[i++];
                ch[j] = '\0';
                arr[++k] = atoi(ch);
                j = 0;
            }
        }
        i = k;
        for(j = 1; j < i; ++j)
            for(k = j + 1; k <= i; ++k)
            {
                x = gcd(arr[j], arr[k]);
                if(x > total)
                    total = x;
            }
        printf("%d\n", total);
    }
    return 0;
}
