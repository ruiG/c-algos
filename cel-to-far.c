#include <stdio.h>

// print Celsius-Fahrenheit table

int main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;   // step size

    celcius = lower;
    printf("%4s %7s\n", "°C", "°F");

    while (celcius <= upper)
    {
        fahr = ((9.0 / 5.0 * celcius) + 32.0);
        printf("%3.0f %6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }

    return 0;
}