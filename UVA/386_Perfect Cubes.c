#include <stdio.h>
int main()
{
    int i, j, k, l, a, b, c;
    for(i = 2; i < 201; ++i)
    {
        a = i * i * i;
        for(j = 2; j < i; ++j)
        {
            b = j * j * j;
            for(k = j; k < i; ++k)
            {
                c = k * k * k;
                for(l = k; l < i; ++l)
                    if(a  ==  b  +  c  +  l * l * l)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                    }
            }
        }
    }

    return 0;
}
