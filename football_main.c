#include "football.h" // Include our football functions via header file
#include <stdio.h> // Include I/O library, for use with scanf and printf

// Main program logic.
int main(int argc, char* argv[])
{
    int score; // Score variable. This is where we deposit user input.

    printf("Enter 0 or 1 to STOP\n"); // Explain to user that they can enter 1 or 0 to stop.

    while (1) { // Infinite while loop. Keeps going until it is forcibly broken.
        printf("Enter the NFL score: "); // Tell our user to enter an NFL score

        if (scanf("%d", &score) != 1) { // deposit input in 'score' variable.. return not being 1 means we weren't handed an integer.
            printf("Not an integer. Please try again.\n"); // tell user we weren't given an integer, and to try again.

            // get rid of garbage input
            while (getchar() != '\n') // keeps reading characters until the newline.
                ;
            continue; // loop back again to give the user another chance
        }

        if (score == 1 || score == 0) { // Score is 0 or 1. Stop the program!
            printf("Program stopped.\n"); // Telling the user the program stopped.
            break; // Break loop.
        } else if (score < 0) { // score provided is negative! impossible!.
            printf("Score is negative. Please try again.\n"); // Tell user that we were given negative input and to try again.

            continue; // loop back again to give the user another chance
        }

        printf("\nPossible combinations of scoring plays if a team's score is %d: \n\n", score);
        print_combinations(score); // Print combinations to user.
        printf("\n");

        // printf("Amount of combinations: %d \n\n", count_combinations(score));
    }

    return 0;
}
