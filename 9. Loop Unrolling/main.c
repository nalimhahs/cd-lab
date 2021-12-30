#include <stdio.h>

int rolled_loop(unsigned int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        n >>= 1;
        i++;
    }
    printf("\nNo of iterations: %d", i);
    return bits;
}

int unrolled_loop(unsigned int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;
        n >>= 4;
        i++;
    }
    printf("\nNo of iterations: %d", i);
    return bits;
}

void main()
{
    unsigned int n;
    int x, d;
    printf("Enter N: ");
    scanf("%u", &n);

    x = rolled_loop(n);
    printf("\nLoop Roll: Count of 1's : %d", x);

    x = unrolled_loop(n);
    printf("\nLoop Unroll: Count of 1's : %d\n", x);
}
