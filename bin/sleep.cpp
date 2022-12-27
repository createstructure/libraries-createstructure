/**
 * sleep.cpp
 *
 * Library for sleep.
 *
 * @author Castellani Davide (@DavideC03)
 */

// Dependencies
#include "sleep.hpp"

// Definitions
// #define DEBUG

void Sleep::sleep(int seconds)
{
	/**
	 * Sleep for a given amount of time.
	 * 
	 * @param seconds The amount of time to sleep.
	 * 
	 */

	sleep_for(chrono::seconds(seconds));
}

void Sleep::sleep(int seconds, int nanoseconds)
{
	/**
	 * Sleep for a given amount of time.
	 * 
	 * @param seconds The amount of time to sleep.
	 * @param nanoseconds The amount of time to sleep.
	 * 
	 */

	sleep_for(chrono::seconds(seconds) + chrono::nanoseconds(nanoseconds));
}

#undef DEBUG
