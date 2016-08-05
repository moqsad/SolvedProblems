#include <cstdio>
#include <set>
#include <cstring>
#include <cctype>
#include <iostream>22
using namespace std;

set <string> dictionary;
set <string> :: iterator it;

char arr[210], letter[210];

int main()
{
    int i, j, x;
    while(scanf("%s", arr) == 1)
    {
        i = 0;
        x = strlen(arr);
        for(j = 0; j < x; ++j)
        {
            if(isalpha(arr[j]))
            {
                i = 0;
                while(isalpha(arr[j]))
                {
                    letter[i++] = tolower(arr[j]);
                    ++j;
                }
                letter[i] = '\0';
                dictionary.insert(letter);
            }
        }
    }
    for(it = dictionary.begin(); it != dictionary.end(); it++)
        cout << *it << "\n";
    return 0;
}
