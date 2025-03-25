#include "football.h"
#include <stdio.h>

// POINTS - Preprocesser to define what each point opportunity is worth.
// Also explains where each opportunity is encountered in the general program logic.
#define TOUCHDOWN_CONVERSION_POINTS 8 // First loop
#define TOUCHDOWN_FIELD_GOAL_POINTS 7 // Second loop
#define TOUCHDOWN_POINTS 6 // Third loop
#define FIELD_GOAL_POINTS 3 // Fourth loop
#define SAFETY_POINTS 2 // Floor-div calculation within fourth loop.

// ## Count combinations of score opportunities to reach the provided score value
int count_combinations(int points)
{

    // ### HIGH-LEVEL OVERVIEW
    // ##  This code leverages 4 nested loops, ordering from largest point opportunities to smallest.
    // ## Every subsequent loop only iterates up until there is no more room to stuff additional points into the total... this is calculated within each loop and provided to the next (see: 'leftover points' variables)
    // ## Within the fourth loop we do the final point stuffing calculation via a straightforward floor division with the Safetys.
    // ## -> Resultingly, we're left with one last variable containing the leftover points; the points we weren't able to fill.
    // ## ---> If this number isn't 0, we move on. We only allow valid point combinations!
    //
    // ##### FUNCTION-SPECIFIC BEHAVIOR
    //
    // ## For this function, specifically, we increment the 'combinations' variable if we've found a valid combination
    // ## We return the total number of combinations found at the end of the function.

    int combinations = 0; // Combinations variable. Increments when we find a valid combination.

    for (
        int touchdown_conversions = 0; // Touchdown conversions counter
        touchdown_conversions * TOUCHDOWN_CONVERSION_POINTS <= points; // Make sure we don't overshoot points
        touchdown_conversions++ // Increment
    ) { // ## Touchdown + 2-point conversions. Worth 8 points each.

        // Leftover points from this iteration. We use this for the next point opportunity
        int leftover_points_A = points - (touchdown_conversions * TOUCHDOWN_CONVERSION_POINTS);

        for (
            int touchdown_field_goals = 0; // Touchdown field goals counter
            touchdown_field_goals * TOUCHDOWN_FIELD_GOAL_POINTS <= leftover_points_A; // Make sure we don't overshoot points
            touchdown_field_goals++ // Increment
        ) { // ## Touchdown + 1-point field goals. Worth 7 points each.

            // Leftover points from this iteration. We use this for the next point opportunity
            int leftover_points_B = leftover_points_A - (touchdown_field_goals * TOUCHDOWN_FIELD_GOAL_POINTS);

            for (
                int touchdowns = 0; // Touchdowns counter
                touchdowns * TOUCHDOWN_POINTS <= leftover_points_B; // Make sure we don't overshoot points
                touchdowns++ // Increment
            ) { // ## Touchdowns. Worth 6 points each.

                // Leftover points from this iteration. We use this for the next point opportunity
                int leftover_points_C = leftover_points_B - (touchdowns * TOUCHDOWN_POINTS);

                for (
                    int field_goals = 0; // Field goals counter
                    field_goals * FIELD_GOAL_POINTS <= leftover_points_C; // Make sure we don't overshoot points
                    field_goals++ // Increment
                ) { // ## Field goals. Worth 3 points each

                    // Leftover points from this iteration. We use this for the next point opportunity
                    int leftover_points_D = leftover_points_C - (field_goals * FIELD_GOAL_POINTS);

                    // ##  LAST POINT OPPORTUNITY.
                    //  Safetys. Worth 2 points each.
                    //  Instead of looping we simply do basic floor division to find out how many of these safetys we can stuff in the remaining points.
                    int safetys = leftover_points_D / SAFETY_POINTS;

                    // The final amount of leftover points
                    int leftover_points_final = leftover_points_D - (safetys * SAFETY_POINTS);

                    // We only care about this all if it actually matches the required number of points.
                    // Undershooting is a no-go. Therefore we check to make sure there's no leftover points.
                    if (leftover_points_final == 0) { // No leftover points after everything subtracted
                        // Found a valid combination! Increment combinations variable!
                        combinations++;
                    }
                }
            }
        }
    }

    // Return total combinations to caller.
    return combinations;
}

// ## Print combinations of score opportunities to reach the provided score value
void print_combinations(int points)
{

    // ### HIGH-LEVEL OVERVIEW
    // ##  This code leverages 4 nested loops, ordering from largest point opportunities to smallest.
    // ## Every subsequent loop only iterates up until there is no more room to stuff additional points into the total... this is calculated within each loop and provided to the next (see: 'leftover points' variables)
    // ## Within the fourth loop we do the final point stuffing calculation via a straightforward floor division with the Safetys.
    // ## -> Resultingly, we're left with one last variable containing the leftover points; the points we weren't able to fill.
    // ## ---> If this number isn't 0, we move on. We only allow valid point combinations!
    //
    // ##### FUNCTION-SPECIFIC BEHAVIOR
    //
    // ## For this function, specifically, we print the valid combinations when we find them

    for (
        int touchdown_conversions = 0; // Touchdown conversions counter
        touchdown_conversions * TOUCHDOWN_CONVERSION_POINTS <= points; // Make sure we don't overshoot points
        touchdown_conversions++ // Increment
    ) { // ## Touchdown + 2-point conversions. Worth 8 points each.

        // Leftover points from this iteration. We use this for the next point opportunity
        int leftover_points_A = points - (touchdown_conversions * TOUCHDOWN_CONVERSION_POINTS);

        for (
            int touchdown_field_goals = 0; // Touchdown field goals counter
            touchdown_field_goals * TOUCHDOWN_FIELD_GOAL_POINTS <= leftover_points_A; // Make sure we don't overshoot points
            touchdown_field_goals++ // Increment
        ) { // ## Touchdown + 1-point field goals. Worth 7 points each.

            // Leftover points from this iteration. We use this for the next point opportunity
            int leftover_points_B = leftover_points_A - (touchdown_field_goals * TOUCHDOWN_FIELD_GOAL_POINTS);

            for (
                int touchdowns = 0; // Touchdowns counter
                touchdowns * TOUCHDOWN_POINTS <= leftover_points_B; // Make sure we don't overshoot points
                touchdowns++ // Increment
            ) { // ## Touchdowns. Worth 6 points each.

                // Leftover points from this iteration. We use this for the next point opportunity
                int leftover_points_C = leftover_points_B - (touchdowns * TOUCHDOWN_POINTS);

                for (
                    int field_goals = 0; // Field goals counter
                    field_goals * FIELD_GOAL_POINTS <= leftover_points_C; // Make sure we don't overshoot points
                    field_goals++ // Increment
                ) { // ## Field goals. Worth 3 points each

                    // Leftover points from this iteration. We use this for the next point opportunity
                    int leftover_points_D = leftover_points_C - (field_goals * FIELD_GOAL_POINTS);

                    // ##  LAST POINT OPPORTUNITY.
                    //  Safetys. Worth 2 points each.
                    //  Instead of looping we simply do basic floor division to find out how many of these safetys we can stuff in the remaining points.
                    int safetys = leftover_points_D / SAFETY_POINTS;

                    // The final amount of leftover points.
                    int leftover_points_final = leftover_points_D - (safetys * SAFETY_POINTS);

                    // We only care about this all if it actually matches the required number of points.
                    // Undershooting is a no-go. Therefore we check to make sure there's no leftover points.
                    if (leftover_points_final == 0) { // No leftover points after everything subtracted
                        // Found a valid combination! Now we print it!
                        printf(
                            "%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", // formatting string
                            touchdown_conversions, // Touchdown + 2-point conversions
                            touchdown_field_goals, // Touchdown + 1-point field goals
                            touchdowns, // Touchdowns
                            field_goals, // Field goals
                            safetys // Safetys
                        );
                    }
                }
            }
        }
    }
}
