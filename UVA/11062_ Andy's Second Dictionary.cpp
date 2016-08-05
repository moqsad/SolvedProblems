#include <cstdio>
#include <set>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

set <string> dictionary;
set <string> :: iterator it;

char arr[210], letter[210], temp[210] = "234432";

int main()
{
    int i, j, x;
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        for(j = 0; j < x; ++j)
        {
            if(isalpha(arr[j]) && arr[strlen(arr)- 1] != '-' && temp[strlen(temp) - 1] != '-')
            {
                i = 0;
                while(isalpha(arr[j]) || arr[j] == '-')
                {
                    letter[i++] = tolower(arr[j]);
                    ++j;
                }
                letter[i] = '\0';
                dictionary.insert(letter);
//                printf("__________________\n");
            }
            else if(isalpha(arr[j]) && arr[strlen(arr)- 1] == '-' && temp[strlen(temp) - 1] != '-')
            {
                i = 0;
                while(isalpha(arr[j]))
                {
                    letter[i++] = tolower(arr[j]);
                    ++j;
                }
//                printf("--------------------\n");
            }
            else if(isalpha(arr[j]) && arr[strlen(arr)- 1] == '-' && temp[strlen(temp) - 1] == '-')
            {
                while(isalpha(arr[j]))
                {
                    letter[i++] = tolower(arr[j]);
                    ++j;
                }
//                printf("%s %s|||||||||||||||||||||\n", arr,temp);
            }
            else if (isalpha(arr[j]) && arr[strlen(arr)- 1] != '-' && temp[strlen(temp) - 1] == '-')
            {
//                printf("%d__",i);
                while(isalpha(arr[j]))
                {
                    letter[i++] = tolower(arr[j]);
                    ++j;
                }
                letter[i] = '\0';
//                printf("%s+++++++++++++++++++++\n",letter);
                dictionary.insert(letter);
            }
        }
        strcpy(temp, arr);
    }
    for(it = dictionary.begin(); it != dictionary.end(); it++)
        cout << *it << "\n";
    return 0;
}
