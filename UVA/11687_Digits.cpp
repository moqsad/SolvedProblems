#include <cstdio>
#include <cstring>
using namespace std;

char arr[1010000];

int main()
{
    int x, y, z, i;
    while(scanf("%s", arr) == 1)
    {
        if(strcmp("END", arr) == 0)
            break;
        if(strcmp("1", arr) == 0)
            printf("1\n");
        else
        {
            x = strlen(arr);
            z = x;
            y = 0;
            i = 2;
            while(z > 0)
            {
                z /= 10;
                ++y;
            }
            while(x != y)
            {
                ++i;
                x = y;
                z = x;
                y = 0;
                while(z > 0)
                {
                    z /= 10;
                    ++y;
                }
            }
            printf("%d\n", i);
        }
    }
    return 0;
}
