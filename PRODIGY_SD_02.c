#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    printf("Welcome to the Guess the Number Game!\n");
    printf("I have selected a random number between 1 and 100. Try to guess it.\n");

    do {
        // Prompt the user to input their guess
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        // Increment the attempts count
        attempts++;

        // Check if the guess is correct, too high, or too low
        if (userGuess == secretNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        } else if (userGuess < secretNumber) {
            printf("Too low. Try again!\n");
        } else {
            printf("Too high. Try again!\n");
        }

    } while (userGuess != secretNumber);

    return 0;
}
