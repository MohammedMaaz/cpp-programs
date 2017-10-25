#include <stdio.h>

void main()
{
    for(int y=0; y<=5; ++y)
    {
        for(int x=0; x<=y+2; ++x)
        {
            printf("*");
        }
        printf("\n");
    }
}
