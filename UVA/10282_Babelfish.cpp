#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <map>
using namespace std;

map <string, string> mm;
string a, b;
char arr[60], english[30], foreign[30];

int main()
{
    int cnt, det, x;
    while(1)
    {
        gets(arr);
        if(arr[0] == '\0')
            break;
        x = strlen(arr);
        det = 0;
        for(cnt = 0; cnt < x; ++cnt)
        {
            if(isalnum(arr[cnt]))
                {
                    english[det++] = arr[cnt];
                }
                if(!isalnum(arr[cnt + 1]))
                {
                    english[det] = '\0';
                    a = english;
                    det = 0;
                    break;
                }
        }
        for(cnt = cnt + 1; cnt < x; ++cnt)
        {
            if(isalnum(arr[cnt]))
                {
                    foreign[det++] = arr[cnt];
                }
                if(!isalnum(arr[cnt + 1]))
                {
                    foreign[det] = '\0';
                    b = foreign;
                    det = 0;
                    break;
                }
        }
        mm[b] = a;
    }
    while(cin >> b)
    {
        if(mm.find(b) != mm.end())
            cout << mm[b] <<  endl;
        else
            printf("eh\n");
    }
    return 0;
}
