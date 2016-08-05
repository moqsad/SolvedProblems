#include "bits/stdc++.h"
using namespace std;

char arr[110][60], temp[60];

int main()
{
    int n, x, y, cnt, i, j, k, z;
    while(scanf("%d", &n) == 1)
    {
        for(cnt = 0; cnt < 60; ++cnt)
            printf("-");
        printf("\n");
        scanf("%s", arr[0]);
        x = strlen(arr[0]);
        for(cnt = 1; cnt < n; ++cnt)
        {
            scanf("%s", arr[cnt]);
            y = strlen(arr[cnt]);
            if(y > x)
                x = y;
        }
        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
            {
                if(strcmp(arr[i], arr[j]) > 0)
                {
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }

        y = 60 - x;
        x += 2;
        z = x;
        y /= x;
        ++y;
        x = n / y;
        if(n % y > 0)
            ++x;
        for(cnt = 0; cnt < x; ++cnt)
        {
            for(i = cnt; i < n; i += x)
            {
                if(i > cnt)
                {
                    k = z - strlen(arr[i - x]);
                    for(j = 0; j < k; ++j)
                        printf(" ");
                }
                if(i < n)
                    printf("%s", arr[i]);
                else
                    break;
            }
            k = z - 2 - strlen(arr[i - x]);
            for(j = 0; j < k; ++j)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
/*
10
tiny
2short4me
very_long_file_name
shorter
size-1
size2
size3
much_longer_name
12345678.123
mid_size_name
12
Weaser
Alfalfa
Stimey
Buckwheat
Porky
Joe
Darla
Cotton
Butch
Froggy
Mrs_Crabapple
P.D.
19
Mr._French
Jody
Buffy
Sissy
Keith
Danny
Lori
Chris
Shirley
Marsha
Jan
Cindy
Carol
Mike
Greg
Peter
Bobby
Alice
Ruben
*/
