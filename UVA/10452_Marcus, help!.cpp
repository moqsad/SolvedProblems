#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[15][15];

string letter[15];

int taken[100], visit[100];

int main()
{
    int cnt, t, i, j, x, row, column;
    taken['I'] = taken['E'] = taken['H'] = taken['O'] = taken['V'] = taken['A'] = taken['#'] = 1;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &row, &column);
        for(i = 0; i < row; ++i)
            scanf("%s", arr[i]);
        i = row - 1;
        for(j = 0; j < column; ++j)
            if(arr[i][j] == '@')
                break;
        x = 0;
        memset(visit, 0, sizeof(visit));
        while(arr[i][j] != '#')
        {
            if(j - 1 > -1 && taken[arr[i][j - 1]] == 1 && visit[arr[i][j - 1]] == 0)
            {
                letter[x++] = "left";
                visit[arr[i][--j]] = 1;
            }

            else if(j + 1 < column && taken[arr[i][j + 1]] == 1 && visit[arr[i][j + 1]] == 0)
            {
                letter[x++] = "right";
                visit[arr[i][++j]] = 1;
            }

            else
            {
                letter[x++] = "forth";
                visit[arr[--i][j]] = 1;
            }

//            printf("%d %d %c______________\n", i, j, arr[i][j]);
        }

        cout << letter[0];
        for(i = 1; i < 7; ++i)
            cout << " " << letter[i];
        printf("\n");
    }
    return 0;
}
