#include "bits/stdc++.h"
using namespace std;

map <string, int> mm;

int main()
{
    int i, j, num[110], k, p, temp;
    char arr[35], letter[110][35], student[10050][35];
    string a, b;
    p = 0;
    while(1)
    {
        memset(num, 0, sizeof(num));
        j = 0;
        i = -1;
        mm.clear();
        while(gets(arr))
        {
            if(arr[0] == '1')
                break;
            if(arr[0] == '0')
            {
                p = 1;
                break;
            }
            if(arr[0] < '[')
            {
                ++i;
                strcpy(letter[i], arr);
            }
            else
            {
                a = arr;
                if(mm.find(a) == mm.end())
                {
                    strcpy(student[j], arr);
                    mm[a] = i;
                    ++j;
                }
                else if(mm[a] < i)
                {
                    mm[a] = -1;
                }
            }
        }
        if(p == 1)
            break;
        for(k = 0; k < j; ++k)
        {
            if(mm[student[k]] > -1)
                ++num[mm[student[k]]];
        }
        for(k = 0; k < i; ++k)
            for(j = k + 1; j <= i; ++j)
            {
                if(num[j] > num[k])
                {
                    temp = num[k];
                    num[k] = num[j];
                    num[j] = temp;
                    strcpy(arr, letter[k]);
                    strcpy(letter[k], letter[j]);
                    strcpy(letter[j], arr);
                }
                else if(num[j] == num[k] && strcmp(letter[j], letter[k]) < 0)
                {
                    strcpy(arr, letter[k]);
                    strcpy(letter[k], letter[j]);
                    strcpy(letter[j], arr);
                }
            }
        for(k = 0; k <= i; ++k)
            printf("%s %d\n", letter[k], num[k]);
    }
    return 0;
}
