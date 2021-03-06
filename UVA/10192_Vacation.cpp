#include "bits/stdc++.h"
using namespace std;

int lcs(void);

map <char, int> mm;
char arr1[1010], arr2[1010], arr[1010][1010];
int value[1010][1010], depend;

int main()
{
    int ans, p = 0;
    while(gets(arr1))
    {
        if(arr1[0] == '#')
            break;
        gets(arr2);
        ans = lcs();
        printf("Case #%d: you can visit at most %d cities.\n", ++p, ans);
    }

    return 0;
}

int lcs(void)
{
    int a, b, cnt, i, j, x, y, z, maximum;

    mm.clear();
    memset(value, 0, sizeof(value));

    a = strlen(arr1);
    b = strlen(arr2);
    maximum = 0;

    i = 0;
    for(cnt = 1; cnt <= a; ++cnt)
    {
        arr[0][cnt] = arr1[i++];
    }

    i = 0;
    for(cnt = 1; cnt <= b; ++cnt)
    {
        arr[cnt][0] = arr2[i++];
    }

    for(i = 1; i <= b; ++i)
        for(j = 1; j <= a; ++j)
        {
            x = value[i - 1][j];
            y = value[i][j - 1];

            if(arr[0][j] == arr[i][0])
                depend = 1;
            else
                depend = 0;

            z = value[i - 1][j - 1] + depend;

            maximum = x > y ? x : y;
            maximum = maximum > z ? maximum : z;

            value[i][j] = maximum;
        }

    return maximum;
}

