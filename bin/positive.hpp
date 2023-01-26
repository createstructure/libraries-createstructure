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
#include <string>
#include <vector>
#include <algorithm>

// using ...
using namespace std;

class Positive
{
private:
    // Vector with all the possible positive options
    static const inline vector<string> positive = {"Y", "y", "Yes", "yes", "YES", "1"};
    
    // Vector with all the possible negative options
    static const inline vector<string> negative = {"N", "n", "No", "no", "NO", "0"};
public:
    static bool isPositive(string str);
    static bool isNegative(string str);
};

#endif
