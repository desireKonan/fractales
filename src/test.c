#include <stdio.h>

int main(void) {
    int a = 5;
    int *p = &a;
    printf("L'adresse de a est : %d\n", &a);
    printf("La valeur de a est : %d", *p);
    return 0;
}