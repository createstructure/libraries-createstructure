/**
 * positive.hpp
 * 
 * Library for checking if a string is positive or negative.
 * 
 * @author Castellani Davide (@DavideC03)
 */

#ifndef POSITIVE
// If not imported yet
#define POSITIVE

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Positive
{
private:
public:
    static bool isPositive(string str);
    static bool isNegative(string str);
};

// Function(s)
bool Positive::isPositive(string str)
{
    /**
     * Check if the string is positive
     * 
     * @param str string to check
     * @return true if the string is positive, false otherwise
     */
    // Vector with all the possible positive options
    vector<string> positive = {"Y", "y", "Yes", "yes", "YES", "1"};

    // Check if the string is in the vector
    return find(positive.begin(), positive.end(), str) != positive.end();
}

bool Positive::isNegative(string str)
{
    /**
     * Check if the string is negative
     * 
     * @param str string to check
     * @return true if the string is negative, false otherwise
     */
    // Vector with all the possible negative options
    vector<string> negative = {"N", "n", "No", "no", "NO", "0"};

    // Check if the string is in the vector
    return find(negative.begin(), negative.end(), str) != negative.end();
}

#undef DEBUG
#endif
