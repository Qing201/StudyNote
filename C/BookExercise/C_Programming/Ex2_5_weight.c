#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y, z, weight, v;

    printf("Enter height of box: ");
    scanf("%d", &x);
    printf("Enter length of box: ");
    scanf("%d", &y);
    printf("Enter width of box: ");
    scanf("%d", &z);

    v = x * y * z;
    weight = (v + 165) / 166;

    printf("Volume (cubic inches): %d\n", v);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}

