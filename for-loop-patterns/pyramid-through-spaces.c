#include <stdio.h>

void main()
{
    for(int y=0; y<=4; ++y)
    {
        for(int x=0; x<=8; ++x)
        {
            if(x>=4-y && x<=y+4)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}
