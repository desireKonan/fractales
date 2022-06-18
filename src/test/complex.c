#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

void printComplexNumber(complex *complex) {
    printf("Complex[z = %f + %f i]", complex->re, complex->im);
}

float distance(complex *complex) {
    return sqrtf(powf(complex->re, 2) + powf(complex->im, 2));
}

int main(int argc, char const *argv[])
{
    //Test la fonction sur les complexes écrites.
    complex complex;
    printf("[-------- Test sur la fonction Complex ---------]");
    printf("Bienvenu dans notre programme d'utilisation des nombres complexes !\n");
    printf("Veuillez entrez un nombre complexe de la forme z = a + bi avec (a, b réels où a est un reél et b un imaginaire). \n");
    printf("Entrez votre réel a : ");
    scanf("%f", &complex.re);
    printf("Entrez votre imaginaire b : ");
    scanf("%f", &complex.im);
    printComplexNumber(&complex);
    printf("La distance de ce complexe est : %f", distance(&complex));
    return 0;
}
