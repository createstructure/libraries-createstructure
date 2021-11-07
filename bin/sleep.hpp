/**
 * sleep.hpp
 *
 * Library for sleep.
 *
 * @author Castellani Davide (@DavideC03)
 */

#ifndef SLEEP
// If not imported yet
#define SLEEP

// Dependencies
#include <bits/stdc++.h>
#include <unistd.h>

// using ...
using namespace std;
using namespace std::this_thread;

// Definitions
// #define DEBUG

// Class prototype
class Sleep
{
private:
public:
	static void sleep(int seconds);
	static void sleep(int seconds, int nanoseconds);
};

// Function(s)
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
#endif