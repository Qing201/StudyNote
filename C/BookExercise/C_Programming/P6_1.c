#include <stdio.h>

int main(int argc, char const *argv[])
{
    float x, l = 0;
    do{
        printf("Enter a number:");
        scanf("%f", &x);
        if ( x == 0 ){
            printf("The largest number:%f", l);
            break;
        }
        else if (x > l) {
            l = x;
        }
    } while (1);

    return 0;
}
