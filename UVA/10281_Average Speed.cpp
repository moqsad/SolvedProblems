#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long int i, j, cnt, x;
    char arr[50], part[50];
    double ans = 0, hh1 = 0, mm, ss, hh2, m = 0, v = 0, y;
    while(gets(arr))
    {
        if(strlen(arr) < 9)
        {
            hh2 = (arr[0] - 48) * 10 + (arr[1] - 48);
            mm = (arr[3] - 48) * 10 + (arr[4] - 48);
            ss = (arr[6] - 48) * 10 + (arr[7] - 48);
            hh2 += mm / 60 + ss / 3600;
            y = ans + (hh2 - hh1) * v;
            printf("%s %.2lf km\n", arr, y);
        }

        else
        {
            hh1 = (arr[0] - 48) * 10 + (arr[1] - 48);
            mm = (arr[3] - 48) * 10 + (arr[4] - 48);
            ss = (arr[6] - 48) * 10 + (arr[7] - 48);
            hh1 += mm / 60 + ss / 3600;
            ans += (hh1 - m) * v;
            m = hh1;
            x = strlen(arr);
            j = 0;
            for(i = 9; i <= x; ++i)
                part[j++] = arr[i];
            v = atof(part);
        }
    }
    return 0;
}
