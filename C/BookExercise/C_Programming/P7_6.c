#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    short int s;
    int i;
    unsigned int u;
    long int l;
    unsigned long int ul;
    float f;
    double d;
    long double ld;

    int size;

    size = sizeof(i);
    printf("%d",size);
    
    return 0;
}
