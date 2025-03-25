#include "temperature.h"
#include <stdio.h>

// Convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32; // Celsius is both at a different root temperature and with a different scaling. Basic arithmetic suffices
}

// Convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9; // Fahrenheit is both at a different root temperature and with a different scaling. Basic arithmetic suffices
}

// Convert celsius to kelvin
float celsius_to_kelvin(float celsius)
{
    return celsius + 273.15f; // Kelvin and Celsius scaling is the same.. Kelvin is just rooted at absolute zero. Accounting for this gives us Kelvin.
}

// Convert kelvin to celsius
float kelvin_to_celsius(float kelvin)
{
    return kelvin - 273.15f; // Kelvin and Celsius scaling is the same... Kelvin is just rooted at absolute zero. Reversing this gets us Celsius.
}

// Takes a temperature float as an input and converts it from the original temperature scale to the conversion target
float convert_temperature(float input_temperature, char temperature_scale, char conversion_target)
{
    float converted_temperature; // Conversion result variable

    // Each branch represents a different possible conversion.
    if (conversion_target == 'k' && temperature_scale == 'c') { // Celsius to Kelvin
        converted_temperature = celsius_to_kelvin(input_temperature);
    } else if (conversion_target == 'k' && temperature_scale == 'f') { // Fahrenheit to Kelvin
        converted_temperature = celsius_to_kelvin(fahrenheit_to_celsius(input_temperature));
    } else if (conversion_target == 'c' && temperature_scale == 'f') { // Fahrenheit to Celsius
        converted_temperature = fahrenheit_to_celsius(input_temperature);
    } else if (conversion_target == 'c' && temperature_scale == 'k') { // Kelvin to Celsius
        converted_temperature = kelvin_to_celsius(input_temperature);
    } else if (conversion_target == 'f' && temperature_scale == 'c') { // Celsius to Fahrenheit
        converted_temperature = celsius_to_fahrenheit(input_temperature);
    } else if (conversion_target == 'f' && temperature_scale == 'k') { // Kelvin to Fahrenheit
        converted_temperature = celsius_to_fahrenheit(kelvin_to_celsius(input_temperature));
    } else if (conversion_target == temperature_scale) { // We're converting to the same type!
        converted_temperature = input_temperature;
    } else { // This should never, ever, happen. It means that this conversion wasn't represented in the if branches!
        printf("Error: Invalid state! No branch option for converting '%c' to '%c'!", temperature_scale, conversion_target); // Tell our user this. Should never reach this place.
    }

    return converted_temperature; // Return the result of the conversion
}

// Categorize celsius temperatures into hardcoded ranges, print said categorization, and issue a recommendation.
void categorize_temperature(float celsius)
{
    printf("Verdict:\n\n"); // Tell the user we're giving them our verdict on the weather

    // Branch based on what range the celsius temperature fits into.
    // Then we print the category, and the weather advisory message.
    if (celsius < 0) {
        // Freezing: Below 0°C (or equivalent in other scales)
        printf("Freezing!\nYou should gather 'round a bonfire!");
    } else if (celsius >= 0 && celsius < 10) {
        // Cold: 0°C to 10°C (or equivalent)
        printf("Cold!\nYou should put on a jacket!");
    } else if (celsius >= 10 && celsius < 25) {
        // Comfortable: 10°C to 25°C (or equivalent)
        printf("Comfortable!\nYou'll be fine.");
    } else if (celsius >= 25 && celsius <= 35) {
        // Hot: 25°C to 35°C (or equivalent)
        printf("Hot!\nMake sure to get plenty of water!");
    } else if (celsius > 35) {
        // Extreme Heat: Above 35°C (or equivalent)
        printf("Extreme Heat!\nDo the ice bucket challenge!");
    }
}
