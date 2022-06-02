#include <cs50.h>
#include <stdio.h>


int main(void)
{
    long creditCard = get_long("Number: ");

    int digits[16];

    for(int i=0; i<16; i++)
    {
        digits[i] = creditCard % 10;
        creditCard /= 10;
    }

    int sum_odd = 0;
    // first phase
    for(int i=1; i<16; i+=2)
    {
        sum_odd += ((digits[i]*2)/10) + ((digits[i]*2) % 10);
    }

    int sum_even = 0;
    // second phase
    for(int i=0; i<16; i+=2)
    {
        sum_even += (digits[i]);
    }

    int validity_mod = (sum_odd + sum_even) % 10;

    int startingDigit = -1; // in reverse

    // find the starting digit in reverse
    for(int i=15;i>=0;i--)
    {
        if(digits[i] != 0)
        {
            startingDigit = i;
            break;
        }
    }

    bool valid = false;

    if(validity_mod == 0)
    {
        int firstTwo = (digits[startingDigit]*10) + digits[startingDigit-1];

        if((firstTwo == 34 || firstTwo == 37) && (startingDigit == 14))
        {
            printf("AMEX\n");
            valid = true;
        }

        if(firstTwo >= 51 && firstTwo <= 55 && startingDigit == 15)
        {
            printf("MASTERCARD\n");
            valid = true;
        }

        if(firstTwo >= 40 && firstTwo <= 49 && (startingDigit == 12 || startingDigit == 15))
        {
            printf("VISA\n");
            valid = true;
        }
    }

    if(valid == false)
    {
        printf("INVALID\n");
    }
}
