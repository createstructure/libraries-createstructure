/**
 * input.hpp
 *
 * Library to manage inputs gived by the user.
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef INPUTS
// If not imported yet
#define INPUTS

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Inputs
{
private:
	map<string, string> convertion = {
		{"-h", "--help"},
		{"-v", "--version"},
		{"-l", "--login"},
		{"-u", "--username"},
		{"-p", "--password"},
		{"-t", "--token"},
		{"-sn", "--server-name"},
		{"-sp", "--server-password"},
		{"-r", "--repo-info"}};
	map<string, string> m;

	string longVersion(string s);

public:
	Inputs();
	Inputs(int argc, char *argv[]);

	bool exist(string key);
	string getValue(string key);

	static bool exist(int argc, char *argv[], string key);
	static string getValue(int argc, char *argv[], string key);
};

// Function(s)
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
	for (size_t i = 1; i < argc; ++i)
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
#endif
