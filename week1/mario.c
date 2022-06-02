#include <cs50.h>
#include <stdio.h>

void print_spaces(int length);
void print_hash(int length);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // lines
    for (int i = 1; i <= height; i++)
    {
        // do spaces
        print_spaces(height - i);

        // print first half
        print_hash(i);

        printf("  ");

        // print second half
        print_hash(i);

        printf("\n");
    }
}

void print_spaces(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}

void print_hash(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
}