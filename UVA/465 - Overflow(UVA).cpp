#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

char a[100000], b[100000], new_a[100000], new_b[100000], o;

int main()
{
    long long i, j, x;

    while(scanf("%s %c %s", a, &o, b) == 3)
    {
        printf("%s %c %s\n", a, o, b);

        i = 0;
        while(a[i++] == '0');
        x = strlen(a);
        if(i > x)
        {
            new_a[0] = '0';
            new_a[1] = '\0';
        }
        else
        {
            j = 0;
            for(i = i - 1; i < x; ++i)
                new_a[j++] = a[i];
            new_a[j] = '\0';
        }


        i = 0;
        while(b[i++] == '0');
        x = strlen(b);
        if(i > x)
        {
            new_b[0] = '0';
            new_b[1] = '\0';
        }
        else
        {
            j = 0;
            for(i = i - 1; i < x; ++i)
                new_b[j++] = b[i];
            new_b[j] = '\0';
        }
//        printf("%s %s ---> \n", new_a, new_b);
        if(strlen(new_a) > 10 || atol(new_a) > 2147483647)
            printf("first number too big\n");
        if(strlen(new_b) > 10 || atol(new_b) > 2147483647)
            printf("second number too big\n");
        if(o == '+')
        {
            if(strlen(new_a) > 10 || strlen(new_b) > 10 || (atol(new_a) + atol(new_b) > 2147483647))
                printf("result too big\n");
        }
        else
        {
            if(strcmp(new_a, "0") && strcmp(new_b, "0"))
            {
                if(strlen(new_a) + strlen(new_b) > 11 || (atol(new_a) * atol(new_b) > 2147483647))
                printf("result too big\n");
            }
        }
    }

    return 0;
}
/*
00000000234324 * 34534534534
*/
