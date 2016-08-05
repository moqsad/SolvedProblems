#include <stdio.h>

int arr[400][10];

int main()
{
    int a, cnt, i, ans[800], x, y, tag;
    i = 1;
    ans[0] = 1;
    for(cnt = 1; cnt <= 367; ++cnt)
    {
        x = 0;
        tag = i;
        for(i = 0; i < tag; ++i)
        {
            y = ans[i] * cnt + x;
            ans[i] = y % 10;
            x = y / 10;
            ++arr[cnt][ans[i]];
        }
        while(x != 0)
        {
            ans[i] = x % 10;
            x /= 10;
            ++arr[cnt][ans[i]];
            ++i;
        }
    }
    while(1)
    {
        scanf("%d", &a);
        if(a == 0)
            break;
        printf("%d! --\n   ", a);
        for(cnt = 0; cnt < 4; ++cnt)
        {
            printf("(%d)%5d    ", cnt, arr[a][cnt]);
        }
        printf("(%d)%5d\n   ", cnt, arr[a][cnt]);
        for(cnt = 5; cnt < 9; ++cnt)
        {
            printf("(%d)%5d    ", cnt, arr[a][cnt]);
        }
        printf("(%d)%5d\n", cnt, arr[a][cnt]);
    }
    return 0;
}
