#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map <string, int> mm;
map <int, string> nn;

int ans[110][110], a[3][110], l;
char arr[2010], letter[40], pos[110][110];

void print(int i, int j, int k)
{
    if(i == 0 || j == 0)
        return ;

    if(pos[i][j] == 'd')
    {
        print(i - 1, j - 1, k + 1);
        if(k > 0)
            cout << nn[a[0][j]] << " ";
        else
            cout << nn[a[0][j]] << "\n";
    }

    else if(pos[i][j] == 'u')
        print(i-1, j, k);

    else
        print(i, j - 1, k);
}

int func(int index)
{
    int i, j, k, x;
    k = 1;
    while(arr[0] != '#')
    {
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            if(isalnum(arr[i]))
            {
                j = 0;

                while(isalnum(arr[i+1]))
                {
                    letter[j++] = arr[i];
                    ++i;
                }

                letter[j++] = arr[i];
                letter[j] = '\0';

                if(mm.find(letter) == mm.end())
                {
                    ++l;
                    mm[letter] = l;
                    nn[l] = letter;
                }
                a[index][k++] = mm[letter];
            }
        }
        gets(arr);
    }

    return k;
}

int main()
{
    int u, v, i, j, cnt = 0;
    while(gets(arr))
    {
        u = func(0);
        gets(arr);
        v = func(1);
        for(i = 1; i < v; ++i)
            for(j = 1; j < u; ++j)
            {
                if(a[1][i] == a[0][j])
                {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                    pos[i][j] = 'd';
                }
                else if(ans[i - 1][j] > ans[i][j - 1])
                {
                    ans[i][j] = ans[i - 1][j];
                    pos[i][j] = 'u';
                }
                else
                {
                    ans[i][j] = ans[i][j - 1];
                    pos[i][j] = 'v';
                }
            }
        print(i - 1, j - 1, 0);
    }
    return 0;
}
