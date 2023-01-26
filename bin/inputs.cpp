/**
 * @file inputs.cpp
 *
 * @brief Library to manage inputs gived by the user.
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "inputs.hpp"

// Definitions
// #define DEBUG

/**
 * @brief Empty constructor
 */
Inputs::Inputs()
{
}

/**
 * @brief Constructor
 *
 * @param argc Number of arguments
 * @param argv Array of arguments
 */
Inputs::Inputs(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		string tmp(argv[i]);
		if (tmp.rfind("-", 0) == 0)
		{
			if (i + 1 < argc && string(argv[i + 1]).rfind("-", 0) != 0)
			{
				string tmp2(argv[++i]);
				m[longVersion(tmp)] = tmp2;
			}
			else
			{
				m[longVersion(tmp)] = ""; // exist but no value
			}
		}
	}
}

/**
 * @brief Convert short version to long version if possible
 *
 * @param s The string to convert
 * @return string If possible, the long version of the string, else the string itself
 */
string Inputs::longVersion(string s)
{
	if (Inputs::convertion.find(s) == Inputs::convertion.end())
	{
		return s;
	}
	else
	{
		return Inputs::convertion[s];
	}
}

/**
 * @brief Check if exist the asked key
 *
 * @param key The key to check
 * @return bool True if the key exist, False otherwise
 */
bool Inputs::exist(string key)
{
	return m.find(key) != m.end();
}

/**
 * @brief Get the value of the asked key
 *
 * @param key The key to get the value
 * @return string The value of the key
 */
string Inputs::getValue(string key)
{
	assert(exist(longVersion(key)));
	return m[longVersion(key)];
}

/**
 * @brief Check if exist the asked key
 *
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @param key The key to check
 *
 * @return bool True if the key exist, False otherwise
 */
bool Inputs::exist(int argc, char *argv[], string key)
{
	Inputs inputs(argc, argv);
	return inputs.exist(key);
}

/**
 * @brief Get the value of the asked key
 *
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @param key The key to get the value
 *
 * @return string The value of the key
 */
string Inputs::getValue(int argc, char *argv[], string key)
{
	Inputs inputs(argc, argv);
	return inputs.getValue(key);
}

#undef DEBUG
