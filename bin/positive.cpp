/**
 * positive.cpp
 * 
 * Library for checking if a string is positive or negative.
 * 
 * @author Castellani Davide (@DavideC03)
 */

// Dependencies
#include "positive.hpp"

// Definitions
// #define DEBUG

bool Positive::isPositive(string str)
{
    /**
     * Check if the string is positive
     * 
     * @param str string to check
     * @return true if the string is positive, false otherwise
     */

    // Check if the string is in the vector
    return (find(Positive::positive.begin(), Positive::positive.end(), str) != Positive::positive.end());
}

bool Positive::isNegative(string str)
{
    /**
     * Check if the string is negative
     * 
     * @param str string to check
     * @return true if the string is negative, false otherwise
     */

    // Check if the string is in the vector
    return (find(Positive::negative.begin(), Positive::negative.end(), str) != Positive::negative.end());
}

#undef DEBUG
