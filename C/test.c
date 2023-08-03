#include<stdio.h>

int main(){
    int i = 0x02;

    printf("%d, %d\n", i,(i<<1 | 0x01));

    return 0;
}
