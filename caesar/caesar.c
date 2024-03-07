#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char ALPHABET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int checking_key(char *key);
string encrypt_function(string plaintext, int check);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string teste = "1";
    int key = checking_key(argv[1]);

    if (key != 0)
        exit(1);
    int check = atoi(argv[1]);

    string plaintext = get_string("Plaintext:  ");
    string cipher = encrypt_function(plaintext, check);

    printf("ciphertext: %s\n", cipher);
    free(cipher);
    return 0;
}

int checking_key(char *key)
{
    int i = 0;
    while (key[i] != '\0')
    {
        if (key[i] >= 48 && key[i] <= 57)
            i++;
        else
            return 1;
    }
    return 0;
}

string encrypt_function(string plaintext, int check)
{
    int i = 0;
    int j = strlen(plaintext);
    string cipher = malloc(j + 1);

    while (plaintext[i] != '\0')
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            cipher[i] = alphabet[(plaintext[i] - 'a' + check + 26) % 26];
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            cipher[i] = ALPHABET[(plaintext[i] - 'A' + check + 26) % 26];
        }
        else
            cipher[i] = plaintext[i];
        i++;
    }
    return cipher;
}
