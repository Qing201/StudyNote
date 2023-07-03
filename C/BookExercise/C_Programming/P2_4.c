#include <stdio.h>


int main(int argc, char const *argv[])
{
    float amount, total;
    float tipRent = 0.05;

    printf("Enter an amount:");
    scanf("%f", &amount);
    printf("With tax added: %.2f\n", amount * (1 + tipRent));
    
    return 0;
}
