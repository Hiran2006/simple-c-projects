#include <stdio.h>
#include <calculator.h>
int main()
{
    while (1)
    {
        printf("--- Calculator ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 5)
        {
            printf("Exiting...\n");
            break;
        }
        double num1, num2;
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
        switch (choice)
        {
        case 1:
            printf("Result: %.2lf\n", add(num1, num2));
            break;
        case 2:
            printf("Result: %.2lf\n", subtract(num1, num2));
            break;
        case 3:

            printf("Result: %.2lf\n", multiply(num1, num2));
            break;

        case 4:
            if (num2 != 0)
            {
                printf("Result: %.2lf\n", divide(num1, num2));
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
        }
    }
    return 0;
}