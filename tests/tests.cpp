#include <gtest/gtest.h>

extern "C" {
#include "football.h"
#include "temperature.h"
}

TEST(Football, CorrectOutput)
{
    EXPECT_EQ(count_combinations(5), 1);
    EXPECT_EQ(count_combinations(16), 14);
    EXPECT_EQ(count_combinations(62), 652);
}

TEST(Temperature, CorrectOutput)
{
    EXPECT_NEAR(celsius_to_fahrenheit(20.f), 68.f, 0.1f);
    EXPECT_NEAR(fahrenheit_to_celsius(68.f), 20.f, 0.1f);
    EXPECT_NEAR(celsius_to_kelvin(20.f), 293.15f, 0.1f);
    EXPECT_NEAR(kelvin_to_celsius(293.15f), 20.f, 0.1f);
}
