// First "C" Program

#include <stdio.h>
#include <math.h>

int main ()
{
    float num1, num2;
    printf("Give me the first number: ");
    scanf("%f", &num1);
    printf("Give me the second number: ");
    scanf("%f", &num2);

    printf("The two numbers are: %0.2f, %0.2f\n", num1, num2);

    float sum = num1 + num2;
    printf("%0.2f + %0.2f = %0.2f \n", num1, num2, sum);
    float difference = num1 - num2;
    printf("%0.2f - %0.2f = %0.2f \n", num1, num2, difference);
    float product = num1 * num2;
    printf("%0.2f * %0.2f = %0.2f \n", num1, num2, product);
    float quotient = num1 / num2;
    printf("%0.2f / %0.2f = %0.2f \n", num1, num2, quotient);
    float p_theorm = sqrt(pow(num1, 2) + pow(num2, 2));
    printf("%0.2f^2 + %0.2f^2 = %0.2f^2 \n", num1, num2, p_theorm);
}
