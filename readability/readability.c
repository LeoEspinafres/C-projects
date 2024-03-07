#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double index_calculator(int n_letters, int n_words, int n_sentences);

int main(void)
{
    string text = get_string("Text: ");
    int n_letters = 0;
    int n_words = 0;
    int n_sentences = 0;
    int i = strlen(text);
    int j = 0;
    //count the number of letters words and sentences
    if (text[--i] == 46 || text[--i] == 63 || text[--i] == 33)
        n_words++;
    while (text[j] != '\0') // i should use isalpha, isnumerical etc from ctype.h. but i did it this way first.
    {
        if ((text[j] >= 33 && text[j] <= 126))
        {
            if((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z'))
            {
                n_letters++;
                j++;
            }
            else if(text[j] == 46 || text[j] == 63 || text[j] == 33)
            {
                n_sentences++;
                j++;
            }
            else
                j++;
        }
        else if (text[j] == 32)
        {
            n_words++;
            j++;
        }
    }
    int k = index_calculator(n_letters, n_words, n_sentences);

    //print out the result according to the int the index gave us
    if (k < 1)
        printf("Before Grade 1\n");
    else if (k > 1 && k < 16)
        printf("Grade %i\n", k);
    else
        printf("Grade 16+\n");

    return 0;
}

// calculate the index;
double index_calculator(int n_letters, int n_words, int n_sentences)
{
    double l = ((float)n_letters /(float) n_words) * 100;
    double s = ((float)n_sentences / (float) n_words) * 100;

    int index = round((0.0588 * l) - (0.296 * s) - 15.8);

    return index;
}
