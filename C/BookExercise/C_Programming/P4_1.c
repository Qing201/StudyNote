#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x;
    printf("Enter a two-digit number: ");
    scanf("%d", &x);
    printf("The reversal is : %d%d\n", x%10, x/10);
    return 0;
}
