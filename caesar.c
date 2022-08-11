#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])

{
    //Make sure la co 2 argument
    if (argc != 2 || argv[1] == NULL)
    {
        printf("Usage: ./caesar key");
        //Tra ve 1 tuc la hoan thanh
        return 1;
    }
    // argument 1 phai chua so 100%
    for (int z = 0; z < strlen(argv[1]); z++)
    {
        if (!isdigit(argv[1][z]))
        {
            return 1;
        }
    }
    ///Cac truong hop dung
    if (argc == 2)
    {
        //Nhap cac chu
        int k = atoi(argv[1]);
        string p = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, s = strlen(p); i < s; i++)
        {
            if (isupper(p[i]))
            {
                printf("%c", (p[i] + k - 65) % 26 + 65);
            }
            else if (islower(p[i]))
            {
                printf("%c", (p[i] + k - 97) % 26 + 97);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
    }
}