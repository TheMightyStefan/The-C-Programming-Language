#include <stdio.h>
int main ()
{
    float celsius,fahr;
    int lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = 300;
    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("  %0.3f |%6.1f\n -----------------\n",fahr,celsius);
        fahr = fahr - step;
    }
    return 0;
}