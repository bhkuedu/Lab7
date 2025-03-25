#include "temperature.h" // Include our functions via header file
#include <stdio.h> // Include I/O library, for use with scanf and printf

int main(int argc, char* argv[])
{

    float temperature; // Temperature variable. This is where we deposit user input and enact equations upon.
    char temperature_scale; // Temperature scale; the initial temperature format of our input: celsius, fahrenheit, etc. Represented as a character
    char conversion_target; // Conversion target; the target temperature format we're going to convert to

    // ### GET TEMPERATURE AND TARGET

    // We need to get the temperature and to keep asking for it until we're given something valid.
    while (1) { // Keep looping until we have a valid float
        printf("Enter the temperature value: "); // Ask the user for a temperature value

        int successful_read = scanf("%f", &temperature); // deposit input in 'temperature' variable.. return not being 1 means we weren't handed a float!

        // get rid of garbage input
        while (getchar() != '\n') // keeps reading characters until the newline.
            ;

        if (successful_read != 1) { // check if the read succeeded
            printf("Not a float. Please try again.\n"); // tell user we weren't given an float, and to try again.

            continue; // loop back again to give the user another chance
        } else {

            // We need to check through all temperature scales to make sure it's valid in at least one.
            // We do this by converting the temperature in each scale to kelvin, and making sure it's at or above absolute 0.
            int valid_celsius = (convert_temperature(temperature, 'c', 'k')) > 0; // Check celsius
            int valid_fahrenheit = (convert_temperature(temperature, 'f', 'k')) > 0; // Check fahrenheit
            int valid_kelvin = temperature >= 0; // Check kelvin

            if (!(valid_celsius || valid_fahrenheit || valid_kelvin)) { // Literally impossible to interpret temperature in a valid way.
                // Tell the user that.
                printf("Temperature below absolute zero in every scale. Please try again.\n\n");

                continue; // Loop back to give it another whirl.
            }

            break; // scanf deposited the float successfully! we have a temperature!
            // Therefore we end the loop.
        }
    }

    // We need to get the temperature scale and to keep asking for it until we're given something valid.
    while (1) { // Keep looping until we have a valid character
        printf("Choose the temperature scale of the input value ('f' for Fahrenheit, 'c' for Celsius, or 'k' for Kelvin): "); // Ask the user for a temperature scale.

        int successful_read = scanf("%c", &temperature_scale); // deposit character input in 'temperature_scale' variable.. return not being 1 means we weren't handed a char!
        while (getchar() != '\n') // keeps reading characters until the newline. clears input backlog.
            ;

        if (successful_read != 1) { // Check if the read worked correctly..
            printf("Not a character. Please try again.\n\n"); // tell user we weren't given an char, and to try again.

            continue; // loop back again to give the user another chance
        } else { // We got a character successfully!

            // Check to make sure that the character provided is a valid temperature scale!
            switch (temperature_scale) {
            case 'k': // Kelvin chosen
            case 'c': // Celsius chosen
            case 'f': // Fahrenheit chosen
                // We need to check to make sure the temperature value is valid in this scale.
                float kelvin = convert_temperature(temperature, temperature_scale, 'k'); // Convert to Kelvin.
                // Kelvin's origin is at absolute 0... we can use this to check if its absolute zero in the given arbitrary scale.
                if (kelvin < 0) { // Temperature cannot be below absolute zero!
                    // Tell our user this
                    printf("Cannot choose '%c', temperature in this scale is below absolute zero. Please try again. \n\n", temperature_scale);
                    continue; // Continue; give user another chance to enter something valid.
                }

                break; // Chose a valid temperature scale! Break the loop and move forward with the program.
            default:
                printf("Not a valid temperature ('f', 'c', or 'k'). Please try again. \n\n"); // tell user we weren't given a valid temperature, and to try again.
                continue; // Force program back to start of loop to give user another chance
            }

            break; //  Switch case passed successfully! temperature scale was chosen successfully!
        }
    }

    // We need to get the conversion target and to keep asking for it until we're given something valid.
    while (1) { // Keep looping until we have a valid char
        printf("Choose the conversion target ('f' for Fahrenheit, 'c' for Celsius, or 'k' for Kelvin): "); // Ask the user for a conversion target.

        int successful_read = scanf("%c", &conversion_target); // deposit character input in 'temperature_scale' variable.. return not being 1 means we weren't handed a char!
        while (getchar() != '\n') // keeps reading characters until the newline. clears input backlog.
            ;

        if (successful_read != 1) { // deposit character input in 'conversion_target' variable.. return not being 1 means we weren't handed a char!
            printf("Not a character. Please try again.\n\n"); // tell user we weren't given an char, and to try again.

            continue; // loop back again to give the user another chance
        } else { // We got a character successfully!

            // Check to make sure that the character provided is a valid conversion target!
            switch (conversion_target) {
            case 'k': // Kelvin chosen
            case 'c': // Celsius chosen
            case 'f': // Fahrenheit chosen
                if (conversion_target == temperature_scale) { // The user is asking to convert to the same scale!
                    printf("Converting to the same scale is not allowed. Please try again. \n\n"); // tell our user to try another choice.

                    continue; // Force program back `to start of loop to give user another chance
                }

                break; // Chose a valid conversion target! Break the switch and then move on to break the loop
            default:
                printf("Not a valid temperature ('f', 'c', or 'k'). Please try again. \n\n"); // tell user we weren't given a valid temperature, and to try again.
                continue; // Force program back `to start of loop to give user another chance
            }

            break; //  Switch case passed successfully! conversion target was chosen
        }
    }

    // ### CONVERT TEMPERATURE INTO TARGET

    // See function definition; converts temperature from existing scale to conversion target. returns result.
    float conversion_result = convert_temperature(temperature, temperature_scale, conversion_target);
    // float converted_temperature = 1.0F;

    printf("\nConverted temperature (%c): %f\n", conversion_target, conversion_result); // Print our converted temperature.

    // We convert to celsius here so that we can categorize the temperature and give advice.
    float celsius_baseline = convert_temperature(temperature, temperature_scale, 'c'); // Convert to celsius

    // Categorize temperature and issue a verdict!
    categorize_temperature(celsius_baseline); // Prints category and weather advisory based on celsius temperature

    return 0; // Exit program with code 0... executed sucessfully
}
