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
#include <chrono>
#include <thread>
#include <unistd.h>

// using ...
using namespace std;
using namespace std::this_thread;

class Sleep
{
private:
public:
	static void sleep(int seconds);
	static void sleep(int seconds, int nanoseconds);
};

#endif
