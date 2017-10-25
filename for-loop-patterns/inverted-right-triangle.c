#include <stdio.h>

void main()
{
    for(int y=0; y<=4; ++y)
    {
        for(int x=0; x<=4-y; ++x)
        {
            printf("*");
        }
        printf("\n");
    }
}
