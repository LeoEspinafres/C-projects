#include <cs50.h>
#include <stdio.h>

string cardtype(int i, long cardnumber);
int validcardtype(long cardnumber);

int main(void)
{
    int i = 0;
    long cardnumber;
    int flag;

    do
    {
        cardnumber = get_long("Enter card number: ");
    }
    while (cardnumber <= 0);

    long temp = cardnumber;

    while (cardnumber > 0)
    {
        cardnumber = cardnumber / 10;
        i++;
    }
    cardnumber = temp;

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    flag = validcardtype(cardnumber);
    if (flag == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
        printf("%s\n", cardtype(i, cardnumber));
}

string cardtype(int i, long cardnumber)
{
    string cardtype = NULL;

    if (i == 15 && ((cardnumber / 10000000000000 == 34) || cardnumber / 10000000000000 == 37))
    {
        cardtype = "AMEX";
    }
    else if ((i == 13 && (cardnumber / 1000000000000 == 4)) || (i == 16 && (cardnumber / 1000000000000000 == 4)))
    {
        cardtype = "VISA";
    }
    else if (i == 16)
    {
        cardnumber = cardnumber / 100000000000000;
        if (cardnumber >= 51 && cardnumber <= 55)
        {
            cardtype = "MASTERCARD";
        }
        else
            cardtype = "INVALID";
    }
    else
        cardtype = "INVALID";
    return cardtype;
}

int validcardtype(long cardnumber)
{
    int digit = 0;
    int temp_whole_number = 0;
    int whole_number = 0;
    long temp_for_cardnumber = cardnumber;
    while (cardnumber > 0) // to find out the numbers I have to multiply by 2 on the card
    {
        digit = cardnumber % 100;
        digit = (digit / 10) * 2;
        if (digit > 9)
        {
            digit = digit % 10;
            digit = digit + 1;
        }
        cardnumber = cardnumber / 100;
        whole_number = whole_number + digit;
    }
    digit = 0;
    while (temp_for_cardnumber > 0)
    {
        digit = temp_for_cardnumber % 10;
        temp_whole_number += digit;
        temp_for_cardnumber = temp_for_cardnumber / 100;
    }
    whole_number = whole_number + temp_whole_number;

    if ((whole_number % 10) == 0)
    {
        return 1;
    }
    else
        return 0;
}
