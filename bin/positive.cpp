/**
 * @file positive.cpp
 *
 * @brief Library for checking if a string is positive or negative.
 *
 * @author Castellani Davide (@DavideC03)
 */

// Dependencies
#include "positive.hpp"

// Definitions
// #define DEBUG

/**
 * @brief Check if the string is positive
 *
 * @param str String to check
 * @return bool True if the string is positive,False otherwise
 */
bool Positive::isPositive(string str)
{
    return (find(Positive::positive.begin(), Positive::positive.end(), str) != Positive::positive.end());
}

/**
 * @brief Check if the string is negative
 *
 * @param str String to check
 * @return bool True if the string is negative, False otherwise
 */
bool Positive::isNegative(string str)
{
    return (find(Positive::negative.begin(), Positive::negative.end(), str) != Positive::negative.end());
}

#undef DEBUG
