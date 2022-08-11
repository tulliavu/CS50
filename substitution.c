#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //validate the key then get the key (done)
    if (argc != 2 || argv[1] == NULL)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    // neu tu do gap lai 2 lan (done)
    for (int i = 0; i < 26; i++)
    {
        for (int k = i + 1; k < 26 ; k ++)
        {
            char laplai = (argv[1][i]) - (argv[1][k]);
            //Nay la phong truong hop viet hoa hoac viet thuong
            if (laplai == 0 || laplai == 32 || laplai == -32)
            {
                printf("Usage: ./substitution key");
                return 1;
            }
        }
    }
    //get plaintext
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        //encipher
        //print ciphertext
        string p = get_string("plaintext: ");
        printf("ciphertext: ");
        string key = argv[1];
        for (int z = 0; z < strlen(p); z++)
        {
            if (islower(p[z]))
            {
                printf("%c", tolower(argv[1][p[z] - 97]));
            }
            else if (isupper(p[z]))
            {
                printf("%c", toupper(argv[1][p[z] - 65]));
            }
            else
            {
                printf("%c", p[z]);
            }
        }
        printf("\n");
    }
}