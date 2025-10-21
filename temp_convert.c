// temp_convert.c
#include <stdio.h>
#include <ctype.h>

double to_celsius(double value, char scale) {
    if (scale == 'C') return value;
    else if (scale == 'F') return (value - 32) * 5 / 9;
    else if (scale == 'K') return value - 273.15;
    else return value;
}

double from_celsius(double c, char scale) {
    if (scale == 'C') return c;
    else if (scale == 'F') return c * 9 / 5 + 32;
    else if (scale == 'K') return c + 273.15;
    else return c;
}

void print_category(double c) {
    if (c < 0) {
        printf("Category: Freezing\nAdvisory: Wear a heavy coat!\n");
    } else if (c < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket.\n");
    } else if (c < 25) {
        printf("Category: Comfortable\nAdvisory: Enjoy the weather!\n");
    } else if (c < 35) {
        printf("Category: Hot\nAdvisory: Drink lots of water!\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Stay indoors and stay hydrated!\n");
    }
}

int main() {
    double value;
    char orig, dest;
    printf("Enter the temperature value: ");
    scanf("%lf", &value);

    printf("Enter the original scale (C, F, K): ");
    scanf(" %c", &orig);
    orig = toupper(orig);

    printf("Enter the scale to convert to (C, F, K): ");
    scanf(" %c", &dest);
    dest = toupper(dest);

    if ((orig != 'C' && orig != 'F' && orig != 'K') ||
        (dest != 'C' && dest != 'F' && dest != 'K')) {
        printf("Invalid scale input.\n");
        return 1;
    }

    double c = to_celsius(value, orig);
    double result = from_celsius(c, dest);

    printf("Converted temperature: %.2f %c\n", result, dest);
    print_category(c);

    return 0;
}
