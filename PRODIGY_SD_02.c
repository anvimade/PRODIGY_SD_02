#include <stdio.h>

void convertCelsiusToFahrenheit();
void convertFahrenheitToCelsius();
void convertCelsiusToKelvin();
void convertKelvinToCelsius();
void convertFahrenheitToKelvin();
void convertKelvinToFahrenheit();

int main() {
    int choice;

    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            convertCelsiusToFahrenheit();
            break;
        case 2:
            convertFahrenheitToCelsius();
            break;
        case 3:
            convertCelsiusToKelvin();
            break;
        case 4:
            convertKelvinToCelsius();
            break;
        case 5:
            convertFahrenheitToKelvin();
            break;
        case 6:
            convertKelvinToFahrenheit();
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}

void convertCelsiusToFahrenheit() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("Temperature in Fahrenheit: %lf\n", fahrenheit);
}

void convertFahrenheitToCelsius() {
    double fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("Temperature in Celsius: %lf\n", celsius);
}

void convertCelsiusToKelvin() {
    double celsius, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    kelvin = celsius + 273.15;

    printf("Temperature in Kelvin: %lf\n", kelvin);
}

void convertKelvinToCelsius() {
    double kelvin, celsius;

    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);

    celsius = kelvin - 273.15;

    printf("Temperature in Celsius: %lf\n", celsius);
}

void convertFahrenheitToKelvin() {
    double fahrenheit, kelvin;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    kelvin = (fahrenheit + 459.67) * 5 / 9;

    printf("Temperature in Kelvin: %lf\n", kelvin);
}

void convertKelvinToFahrenheit() {
    double kelvin, fahrenheit;

    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);

    fahrenheit = (kelvin * 9 / 5) - 459.67;

    printf("Temperature in Fahrenheit: %lf\n", fahrenheit);
}
