#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <limits.h>
// tao 1 ham chung de apply cac truong hop, ham nay la de tinh tong so le tu duoi len
int checksum1(long long r, int y)
{
    int i = 1;
    int m = 0;
    do
    {
        //printf("so thap phan la %lld \n", (long long) round(pow(10 , (2 * i))));
        //printf("so r la %lld \n", r);
        long long k = r % (long long) round(pow(10, (2 * i)));
        //printf("so k la %lld \n",k);
        long long l = k / (long long) round(pow(10, (2 * i - 1)));
        //printf("so l la %lld \n",l);
        if (l > 4)
        {
            int s = (2 * l) % 10;
            m = m + s + 1 ;
        }
        else
        {
            m = m + 2 * l;
        }
        //printf("so m la %d \n",m);
        i ++;
        //printf("so i la %d \n",i);
    }
    while (i <= round(y / 2));
    return m;
}
// tao 1 ham chung de apply cac truong hop, ham nay la de tinh tong so chan tu duoi len
int checksum2(long long r, int y)
{
    int u = 1;
    int j = 0;
    do
    {
        long long w = r % (long long) round(pow(10, (2 * u - 1)));
        long long f = w / (long long) round(pow(10, (2 * u - 2)));
        j = j + f;
        //printf("so j la %d \n",j);
        u ++;
    }
    while (u <= round(y / 2) + 1);
    return j;
}
int main(void)
{
    // Bao nguoi dung nhap so tai khoan
    long long x = get_long("Nhap so credit: \n");
    // lam cho no co dinh
    const long long g = x;
    // n la so chu so
    int n = 0;
    do
    {
        //Tinh so chu so cua so tai khoan vua nhap
        x = x / 10;
        n ++;
    }
    while (x != 0);
    //printf("so n2 la %d \n ",n);
    // hang check 2 chu so dau ;
    //printf("so x la %lld \n",g);
    int c = g / (long long) round(pow(10, (n - 2)));
    //printf("so c la %d \n ",c);
    // Neu so hang bang 15 va bat dau = 34 hoac 37 thi co kha nang la AE
    if (n == 15)
    {
        // Neu bat dau = 34 hoac 37
        if (c == 34 || c == 37)
        {
            // Thuc hien ham checksum, neu dung in AE
            int m = checksum1(g, n);
            //printf("so m la %d \n", m);
            int j = checksum2(g, n);
            int ae = m + j;
            if (ae % 10 == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Neu so hang bang 16 va bat dau bang 4 thi co kha nang la Visa ; bat dau bang 1 day 51 den 55 thi co khang la MC
    else if (n == 16)
    {
        // Neu bat dau = 4
        if (c / 10 == 4)
        {
            // Thuc hien ham checksum, neu dung in Visa
            int m = checksum1(g, n);
            int j = checksum2(g, n);
            int vs = m + j;
            if (vs % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Neu bat dau bang 51 den 55
        else if (c == 51 || c == 52 || c == 53 || c == 54 || c == 55)
        {
            // Thuc hien ham checksum, neu dung in MC
            int m = checksum1(g, n);
            int j = checksum2(g, n);
            int mc = m + j;
            if (mc % 10 == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (n == 13)
    {
        // Neu bat dau bang 4
        if (c / 10 == 4)
        {
            // Thuc hien ham checksum, neu dung in Visa
            int m = checksum1(g, n);
            int j = checksum2(g, n);
            int vs = m + j;
            if (vs % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
