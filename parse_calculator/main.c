#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main() {
    while (1) {
        printf("Enter an infix expression (or 'exit' to quit): ");
        char* c = (char*)malloc(100 * sizeof(char));
        scanf("%s", c);

        if (strcmp(c, "exit") == 0) {
            free(c);
            break;
        }

        printf("You entered: %s\n", c);

        // Convert to postfix
        char* postfix = infixToPostfix(c);
        printf("Postfix: %s\n", postfix);

        // Evaluate postfix
        double result = evaluatePostfix(postfix);
        printf("Result: %.2f\n\n", result);

        free(c);
        free(postfix);
    }
    return 0;
}