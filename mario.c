#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n=get_int("Size:");
    }
        while (n<1 || n>8);
    //For each row
    for (int i = 0; i<n;i++)
    {
        for ( int k=0; k < n-i-1; k++ )
        {
            printf(" ");
        }
        for ( int q = 0; q<=i;q++)
        {
            printf("#");
        }
        printf("  ");
        //For each column
        for ( int j = 0;j <= i;j++ )
        {
                //Print a brick
                printf("#");
        }
        //Move to next row
        printf("\n");
    }
}