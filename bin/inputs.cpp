/**
 * input.cpp
 *
 * Library to manage inputs gived by the user.
 *
 * @author Davide Castellani (@DavideC03)
 */

// Dependencies
#include "inputs.hpp"

// Definitions
// #define DEBUG

Inputs::Inputs()
{
	/**
	 * Empty constructor
	 */
}

Inputs::Inputs(int argc, char *argv[])
{
	/**
	 * Constructor
	 *
	 * @param argc: number of arguments
	 * @param argv: array of arguments
	 */
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

string Inputs::longVersion(string s)
{
	/**
	 * Long version: convert short version to long version if possible
	 *
	 * @param s: the string to convert
	 *
	 * @return if possible, the long version of the string, else the string itself
	 */
	if (Inputs::convertion.find(s) == Inputs::convertion.end())
	{
		return s;
	}
	else
	{
		return Inputs::convertion[s];
	}
}

bool Inputs::exist(string key)
{
	/**
	 * Inputs Exist: check if exist the asked key
	 *
	 * @param key: the key to check
	 *
	 * @return true if the key exist, false otherwise
	 */
	return m.find(key) != m.end();
}

string Inputs::getValue(string key)
{
	/**
	 * Get Value: get the value of the asked key
	 *
	 * @param key: the key to get the value
	 *
	 * @return the value of the key
	 */
	assert(exist(longVersion(key)));
	return m[longVersion(key)];
}

bool Inputs::exist(int argc, char *argv[], string key)
{
	/**
	 * Inputs Exist: check if exist the asked key
	 *
	 * @param argc: number of arguments
	 * @param argv: array of arguments
	 * @param key: the key to check
	 *
	 * @return true if the key exist, false otherwise
	 */
	Inputs inputs(argc, argv);
	return inputs.exist(key);
}

string Inputs::getValue(int argc, char *argv[], string key)
{
	/**
	 * Get Value: get the value of the asked key
	 *
	 * @param argc: number of arguments
	 * @param argv: array of arguments
	 * @param key: the key to get the value
	 *
	 * @return the value of the key
	 */
	Inputs inputs(argc, argv);
	return inputs.getValue(key);
}

#undef DEBUG
