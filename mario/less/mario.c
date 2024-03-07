#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    int rows = 0;

    while (rows <= 0)
    {
        rows = get_int("Enter number of rows: ");
    }

    while (i < rows)
    {
        int j = 0;
        while (j < rows - i - 1)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j <= i)
        {
            printf("#");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
