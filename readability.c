#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Ham tim so chu
int count_letters(string text)
{
    int i = 0;
    int p = 0;
    while (text[i] != '\0')
    {
        if (text[i] != '.' && text[i] != '!' && text[i] != ',' && text[i] != ' ' && text[i] != '?' && text[i] != ';' && text[i] != '-'
            && text[i] != 39)
        {
            p++;
        }
        i++;
    }
    return p;
}
// Ham tim so tu
int count_word(string text)
{
    int s = 0;
    int m = 1;
    //will contain at least one word;will not start or end with a space; and will not have multiple spaces in a row.
    while (text[s] != '\0')
    {
        if (text[s] == ' ')
        {
            m++;
        }
        s++;
    }
    return m ;
}
// Ham tim so cau
int count_sentence(string text)
{
    int k = 0;
    int q = 0;
    //will contain at least one word;will not start or end with a space; and will not have multiple spaces in a row.
    while (text[k] != '\0')
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            q++;
        }
        k++;
    }
    return q;
}
// Ham chinh
int main(void)
{
    //Nhap chu
    string x = get_string("Enter your word: \n");
    // Dem tong o chu trong nhieu chu
    int sochu = count_letters(x);
    // dem tong so chu
    int sotu = count_word(x);
    // den so cau
    int socau = count_sentence(x);
    float L = (float) sochu / (float) sotu * 100;
    float S = (float) socau / (float) sotu * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 16 && index > 0)
    {
        printf("Grade %d\n", index);
    }
    else if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
