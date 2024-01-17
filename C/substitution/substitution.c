#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isDistinctAlphabet(string key);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1; // return non-zero to indicate an error
    }

    // Get the key from command-line argument
    string key = argv[1];

    // Validate the key
    int keyLength = strlen(key);

    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1; // return non-zero to indicate an error
    }

    // Additional validation if needed
    if (!isDistinctAlphabet(key))
    {
        return 1; // return non-zero to indicate an error
    }

    for(int i = 0; i < 26; i++)
    {
        if(islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }


    // get plain text
    string p = get_string("plaintext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        char c = p[i];
        if(isupper(c) && c > 'A' && c < 'Z')
        {
            p[i] = key[p[i] - 'A'];
        }
        else if(islower(c) && c > 'a' && c < 'z')
        {
            char between = toupper(p[i]);
            p[i] = tolower(key[between - 'A']);
        }
    }
    // print ciphertext
    printf("ciphertext: %s\n", p);
    return 0; // return 0 to indicate successful execution
}


bool isDistinctAlphabet(string key)
{
    int letterCount[26] = {0};
    for(int i = 0; i < 26; i++)
    {
        char currentChar = toupper(key[i]);

        if (currentChar < 'A' || currentChar > 'Z')
        {
            printf("Key must only contains alphabetic characters \n");
            return false;
        }

        // Check if the letter has already occurred
        if (letterCount[currentChar - 'A'] > 0)
        {
            printf("Key must not contains repeated characters \n");
            return false; // Duplicate letter found
        }

        // Mark the letter as occurred
        letterCount[currentChar - 'A']++;
    }

    return true; // All conditions satisfied

}