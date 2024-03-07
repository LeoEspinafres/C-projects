#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0;
    int cash;

    do
    {
        cash = get_int("How much changed is owed: ");
    }
    while(cash < 0);

    if (cash >= 0)
    {
        while (cash >= 25)
        {
            cash = cash  - 25;
            i++;
        }
        while (cash >= 10)
        {
            cash = cash  - 10;
            i++;
        }
        while (cash >= 5)
        {
            cash = cash  - 5;
            i++;
        }
        while (cash >= 1)
        {
            cash = cash  - 1;
            i++;
        }
    }
    printf("%i\n", i);
    return (0);
}
