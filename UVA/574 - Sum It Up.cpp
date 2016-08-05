#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, t, x, arr[30], p;
char ch[100];
map <string, int> mm;

vector <int> result;

void convert(void)
{
    int i, k, y;
    k = 0;
    y = result[0];
    while(y > 0)
    {
        ch[k++] = y % 10 + 48;
        y /= 10;
    }

    for(i = 1; i < x; ++i)
    {
        ch[k++] = '+';
        y = result[i];
        while(y > 0)
        {
            ch[k++] = y % 10 + 48;
            y /= 10;
        }
    }
    ch[k] = '\0';
}

void call(int j)
{
    int i, sum = 0;
    x = result.size();
    for(i = 0; i < x; ++i)
        sum += result[i];
    if(sum == t)
    {
        convert();
        if(mm.find(ch) == mm.end())
        {
            p = 1;
            printf("%d", result[0]);
            for(i = 1; i < x; ++i)
                printf("+%d", result[i]);
            printf("\n");
            mm[ch] = 1;
        }
    }

    for(i = j + 1; i < n; ++i)
    {
        result.push_back(arr[i]);

        call(i);

        result.pop_back();
    }
}


int main()
{
    int i, sum;
    while(scanf("%d %d", &t, &n) == 2)
    {
        if(t == 0 && n == 0)
            break;
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        printf("Sums of %d:\n", t);
        p = 0;
        call(-1);
        if(p == 0)
            printf("NONE\n");
        mm.clear();
    }
    return 0;
}

/*
200 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/

