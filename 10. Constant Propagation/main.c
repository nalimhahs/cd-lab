#include <stdio.h>
#include <math.h>

int main()
{
    int c;
    float r, pi = floor((22.0 / 7.0) * 100) / 100;
    do
    {
        printf("\nMENU");
        printf("\n1. Find perimeter and area of circle without constant propagation");
        printf("\n2. Find perimeter and area of circle with constant propagation Code optimization");
        printf("\n3. Exit");
        printf("\nEnter your Option: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                printf("Enter the radius of circle: ");
                scanf("%f", &r);
                printf("Perimeter = %0.2f", 2 * pi * r);
                printf("\nArea = %0.2f", pi * r * r);
                break;
            case 2:
                printf("Enter the radius of circle: ");
                scanf("%f", &r);
                printf("Perimeter = %0.2f", 2 * 3.14 * r);
                printf("\nArea = %0.2f", 3.14 * r * r);
                break;
        }

    } while (c != 3);
    return 0;
}