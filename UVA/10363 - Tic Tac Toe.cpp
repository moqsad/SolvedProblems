#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char arr[5][5];

int main()
{
    int x, o, i, j, cnt, t, on, xn;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        xn = on = x = o = 0;
        for(i = 0; i < 3; ++i)
            scanf("%s", arr[i]);

        for(i = 0; i < 3; ++i)
            for(j = 0; j < 3; ++j)
            {
                if(arr[i][j] == 'X')
                    ++x;
                else if(arr[i][j] == 'O')
                    ++o;
            }

        if(arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')
            ++xn;
        else if(arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')
            ++on;

        if(arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')
            ++xn;
        else if(arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')
            ++on;

        if(arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')
            ++xn;
        else if(arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')
            ++on;





        if(arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')
            ++xn;
        else if(arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')
            ++on;

        if(arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')
            ++xn;
        else if(arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')
            ++on;

        if(arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')
            ++xn;
        else if(arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')
            ++on;




        if(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
            ++xn;
        else if(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
            ++on;

        if(arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
            ++xn;
        else if(arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
            ++on;

        if(o > x || x - o > 1)
            printf("no\n");

        else if(xn > 0 && on > 0)
            printf("no\n");

        else if(on == 1 && x != o)
            printf("no\n");

        else if(xn == 1 && x - o != 1)
            printf("no\n");

        else
            printf("yes\n");
    }
    return 0;
}
