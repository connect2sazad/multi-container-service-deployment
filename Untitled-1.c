
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
int main_menu(void);
int simple_calc(void);
int advanced_calc(void);

double simple_operation(char op) {
    double num1, num2, result = 0;

    printf("Enter the 1st number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    printf("Enter the 2nd number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    switch (op) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
                return 0;
            }
            result = num1 / num2;
            break;

        default:
            printf("Invalid operator.\n");
            return 0;
    }

    return result;
}

double advanced_operation(char op) {
    double num1, result = 0;

    printf("Enter the value of x: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    switch (op) {
        case 'c':
            result = cbrt(num1);
            break;

        case 's':
            if (num1 < 0) {
                printf("Error! Square root of a negative number.\n");
                return 0;
            }
            result = sqrt(num1);
            break;

        case 'o':
            result = cos(num1);
            break;

        case 'i':
            result = sin(num1);
            break;

        case 't':
            result = tan(num1);
            break;

        case 'l':
            if (num1 <= 0) {
                printf("Error! Logarithm requires a positive number.\n");
                return 0;
            }
            result = log(num1);
            break;

        default:
            printf("Invalid operation.\n");
            return 0;
    }

    return result;
}

int simple_calc(void) {
    int op;

    while (1) {
        printf("\nSimple Calculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("9. Go Back to Main Menu\n");
        printf("0. Exit\n");
        printf("Select from Menu: ");

        if (scanf("%d", &op) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (op) {
            case 1:
                printf("Result: %.2f\n",
                       simple_operation('+'));
                break;

            case 2:
                printf("Result: %.2f\n",
                       simple_operation('-'));
                break;

            case 3:
                printf("Result: %.2f\n",
                       simple_operation('*'));
                break;

            case 4:
                printf("Result: %.2f\n",
                       simple_operation('/'));
                break;

            case 9:
                return 0;

            case 0:
                printf("Thank you for using this calculator!\n");
                exit(0);

            default:
                printf("Invalid menu option.\n");
        }
    }
}

int advanced_calc(void) {
    int op;

    while (1) {
        printf("\nAdvanced Calculator Menu:\n");
        printf("1. Cube Root\n");
        printf("2. Square Root\n");
        printf("3. Cos\n");
        printf("4. Sin\n");
        printf("5. Tan\n");
        printf("6. Log (natural logarithm)\n");
        printf("9. Go Back to Main Menu\n");
        printf("0. Exit\n");
        printf("Select from Menu: ");

        if (scanf("%d", &op) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (op) {
            case 1:
                printf("Result: %.2f\n",
                       advanced_operation('c'));
                break;

            case 2:
                printf("Result: %.2f\n",
                       advanced_operation('s'));
                break;

            case 3:
                printf("Result: %.2f\n",
                       advanced_operation('o'));
                break;

            case 4:
                printf("Result: %.2f\n",
                       advanced_operation('i'));
                break;

            case 5:
                printf("Result: %.2f\n",
                       advanced_operation('t'));
                break;

            case 6:
                printf("Result: %.2f\n",
                       advanced_operation('l'));
                break;

            case 9:
                return 0;

            case 0:
                printf("Thank you for using this calculator!\n");
                exit(0);

            default:
                printf("Invalid menu option.\n");
        }
    }
}

int main_menu(void) {
    int op;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Simple Calculator\n");
        printf("2. Advanced Calculator\n");
        printf("3. Credits\n");
        printf("0. Exit\n");
        printf("Select from Main Menu: ");

        if (scanf("%d", &op) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (op) {
            case 1:
                simple_calc();
                break;

            case 2:
                advanced_calc();
                break;

            case 3:
                printf("Developer: Asiff Junaid\n");
                printf("Project Version: 1.0.0\n");
                printf("Github: @connect...\n");
                printf("Email: asiff@julab.com\n");
                break;

            case 0:
                printf("Thank you for using this calculator!\n");
                return 0;

            default:
                printf("Invalid menu option.\n");
        }
    }
}

int main(void) {
    return main_menu();
}
