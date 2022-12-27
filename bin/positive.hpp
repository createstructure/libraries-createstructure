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

// using ...
using namespace std;

class Positive
{
private:
public:
    static bool isPositive(string str);
    static bool isNegative(string str);
};

#endif
