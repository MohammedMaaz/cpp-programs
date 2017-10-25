#include <stdio.h>
#include <math.h>
#include <console_formatting.h>

void main()
{
    double pi=3.14159265;
    int amp = 10;
    int frequency = 10; //multiple of 5 (for better results)
    if(frequency < 5) frequency = 5; //must not be less than 5
    int phase = 0;
    double cycles = 2;

    //pattern
    for(int y=amp; y>=-amp; --y)
    {
        printf("%4d ",y); //y-axis labeling
        for(int x=0; x<=cycles*360; x=x+frequency)
        {
            if( y == round(amp*sin((x + phase)*pi/180)) )
                printf("_");
            else
                printf(" ");
        }
        printf("\n");
    }


    //labeling
    printf("\n");
    int counter=0, i, prev;
    for(int i=-5; i<=361*cycles/frequency; ++i)
    {
        if(i%(int)round(361.0/frequency/4.0) == 0 && i>=0)
        {
            printf("%d", counter*90);
            prev = i;
            ++counter;
        }
        else
        {
            if(i==prev+2 && counter>1)
                printf("\b"); //adjusting x-axis labeling
            else
                printf(" ");
        }
    }

    if(counter<=4*cycles)
        printf("%d", counter*90);
    printf("\n");
}
