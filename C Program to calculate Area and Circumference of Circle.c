#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area, circumference;

    //Prompt user to enter the radius of circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate area and circumference of circle
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    // Print are and circumference of circle
    printf("Area of the circle: %.2f\n", area);
    printf("Circumference of the circle: %.2f\n", circumference);

    return 0;
}
