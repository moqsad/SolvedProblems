#include <cstdio>
using namespace std;

char arr[5];

int main()
{
    int n, i, j, total;
    scanf("%d", &n);
    for(i = 0; i < n; ++i)
    {
        total = 0;
        for(j = 0; j < 4; ++j)
        {
            scanf("%s", arr);
            total += arr[1] - 48 + arr[3] - 48;
            total += ((arr[0] - 48) * 2) % 10 + ((arr[0] - 48) * 2) / 10;
            total += ((arr[2] - 48) * 2) % 10 + ((arr[2] - 48) * 2) / 10;
        }
//        printf("%d___\n", total);
        if(total % 10)
            printf("Invalid\n");
        else
            printf("Valid\n");
    }
    return 0;
}
