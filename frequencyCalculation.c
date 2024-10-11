#include<stdio.h>

void main(){
    float R, C;
    printf("Enter Resistance in Kiloohm\n");
    scanf("%f", &R);
    printf("Enter Capacitor in Microfarad\n");
    scanf("%f", &C);
    float t = 0.693*(10 + 2 * R) * C * 0.001;
    float f = 1 / t;
    printf("Time Period in seconds = %f\n", t);
    printf("Frequency in Hz = %f\n", f);
}