/**
 * @file sleep.cpp
 *
 * @brief Library for sleep.
 *
 * @author Castellani Davide (@DavideC03)
 */

// Dependencies
#include "sleep.hpp"

// Definitions
// #define DEBUG

/**
 * @brief Sleep for a given amount of time
 *
 * @param seconds The amount of seconds to sleep
 */
void Sleep::sleep(int seconds)
{
	sleep_for(chrono::seconds(seconds));
}

/**
 * @brief Sleep for a given amount of time.
 *
 * @param seconds The amount of seconds to sleep
 * @param nanoseconds The amount of milliseconds to sleep, over the seconds
 */
void Sleep::sleep(int seconds, int nanoseconds)
{
	sleep_for(chrono::seconds(seconds) + chrono::nanoseconds(nanoseconds));
}

#undef DEBUG
