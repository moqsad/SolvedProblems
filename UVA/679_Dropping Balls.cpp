#include <cstdio>

int arr[22][1100000], divide[25];

//int func(int beg, int endd, int search_)
//{
//    int mid;
//    mid = (beg + endd) / 2;
//    while(arr[mid] != search_)
//    {
//        //printf("******%d********\n", mid);
//        if(search_ < arr[mid])
//            beg = mid + 1;
//        else if(search_ > arr[mid])
//            endd = mid - 1;
//        else
//            return mid;
//        mid = (beg + endd) / 2;
//    }
//    return mid;
//}

int main()
{
    int x = 2, y, z, a, b, c, i, cnt, j, t;
    divide[1] = 1;
    divide[2] = 2;
    arr[1][1] = 1;
    arr[2][1] = 2;
    arr[2][2] = 3;
    for(cnt = 3; cnt < 21; ++cnt)
    {
        x *= 2;
        divide[cnt] = x;
        a = x / 2;
        b = a / 2;
        c = divide[cnt - 2];
        y = x / 4;
        j = 0;
        for(i = 1; i <= y; ++i)
        {
            z = x + arr[cnt - 2][i] - c;
//            printf("%d__%d_____%d_____%d*************\n", z, x, arr[cnt - 2][i], c);
            arr[cnt][++j] = z;
//            printf("%d__%d %d_\n", arr[cnt][j], cnt, j);
            arr[cnt][++j] = z + a;
//            printf("%d__%d %d_\n", arr[cnt][j], cnt, j);
            arr[cnt][++j] = z + b;
//            printf("%d__%d %d_\n", arr[cnt][j], cnt, j);
            arr[cnt][++j] = z + a + b;
//            printf("%d__%d %d_\n", arr[cnt][j], cnt, j);
        }
//        for(i = 1; i <= x; ++i)
//            printf("%d______________\n", arr[cnt][i]);
//        printf("\n\n\n\n");
    }
    while(scanf("%d", &t) == 1)
    {
        if(t < 0)
            break;
        for(cnt = 0; cnt < t; ++cnt)
        {
            scanf("%d %d", &a, &b);
            b = b % divide[a];
            if(b == 0)
                b = divide[a];
            printf("%d\n", arr[a][b]);
        }
    }
    return 0;
}
