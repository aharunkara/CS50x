#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        long keyLength = strlen(key);
        if (keyLength != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            int checkSum = 0;
            for (int i = 0; i < keyLength; i++)
            {

                if (!isalpha(key[i]))
                {
                    printf("invalid key\n");
                    return 1;
                }

                int keyInt = (int)toupper(key[i]);
                checkSum += keyInt;

                for(int j=0;j<keyLength;j++)
                {
                    if(i != j)
                    {
                        if(toupper(key[i]) == toupper(key[j]))
                    {
                        printf("repeated letter in key\n");
                        return 1;
                    }
                    }
                }
            }

            string plainText = get_string("plain text: ");

            printf("\nciphertext: ");
            for (int i = 0; i < strlen(plainText); i++)
            {
                if(isalpha(plainText[i]))
                {
                    //cipher without loosing case
                    int letterIndex = (int)toupper(plainText[i]) - 65;
                    int diff = (int)toupper(key[letterIndex]) - (int)toupper(plainText[i]);
                    printf("%c", (int)plainText[i] + diff);
                } else
                {
                     printf("%c",plainText[i]); // dont cipher nonalpha
                }
            }

            printf("\n");
            return 0;
        }
    }
}