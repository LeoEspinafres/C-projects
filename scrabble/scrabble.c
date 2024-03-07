#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int VALUE[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int count_points(int i, string word);

int main(void)
{
    string word1 = get_string("Type first word: ");
    string word2 = get_string("Type second word: ");
    int j = strlen(word1);
    int k = strlen(word2);
    int player1 = 0;
    int player2 = 0;

    player1 = count_points(j, word1);
    player2 = count_points(k, word2);

    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1 < player2)
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int count_points(int i, string word)
{
    int number_of_points = 0;

    while (i-- >= 0)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            number_of_points = number_of_points + VALUE[word[i] - 'a'];
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            number_of_points = number_of_points + VALUE[word[i] - 'A'];
        }
    }

    return number_of_points;
}
