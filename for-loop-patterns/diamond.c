#include <stdio.h>

void main()
{
    int size = 5;

    //method 1
    /*
    for(int y=0; y<=(size-1)*2; ++y)
    {
        for(int x=0; x<=(size-1)*2; ++x)
        {
            if(y<=(size-1))
            {
                if(x>=(size-1)-y && x<=y+(size-1))
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if(x>=y-(size-1) && x<=(size-1)*3-y)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    } */

    //method 2
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
    }
    for(int y=5; y<=8; ++y)
    {
        for(int x=0; x<y-4; ++x)
        {
            printf(" ");
        }
        for(int x=y-4; x<=12-y; ++x)
        {
            printf("*");
        }
        printf("\n");
    }*/

    //method 3
    for(int y=0; y<=8; ++y)
    {
        for(int x=0; x<=8; ++x)
        {
            if(x>=4-y && x>=y-4 && x<=y+4 && x<=12-y)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

