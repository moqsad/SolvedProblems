#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <map>
using namespace std;

map <string, int> mm;
string a;
double x;

int main()
{
    int m, n, r, sum, i, det, cnt, y;
    char arr[1000], letter[20], oparetor[5];
    scanf("%d %d", &m, &n);
    getchar();
    for(cnt = 0; cnt < m; ++cnt)
    {
        cin >> a >> x;
        x *= 10;
        mm[a] = (int)x;
    }
    getchar();
    for(cnt = 1; cnt <= n; ++cnt)
    {
        sum = 0;
        gets(arr);
        r = strlen(arr);
        det = 0;
        for(i = 0; i < r; ++i)
        {
            if(isalnum(arr[i]))
            {
                letter[det++] = arr[i];
                if(!isalnum(arr[i + 1]))
                {
                    letter[det] = '\0';
                    a = letter;
                    sum += mm[a];
                    det = 0;
                }
            }
            else if(arr[i] == '>' || arr[i] == '<' || arr[i] == '=')
            {
                oparetor[0] = arr[i];
                break;
            }
        }
        if(arr[i + 1] == '=')
        {
            oparetor[1] = '=';
            oparetor[2] = '\0';
        }
        else
            oparetor[1] = '\0';
        for(i = r - 3; i < r; ++i)
            if(isdigit(arr[i]))
                letter[det++] = arr[i];
        letter[det] = '\0';
        y = atoi(letter);
        y *= 10;
        if(strcmp(oparetor, "=") == 0)
        {
            if(sum == y)
                printf("Guess #%d was correct.\n", cnt);
            else
                printf("Guess #%d was incorrect.\n", cnt);
        }
        else if(strcmp(oparetor, "<") == 0)
        {
            if(sum < y)
                printf("Guess #%d was correct.\n", cnt);
            else
                printf("Guess #%d was incorrect.\n", cnt);
        }
        else if(strcmp(oparetor, ">") == 0)
        {
            if(sum > y)
                printf("Guess #%d was correct.\n", cnt);
            else
                printf("Guess #%d was incorrect.\n", cnt);
        }
        else if(strcmp(oparetor, ">=") == 0)
        {
            if(sum >= y)
                printf("Guess #%d was correct.\n", cnt);
            else
                printf("Guess #%d was incorrect.\n", cnt);
        }
        else
        {
            if(sum <= y)
                printf("Guess #%d was correct.\n", cnt);
            else
                printf("Guess #%d was incorrect.\n", cnt);
        }
    }
    return 0;
}
