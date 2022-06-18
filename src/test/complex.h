#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex
{
    float re;
    float im;
} complex;

void printComplexNumber(complex *complex);
float distance(complex *complex);

#endif /* COMPLEX_H */