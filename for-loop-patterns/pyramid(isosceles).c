#include <stdio.h>

void main()
{
    //method 1:
    /*for(int y=0; y<=4; ++y)
    {
        for(int x=0; x<4-y; ++x)
        {
            printf(" ");
        }
        for(int x=4-y; x<=y+4; ++x)
        {
            printf("*");
        }
        printf("\n");
    }*/

    //method 2
    for(int y=0; y<=4; ++y)
    {
        for(int x=0; x<=8; ++x)
        {
            if(x<4-y)
                printf(" ");
            else if(x>=4-y && x<=y+4)
                printf("*");
        }
        printf("\n");
    }
}
