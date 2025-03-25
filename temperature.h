#ifndef __REPORT_H__
#define __REPORT_H__

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 *
 * @param celsius
 * @return float
 */
float celsius_to_fahrenheit(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 *
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 *
 * @param celsius
 * @return float
 */
float celsius_to_kelvin(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 *
 * @param kelvin
 * @return float
 */
float kelvin_to_celsius(float kelvin);

// ### OUR FUNCTION DEFINITIONS

/**
 * @brief Converts a temperature from one temperature scale to another
 *
 * @param input_temperature
 * @param temperature_scale
 * @param conversion_target
 * @return float
 */
float convert_temperature(float input_temperature, char temperature_scale, char conversion_target);

/**
 * @brief Print categorization of temperature and related recommendations
 *
 * @param celsius
 * @return void
 */
void categorize_temperature(float celsius);

#endif /* __REPORT_H__ */
