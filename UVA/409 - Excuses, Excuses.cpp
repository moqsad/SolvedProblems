#include <cstdio>
#include <cstring>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cctype>
#include <iostream>
using namespace std;

map <string, int> mm;

string a;
char arr[30][80], letter[80], rec[80];
int num[30];

int main()
{
    int total, i, j, k, l, e, x, m, cnt = 0;
    while(scanf("%d %d", &k, &e) == 2)
    {
        for(i = 0; i < k; ++i)
        {
            scanf("%s", letter);
            mm[letter] = 1;
        }

        memset(num, 0, sizeof(num));
        getchar();
        total = 0;

        for(i = 0; i < e; ++i)
        {
            gets(arr[i]);
            x = strlen(arr[i]);
            for(j = 0; j <= x; ++j)
                letter[j] = tolower(arr[i][j]);
            stringstream ss (letter);
            while(ss >> a)
            {
                for(l = 0; a[l] != '\0'; ++l)
                {
                    if(isalpha(a[l]))
                    {
                        m = 0;
                        while(isalpha(a[l]))
                        {
                            rec[m++] = a[l];
                            ++l;
                        }
                        rec[m] = '\0';
                        if(mm.find(rec) != mm.end())
                            ++num[i];
                            --l;
                    }
                }
            }
            if(num[i] > total)
                total = num[i];
        }

        printf("Excuse Set #%d\n", ++cnt);
        for(i = 0; i < e; ++i)
        {
            if(num[i] == total)
                printf("%s\n", arr[i]);
        }
        printf("\n");
        mm.clear();
    }
    return 0;
}
