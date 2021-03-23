//This lab is to get more acquainted with C Progamming

#include <stdio.h>

int main ()
{
    float grade, count = 0, minimum = 100, maximum = 0, average;
    int total = 0;
    while(grade != -1)
    {
        printf("Input a valid test score (Input -1 to exit): ");
        scanf("%f", &grade);
        if(grade == -1)
        {
            break;
        }
        if(grade < 0 || grade > 100)
        {
            printf("Test score [%0.2f] is not a valid grade. \n", grade);
        }
        else
        {
            if(grade > maximum)
            {
                maximum = grade;
            }
            if(grade < minimum)
            {
                minimum = grade;
            }
            count += grade;
            total++;
        }
    }
    if(count != 0){
        average = count / total;
        printf("\nThe maximum grade is: %11.2f \n", maximum);
        printf("The minimum grade is: %11.2f \n", minimum);
        printf("The average grade is: %11.2f \n", average);
        printf("The total number of grades: %2d \n", total);
    }
}
